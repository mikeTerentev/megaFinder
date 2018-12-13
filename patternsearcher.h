#ifndef PATTERNSEARCHER_H
#define PATTERNSEARCHER_H

#include <qset.h>
#include "QString"
#include "QMap"
#include <qdiriterator.h>
#include <QDebug>
#include <QList>
#include <QPair>
class PatternSearcher
{
public:

    PatternSearcher();

    QSet<QString> getDirectories(){
        return directories;
    }
    QMap<QString,QMap<QString,QSet<QString>>> getTrigramData(){
        return trigramsData;
    }
    bool addFileDir(QString dir);
    void deleteDir(QString dir);
    void indexDir(QString dir);
    QVector<QPair<QString, QList<QString> > > find(QString pattern);
private:
    QSet<QString> directories;
    QMap<QString,QMap<QString,QSet<QString>>> trigramsData;
    //<dir,<file, trigrams>>
};

#endif // PATTERNSEARCHER_H
