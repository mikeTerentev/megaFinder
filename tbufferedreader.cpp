#include "tbufferedreader.h"

#include <QDebug>
    TBufferedReader::TBufferedReader(QString filePath){
        file = new QFile(filePath);
        if (file->open(QFile::ReadOnly)){
            byteLine = file->readAll();
            it = byteLine.begin();
            size = byteLine.size();
            pointer = 0;
        }
    }


    uint64_t TBufferedReader::nextTrigram(){
        /*if (pointer + 2 >= line.size()){pointer = 0; line = stream->readAll()}*/
        hash = static_cast<unsigned char>(*it);
        //qDebug()<<"1 ->"<<hash;
        for(int i=0; i<2;i++){
             it++;
             hash = (hash << 8) +  static_cast<unsigned char>(*it);
             //qDebug()<<i+2<<" ->"<< hash;
        }
        it--;
        pointer++;
        return hash;
    }

    bool TBufferedReader::hasNextTrigram(){
        return  (pointer + 2 < size) ? true : false;
    }
    TBufferedReader::~TBufferedReader(){
        delete file;
    }

    bool TBufferedReader::isTextFile(){
        for(auto it = byteLine.begin(); it != byteLine.end(); it++){
            if(*it == '\0'){
                return false;
            }
        }
        return true;
    }
