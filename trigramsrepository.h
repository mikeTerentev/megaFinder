#ifndef PATTERNSEARCHER_H
#define PATTERNSEARCHER_H

#include <qset.h>
#include "QString"
#include "QMap"
#include <qdiriterator.h>
#include <QDebug>
#include <QList>
#include <QPair>
#include <QThread>
class TrigramsRepository
{

public:

    TrigramsRepository();

    const QMap<QString,QMap<QString,QSet<QString>>>& getTrigramData(){
        return trigramsData;
    }
    bool canAddDir(QString path);
    void deleteDir(QString dir);
    QVector<QPair<QString, QList<QString> > > find(QString pattern);
    void insertFile(QString filePath, QSet<QString> tdata);
public slots:
    QString findDirByPath(QString path);
    void insert(QString dir, QMap<QString, QSet<QString> > tdata);
private:
    QMap<QString,QMap<QString,QSet<QString>>> trigramsData;
    //<dir,<file, trigrams>>

};

#endif // PATTERNSEARCHER_H
