#include "fileindexer.h"
#include "trigramsrepository.h"
#include <QTextStream>
#include <QDialog>
#include <algorithm>

TrigramsRepository::TrigramsRepository(){
    //no actions
}

bool TrigramsRepository::canAddDir(QString path){
    if(path.isEmpty()){
        qDebug()<<"PATH EMPTY!";
        return 0;
     }
     for (auto& keyDir : trigramsData.keys()){
         if (keyDir.contains(path) || path.contains(keyDir)){
             return false;
         }
     }
     return true;
}

void TrigramsRepository::deleteDir(QString dir){
     trigramsData.remove(dir);
     qDebug()<<"remove : "<< dir<<"Map size: "<<trigramsData.size();
}

void TrigramsRepository::insertFile(QString filePath, QSet<QString> tdata){
    QString directory = findDirByPath(filePath);
    trigramsData[directory].insert(filePath, tdata);
}
void TrigramsRepository::insert(QString dir, QMap<QString,QSet<QString>> tdata){
   trigramsData.insert(dir, tdata);
}

QVector<QPair<QString,QList<QString>>> TrigramsRepository::find(QString pattern){
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
                /* QFile file(filePath);
                 QTextStream stream(&file);

                 std::string std_pattern = pattern.toStdString();
                 std::string std_text = stream.readAll().toStdString();
                 auto it = std::search(std_text.begin(), std_text.end(),
                                    std::boyer_moore_searcher(
                                       std_pattern.begin(), std_pattern.end()));
                 if (it == std_text.end()){
                     continue;
                 }*/
                 filesList.append(filePath);
                 qDebug()<<"Found:"<<filePath;
             }
          }
        result.push_back(qMakePair(curDir.key(),filesList));
     }
     return result;
 }

QString TrigramsRepository::findDirByPath(QString path){
    for (auto curDir = trigramsData.begin(); curDir != trigramsData.end(); curDir++){
        if(path.contains(curDir.key())){
            return curDir.key();
        }
    }
    qDebug()<<"LOGICAL ERROR NOT FOUND DIR BY PATH";
    return "";
}
