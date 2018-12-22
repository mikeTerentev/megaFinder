#include "trigramssearcher.h"


void TrigramsSearcher::find(){
    qDebug()<< "started";
    emit filesCounted(trigramsRepository->getFilesAmount());
    auto foundData = trigramsRepository->find(pattern);
    if (QThread::currentThread()->isInterruptionRequested()){
        emit finished(foundData,false);
        return;
    }
    qDebug()<<"finished";
    emit finished(foundData,true);
}

void TrigramsSearcher::indexDir(){
    if (!trigramsRepository->canAddDir(dir)){
        emit foundDuplicate(dir);
        emit finished(QDialog::Accepted);
        return;
    }
     qDebug()<<"add : "<< dir <<"Map size inc";
    QDirIterator it(dir, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
       while (it.hasNext()) {
           if (QThread::currentThread()->isInterruptionRequested()){
              emit finished(QDialog::Accepted);
              return;
           }
           QFileInfo  file =(it.next());
           emit fileIndexing(file.absoluteFilePath());
           QString filePath(file.absoluteFilePath());
           //qDebug()<<filePath;
           if (file.isSymLink()) {
               continue;
           }
           QSet<uint64_t> fileData = indexer.findTrigramsOfFile(filePath);
           if (!fileData.isEmpty()){
              dirData.insert(filePath, fileData);
              filePaths.append(filePath);
           }
       }
       trigramsRepository->insert(dir,dirData);
       watcher->addPaths(filePaths);
       watcher->addPath(dir);
       qDebug()<<"Watching directories : "<<watcher->directories().size()<<"files : "<<watcher->files().size();
       emit addPreprocessedDir(dir);
       emit finished(QDialog::Accepted);
}

QSet<uint64_t> TrigramsSearcher::getFileTrigrams(){
    return indexer.findTrigramsOfFile(dir);
}
