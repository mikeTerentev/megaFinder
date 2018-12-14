#include "fileindexer.h"
#include "trigramssearcher.h"




void TrigramsSearcher::indexDir(){
     qDebug()<<"add : "<< dir <<"Map size inc";
     FileIndexer indexer;
    QDirIterator it(dir, QDir::Hidden | QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
       while (it.hasNext()) {
           if (QThread::currentThread()->isInterruptionRequested()){
              emit finished(QDialog::Accepted);
              return;
           }
           QFileInfo  file =(it.next());
           emit fileIndexing(file.absoluteFilePath());
           QString fileDir(file.absoluteFilePath());
           qDebug()<<fileDir;
           if (file.isSymLink()) {
               continue;
           }
           dirData.insert(fileDir, indexer.findTrigramsOfFile(fileDir));
       }
       isCompleted = true;
       emit finished(QDialog::Accepted);
}
