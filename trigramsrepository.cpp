#include "fileindexer.h"
#include "patternsearcher.h"

PatternSearcher::PatternSearcher(){
    //no actions
}

bool PatternSearcher::addFileDir(QString path){
     for (auto& dir : directories){
         if (dir.contains(path)){
             return false;
         }
     }
     directories.insert(path);
      qDebug()<<"add : "<< path<<"Map size: "<<directories.size();
     return true;
}

void PatternSearcher::deleteDir(QString dir){
     directories.remove(dir);
     qDebug()<<"remove : "<< dir<<"Map size: "<<directories.size();
     trigramsData.remove(dir);
}

 void PatternSearcher::indexDir(QString dir){
     QMap<QString,QSet<QString>> dirData;
     QDirIterator it(dir, QDir::Hidden | QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QFileInfo  file =(it.next());
            FileIndexer indexer;
            QString fileDir(file.absoluteFilePath());
            qDebug()<<fileDir;
            if (file.isSymLink()) {
                continue;
            }
            dirData.insert(fileDir, indexer.findTrigramsOfFile(fileDir));
        }
        trigramsData.insert(dir,dirData);
 }

 QVector<QPair<QString,QList<QString>>> PatternSearcher::find(QString pattern){
     QVector<QPair<QString,QList<QString>>> result;
     FileIndexer indexer;
     QSet<QString> patternTrigrams =indexer.findTrigramsOfString(pattern);
     for (auto curDir = trigramsData.begin(); curDir != trigramsData.end(); curDir++){
         QList<QString> filesList;
         for (auto curFile = curDir.value().begin(); curFile != curDir.value().end(); curFile++){
             bool isMatch = true;
             QString filePath = curFile.key();
             if( pattern.size() >= 3){
                 for (auto& patternTrigram : patternTrigrams){
                     if (!curFile.value().contains(patternTrigram)){
                         isMatch = false;
                     }
                 }
             }
             else {
                  isMatch = false;
                  for (auto& fileTrigram : curFile.value()){
                      if (fileTrigram.contains(pattern)){
                         isMatch = true;
                         continue;
                      }
                  }
             }
             if (isMatch){
                 filesList.append(filePath);
                 qDebug()<<"Found:"<<filePath;
             }
          }
        result.push_back(qMakePair(curDir.key(),filesList));
     }
     return result;
 }
