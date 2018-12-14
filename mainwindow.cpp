#include "mainwindow.h"
#include "trigramssearcher.h"
#include "ui_mainwindow.h"

#include <QFileDialog>



main_window::main_window(QWidget *parent)
        :  QMainWindow(parent) ,ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->dirWidget->setMainWindow(this);
    ui->treeWidget->setMainWindow(this);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->NAME_COL,  QHeaderView::Stretch);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->DIR_COL, QHeaderView::ResizeToContents);
   //  ui->treeWidget->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
   // ui->lineEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ui->lineEdit->setFixedHeight(40);
    ui->treeWidget->header()->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->dirWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
     ui->lineEdit->setReadOnly(false);
    ui->actionScan_Directory->setIcon(style.standardIcon(QCommonStyle::SP_DialogOpenButton));
    ui->actionExit->setIcon(style.standardIcon(QCommonStyle::SP_DialogCloseButton));
    ui->actionAbout->setIcon(style.standardIcon(QCommonStyle::SP_DialogHelpButton));
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, this, &main_window::show_about_dialog);

    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem * , int)), this, SLOT(fileClicked(QTreeWidgetItem * )));
    connect(ui->treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem * , QTreeWidgetItem * )), ui->treeWidget, SLOT(fileSelected(QTreeWidgetItem * )));

     connect(ui->lineEdit,SIGNAL(textChanged()),this,SLOT(changePattern()));
   // connect(ui->findButton,SIGNAL(clicked()),this,SLOT(changePattern()));
    connect(ui->nextButton,SIGNAL(pressed()),this,SLOT(next()));
    connect(ui->textViewer,SIGNAL(textChanged()),ui->textViewer,SLOT(enableFlag()));

    connect(ui->dirWidget, SIGNAL(itemClicked(QTreeWidgetItem *,int)), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));
    connect(ui->dirWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem * )), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));

    connect(ui->addFileButton, SIGNAL(clicked()),this,SLOT(addFileDirectory()));

}

main_window::~main_window() {
}

void main_window::changePattern(){
    pattern = ui->lineEdit->toPlainText();
    qDebug()<<"pattern changed to "<<pattern;
    find();
}
void main_window::findNextFile(){
    ui->textViewer->search();
    next();
}

void main_window::find(){
    if(pattern.isEmpty()){
        return;
    }
    ui->textViewer->setLine(pattern);
    QVector<QPair<QString,QList<QString>>> files = trigramsRepository.find(pattern);
    if(files.isEmpty()) return;
    ui->treeWidget->addFilesFromDirs(files);
    findNextFile();
}


void main_window::next(){
    ui->textViewer->next();
    qDebug()<<ui->textViewer->getCurrentUsage()<<" "<<ui->textViewer->getAmount();
    ui->foundAmountLabel->clear();
    QString msg = QString(QString::number(ui->textViewer->getCurrentUsage())+" of "+ QString::number(ui->textViewer->getAmount()) + "usages");
    ui->foundAmountLabel->setText(msg);
}

void main_window::addFileDirectory(){
    clear();

    QString dir = QFileDialog::getExistingDirectory(this, "Select Directory for Scanning",QString(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!trigramsRepository.canAddDir(dir)){
        QMessageBox::warning(this, "Directory has already added",QString("Directory \n\n %1 \n\n has already addFileed.").arg(dir), QMessageBox::Ok);
        return;
    }

    searcher = new  TrigramsSearcher(dir);
    auto *thread = new QThread();
    progressWindow = new ProgressDialog(thread, this);
    searcher->moveToThread(thread);

    connect(thread, SIGNAL (started()), searcher, SLOT (indexDir()));
    connect(searcher, SIGNAL(fileIndexing(QString)), progressWindow, SLOT(update(QString)));
    connect(searcher, SIGNAL(finished(int)), this, SLOT(save()));
    connect(searcher, SIGNAL (finished(int)), thread, SLOT (quit()));
    connect(searcher, SIGNAL(finished(int)),  progressWindow, SLOT(done(int)));
    connect(thread, SIGNAL (finished()), thread, SLOT (deleteLater()));

    thread->start();
    if (progressWindow->exec() == QDialog::Rejected) {
            progressWindow->stopSearch();
        }
   delete progressWindow;
}
void main_window::save(){
      if(searcher->isSearchCompleted()){
          ui->dirWidget->addFileDir(searcher->getDir());
      }
    trigramsRepository.insert(searcher->getDir(),searcher->getData());
    find();
}

void main_window::deleteDir(QString dir){
    trigramsRepository.deleteDir(dir);
    ui->dirWidget->deleteDir(dir);
    ui->treeWidget->deleteDir(dir);
    ui->textViewer->clear();
    ui->foundAmountLabel->clear();
}

void main_window::clear(){
    ui->treeWidget->clear();
    ui->textViewer->clear();
    ui->foundAmountLabel->clear();
}
void main_window::fileClicked(QTreeWidgetItem * widget){
    ui->treeWidget->fileSelected(widget);
    if ( widget->text(0).isEmpty()){
        return;
    }
    openFile(ui->treeWidget->getItemName(widget));
}

void main_window::openFile(QString path){
    QFileInfo f(path);
    if(f.isDir()) return;
    ui->textViewer->openFile(path);
    ui->textViewer->search();
    findNextFile();
}

void main_window::show_about_dialog() {
    QMessageBox::aboutQt(this);
}
