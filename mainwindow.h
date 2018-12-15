#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "fileindexer.h"
#include "progressdialog.h"
#include "trigramsrepository.h"
#include "trigramssearcher.h"

#include <memory>
#include <qmainwindow.h>
#include <qcommonstyle.h>
#include <QTreeWidgetItem>
#include <QFileSystemWatcher>


namespace Ui {
    class MainWindow;
}

class main_window : public QMainWindow {
    Q_OBJECT

public:

    void removeDirectory(QString dir);
    explicit main_window(QWidget *parent = nullptr);

    ~main_window();


    void findNextFile();
    public
    slots:
    void updateFile(QString path);
    void updateDirectory(QString dir);
    void changePattern();
    void  find();
    void fileClicked(QTreeWidgetItem *widget);
    void openFile(QString path);
    void save();
    void addFileDirectory(QString dir = "");
    private
       slots:
    void show_about_dialog();   

    void next();
private:
    QFileSystemWatcher watcher;
    TrigramsSearcher* searcher;
    TrigramsRepository trigramsRepository;
    QString pattern;
    FileIndexer indexer;
    QCommonStyle style;
    std::unique_ptr <Ui::MainWindow> ui;
    void clear();
};

#endif // MAINWINDOW_H
