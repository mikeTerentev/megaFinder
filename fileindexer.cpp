#include "fileindexer.h"
#include "tbufferedreader.h"
#include <QDebug>
FileIndexer::FileIndexer(QString pattern):pattern(pattern){}

void FileIndexer::indexDir(const QString& dir){

}

QSet<QString> FileIndexer::findTrigramsOfFile(const QString& file)
{
    QSet<QString> data;
    TBufferedReader reader(file);
    if(!reader.isTextFile()){
        qDebug()<<"FILE IS BINARY"<<file;
        return data;
    }
    while(reader.hasNextTrigram()){
        QString curTrigram = reader.nextTrigram();
        data.insert(curTrigram);
     }
     return  data;
 }

QSet<QString> FileIndexer::findTrigramsOfString(const QString& line){
    int pointer = 0;
    QSet<QString> result;
    if(line.size()<3){
        result.insert(line);
    }
    while (pointer + 2 < line.size()){
        result.insert(line.mid(pointer,3));
        pointer++;
    }
    return result;
}

