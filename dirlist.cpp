#include "dirlist.h"






void DirList::addFileDir( QString dir){
    QTreeWidgetItem* x = new QTreeWidgetItem(this);
    x->setText(0,dir);
    addTopLevelItem(x);
}
void DirList::deleteDir(QString dir){
    delete selectedDir;
}
void DirList::fileClicked(QTreeWidgetItem * item){
    selectedDir = item;
    qDebug()<<"dirClicked changed in dir list";
}


void DirList::keyPressEvent(QKeyEvent * event){
    QString x =event->text();
    if ( event->key() == Qt::Key_Backspace){
        mainwindow->deleteDir(selectedDir->text(0));
    }
    if ( event->key() == Qt::Key_N){
        mainwindow->addFileDirectory();
    }
    qDebug() << Qt::Key(event->key());

    QTreeWidget::keyPressEvent(event);
}
