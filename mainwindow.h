#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "fileindexer.h"
#include "patternsearcher.h"

#include <memory>
#include <qmainwindow.h>
#include <qcommonstyle.h>
#include <QTreeWidgetItem>


namespace Ui {
    class MainWindow;
}

class main_window : public QMainWindow {
    Q_OBJECT

public:

    void deleteDir(QString dir);
    explicit main_window(QWidget *parent = nullptr);

    ~main_window();


    void findNextFile();
    public
    slots:
    void addFileDirectory();
    void  find();
    void fileClicked(QTreeWidgetItem *widget);
    private
    slots:
    void show_about_dialog();   


    void next();
private:
    FileIndexer indexer;
    PatternSearcher searcher;
    QCommonStyle style;
    std::unique_ptr <Ui::MainWindow> ui;
};

#endif // MAINWINDOW_H
