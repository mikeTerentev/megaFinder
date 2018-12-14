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
    QString nextTrigram();
    bool hasNextTrigram();
    bool isTextFile();
private:
    QFile* file;
    QTextStream* stream;
    QString line;
    int pointer;
};

#endif // TBUFFEREDREADER_H
