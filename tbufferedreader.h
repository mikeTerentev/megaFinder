#ifndef TBUFFEREDREADER_H
#define TBUFFEREDREADER_H

#include <QFile>
#include <qstring.h>
#include <qtextstream.h>



class TBufferedReader
{
public:
    TBufferedReader(QString filePath);
    ~TBufferedReader();
    uint64_t nextTrigram();
    bool hasNextTrigram();
    bool isTextFile();
private:
    QByteArray::iterator it;
    int size;
    QFile* file;
    uint64_t hash;
    QByteArray byteLine;
    int pointer;
};

#endif // TBUFFEREDREADER_H
