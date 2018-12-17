
#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "mainwindow.h"
#include "tbufferedreader.h"
#include "QDebug"
int main(int argc, char *argv[]) {
    qDebug()<<static_cast<unsigned char>('a');
    qDebug()<<((static_cast<unsigned char>('a') << 8) + static_cast<unsigned char>('b'));
    qDebug()<<"abc"<< (((static_cast<unsigned char>('a') << 8) + static_cast<unsigned char>('b')) << 8) + static_cast<unsigned char>('c');
    TBufferedReader x("/Users/miketerentyev/itmo/poligon.txt");
    while(x.hasNextTrigram()){
        qDebug()<<x.hasNextTrigram()<<" "<< x.nextTrigram()<<endl;
    }
    QApplication app(argc, argv);
    main_window w;
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription("Mega Cleaner");
    parser.addHelpOption();
    parser.addVersionOption();
    w.show();
    return app.exec();
}
