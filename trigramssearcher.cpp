#include "trigramssearcher.h"




void TrigramsSearcher::indexDir(){
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
           qDebug()<<filePath;
           if (file.isSymLink()) {
               continue;
           }
           auto fileData = indexer.findTrigramsOfFile(filePath);
           if (!fileData.isEmpty()){
              dirData.insert(filePath, fileData);
              directories.append(filePath);
           }
       }
       isCompleted = true;
       emit finished(QDialog::Accepted);
}

QSet<QString> TrigramsSearcher::updateFile(){
    return indexer.findTrigramsOfFile(dir);
}
