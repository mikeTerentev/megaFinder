
#include "mytreewidget.h"


void MyTreeWidget::addFileFile(QString& path){
    QFileInfo file(path);
    QTreeWidgetItem *item = new QTreeWidgetItem(this);
    item->setIcon(NAME_COL, style.standardIcon(QStyle::SP_FileIcon));
    setItemParameters(item, file);
    insertTopLevelItem(0,item);
}


void MyTreeWidget::addFileFiles(QList<QString>& list){
    for(auto& file : list){
        addFileFile(file);
    }
}

void MyTreeWidget::fileSelected(QTreeWidgetItem *curFile) {
   selectedFile = curFile;
}


void MyTreeWidget::removeFile(QTreeWidgetItem *child) {
    QString delFilePath = getItemName(child);
    QFile file(delFilePath);
    if (!file.remove()) {
        QMessageBox::warning(this, "Can't delete file",
                             QString("File \n\n %1 \n\n can't be removed.").arg(delFilePath),
                             QMessageBox::Ok);
    }
}


void MyTreeWidget::show(){

}

void MyTreeWidget::onTreeWidgetClicked() {
    textviewer->save();
    QFileInfo f(getItemName(selectedFile));
    if(f.isDir()) return;
    textviewer->openFile(getItemName(selectedFile));
    textviewer->search();
    // Файл закидывается в вьювер и нужные подсвечиваются
}





QString MyTreeWidget::getItemName(QTreeWidgetItem *item) {
    return QString("%1/%2").arg(item->text(DIR_COL), item->text(NAME_COL));
}


void MyTreeWidget::keyPressEvent(QKeyEvent * event){
    QString x =event->text();
    if ( event->key() == Qt::Key_Return){
        this->onTreeWidgetClicked();
    }
    if ( event->key() == Qt::Key_Escape ){
        currentDir.truncate(currentDir.lastIndexOf("/"));
        if(currentDir.size()==0){
            currentDir = "/";
        };
    }
    qDebug() << Qt::Key(event->key());

    QTreeWidget::keyPressEvent(event);
}
void MyTreeWidget::setItemParameters(QTreeWidgetItem *item, QFileInfo &file_info) {
    item->setText(DIR_COL, file_info.path());
    item->setText(NAME_COL, file_info.fileName());
}
