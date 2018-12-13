#include "tbufferedreader.h"


    TBufferedReader::TBufferedReader(QString filePath){
        file = new QFile(filePath);
        if (file->open(QFile::ReadOnly)){
            stream = new QTextStream(file);
        }
    }


    QString TBufferedReader::nextTrigram(){
        if (pointer + 2 >= line.size()){
           line = stream->readAll();
           pointer = 0;
        }
        QString res = line.mid(pointer, 3);
        pointer++;
        return res;
    }

    bool TBufferedReader::hasNextTrigram(){
        if(pointer + 2 < line.size() || !stream->atEnd()){
            return  true;
        } else{
            return false;
        }
    }

    TBufferedReader::~TBufferedReader(){
        delete file;
        delete stream;
    }
