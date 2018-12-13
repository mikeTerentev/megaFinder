#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H


#include <action.h>
#include <qcommonstyle.h>
#include <qtreewidget.h>
#include "QKeyEvent"
#include "mainwindow.h"
#include <qdesktopservices.h>
#include <qdebug.h>
#include <qapplication.h>
#include "QClipboard"
#include "progressdialog.h"
#include "textviewer.h"
#include <QFileInfoList>
#include <QMessageBox>
#include <QThread>
#include <qprogressbar.h>
#include <QDir>
class MyTreeWidget : public QTreeWidget {
    Q_OBJECT
public:
    const int DIR_COL = 1;
    const int NAME_COL = 0;

    virtual ~MyTreeWidget(){
    }

   explicit MyTreeWidget(QWidget *parent = nullptr):QTreeWidget (parent) {
        setUniformRowHeights(1);
    }


    void setTextViewer(TextViewer* tv){
        textviewer = tv;
    }

    void addFileFile(QString& path);

    void removeFile(QTreeWidgetItem *child);

    QString getItemName(QTreeWidgetItem *item);


    QTreeWidgetItem *getSelectedFile() {
        return selectedFile;
    }

    void setCurDir(QString& x) {
        currentDir = x;
    }

    void setSelectedFile(QTreeWidgetItem *x) {
        selectedFile = x;
    }

    void addFileFiles(QList<QString> &list);
public slots:
    void onTreeWidgetClicked();

    void fileSelected(QTreeWidgetItem *curFile);

    void keyPressEvent(QKeyEvent *event);

     void show();
private:
    QCommonStyle style;
    TextViewer* textviewer;
    QString currentDir ="/Users/miketerentyev/itmo/cleanerrrr";
    QTreeWidgetItem *selectedFile = nullptr;
    void setItemParameters(QTreeWidgetItem *item, QFileInfo &file_info);
};

#endif // MYTREEWIDGET_H
