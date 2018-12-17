#ifndef TRIGRAMSSEARCHER_H
#define TRIGRAMSSEARCHER_H

#include "fileindexer.h"

#include <qstring.h>
#include <QMap>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QDialog>
#include <QDirIterator>
#include <QThread>

class TrigramsSearcher:public   QObject
{
    Q_OBJECT
public:
    TrigramsSearcher(QString dir) : dir(dir){}

   const QString getDir(){
        return dir;
    }
   QMap<QString,QSet<uint64_t>>& getData(){
        return  dirData;
    }

   bool isSearchCompleted(){
       return isCompleted;
   }
   QList<QString> getDirectories(){
       return directories;
   }
public slots:
    void indexDir();
    QSet<uint64_t> getFileTrigrams();

signals:
     void fileIndexing(QString);
     void finished(int);

private:
    FileIndexer indexer;
    QMap<QString,QSet<uint64_t>> dirData;
    QList<QString> directories;
    QString dir;
    bool isCompleted = false;
};

#endif // TRIGRAMSSEARCHER_H
