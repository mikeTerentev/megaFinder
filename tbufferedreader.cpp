#include "tbufferedreader.h"


    TBufferedReader::TBufferedReader(QString filePath){
        file = new QFile(filePath);
        if (file->open(QFile::ReadOnly)){
            stream = new QTextStream(file);
            line = stream->readAll();
            it=line.begin();
            size = line.size();
            pointer = 0;
        }
    }


    QString TBufferedReader::nextTrigram(){
        /*if (pointer + 2 >= line.size()){pointer = 0; line = stream->readAll()}*/
        res = (*it);
        for(int i=0; i<2;i++){
             pointer++;
             it++;
             res+=(*it);
        }
        it--;
        return res;
    }

    bool TBufferedReader::hasNextTrigram(){
        if(pointer + 2 < size /*|| !stream->atEnd()*/){
            return  true;
        } else{
            return false;
        }
    }
    TBufferedReader::~TBufferedReader(){
        delete file;
        delete stream;
    }

    bool TBufferedReader::isTextFile(){
        for(auto it = line.begin(); it != line.end(); it++){
            if(*it == '\0'){
                return false;
            }
        }
        return true;
    }
