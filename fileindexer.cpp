#include "fileindexer.h"
#include "tbufferedreader.h"

FileIndexer::FileIndexer(QString pattern):pattern(pattern)
{
}

void FileIndexer::indexDir(const QString& dir){

}

QSet<QString> FileIndexer::findTrigrams(QString file)
{
    QSet<QString> data;
    TBufferedReader reader(file);
    while(reader.hasNextTrigram()){
        QString curTrigram = reader.nextTrigram();
        data.insert(curTrigram);
     }
     return  data;
 }
