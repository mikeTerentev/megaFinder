#include "fileindexer.h"
#include "patternsearcher.h"



PatternSearcher::PatternSearcher()
{

}

bool PatternSearcher::addFileDir(QString path){
     if (directories.contains(path)){
       return false;
     }
       directories.insert(path);
       return true;
   }

 void PatternSearcher::deleteDir(QString dir){
     directories.remove(dir);
     trigramsData.remove(dir);
 }

 void PatternSearcher::indexDir(QString path){
     QDirIterator it(path,QDir::Hidden | QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QFileInfo  file =(it.next());
            FileIndexer indexer;
            QString fileDir(file.absoluteFilePath());
            qDebug()<<fileDir;
            if (file.isSymLink()) continue;
            trigramsData.insert(fileDir, indexer.findTrigrams(fileDir));
        }
 }

 QList<QString> PatternSearcher::find(QString& pattern){
     QList<QString> result;
     for(auto cur = trigramsData.begin(); cur != trigramsData.end(); cur++){
         QString filePath = cur.key();
         if(cur.value().contains(pattern)){
             result.append(filePath);
             qDebug()<<"Found:"<<filePath;
         }
     }
     return result;
 }
