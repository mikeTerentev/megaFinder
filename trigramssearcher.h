#ifndef TRIGRAMSSEARCHER_H
#define TRIGRAMSSEARCHER_H

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
   const QMap<QString,QSet<QString>> getData(){
        return  dirData;
    }

   bool isSearchCompleted(){
       return isCompleted;
   }

public slots:
    void indexDir();


signals:
     void fileIndexing(QString);
     void finished(int);

private:
    QMap<QString,QSet<QString>> dirData;
    QString dir;
    bool isCompleted = false;
};

#endif // TRIGRAMSSEARCHER_H
