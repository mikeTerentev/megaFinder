#include <QFileDialog>

#include "mainwindow.h"
#include "trigramssearcher.h"
#include "ui_mainwindow.h"



main_window::main_window(QWidget *parent)
        :  QMainWindow(parent) ,ui(new Ui::MainWindow){
    qRegisterMetaType<qstring_list>( "qstring_list" );
    ui->setupUi(this);
    ui->dirWidget->setMainWindow(this);
    ui->treeWidget->setMainWindow(this);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->NAME_COL,  QHeaderView::ResizeToContents);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->DIR_COL, QHeaderView::Stretch);
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
  
    connect(ui->nextButton,SIGNAL(pressed()),this,SLOT(next()));
    connect(ui->prevButton,SIGNAL(pressed()),this,SLOT(prev()));
    connect(ui->textViewer,SIGNAL(textChanged()),ui->textViewer,SLOT(enableFlag()));

    connect(ui->dirWidget, SIGNAL(itemClicked(QTreeWidgetItem *,int)), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));
    connect(ui->dirWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem * )), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));

    connect(ui->addFileButton, SIGNAL(clicked()),this, SLOT(addFileDirectory()));
    watcher = new QFileSystemWatcher();
    connect(watcher,SIGNAL(fileChanged(QString)),this, SLOT(updateFile(QString)));
    connect(watcher,SIGNAL(directoryChanged(QString)),this, SLOT(updateDirectory(QString)));
    trigramsRepository = new TrigramsRepository();
    thread.start();
       thread.quit();
       thread.wait();
}

main_window::~main_window() {
    thread.quit();
    thread.wait();
    delete trigramsRepository;
    delete watcher;
}

void main_window::changePattern(){
    ui->foundAmountLabel->clear();
    ui->fileNameLabel->clear();
    ui->textViewer->clear();
    pattern = ui->lineEdit->toPlainText();
    qDebug()<<"pattern changed to "<<pattern;
    find();
}
void main_window::findNextFile(){
    ui->textViewer->search();
    next();
    QFileInfo f(ui->textViewer->getFilePath());
    ui->fileNameLabel->setText("File :" + f.completeBaseName() + f.completeSuffix());
    ui->foundAmountLabel->setText(QString::number(ui->textViewer->getAmount()) + " usages");
}

void main_window::find(){
    if(!thread.isFinished()){
     thread.quit();
     thread.wait();
    }
    if (pattern.isEmpty()){
        return;
    }
    clear();
    block(true);
    ui->textViewer->setLine(pattern);
    searcher = new  TrigramsSearcher(pattern,trigramsRepository,watcher);
    searcher->setPattern(pattern);

    searcher->moveToThread(&thread);
    connect(&thread, &QThread::finished, searcher, &QObject::deleteLater);
    connect(&thread, SIGNAL (started()), searcher, SLOT (find()));
    connect(searcher, SIGNAL(filesCounted(int)),ui->progressBar,SLOT(setMaximum(int)));
    connect(trigramsRepository, SIGNAL(fileDone(int)), ui->progressBar, SLOT(setValue(int)));
    connect(searcher, SIGNAL(finished(QVector<QPair<QString,QList<QString>>>,bool)), this, SLOT(finishedSearch(QVector<QPair<QString,QList<QString>>>,bool)));
    //connect(searcher, SIGNAL(finished(QVector<QPair<QString,QList<QString>>>,bool)), &thread, SLOT(quit()));
    thread.start();
}

void main_window::finishedSearch(QVector<QPair<QString,QList<QString>>> info,bool fin){
     block(false);
     if(!fin) return;
     if(info.isEmpty()) return;
     ui->treeWidget->addFilesFromDirs(info);
     thread.quit();
     thread.wait();
}

void main_window::prev(){
     ui->textViewer->prev();
     qDebug()<<ui->textViewer->getCurrentUsage()<<" "<<ui->textViewer->getAmount();
}

void main_window::next(){
    ui->textViewer->next();
    qDebug()<<ui->textViewer->getCurrentUsage()<<" "<<ui->textViewer->getAmount();
}

void main_window::block(bool isEnable){
    ui->lineEdit->setDisabled(isEnable);
    ui->addFileButton->setDisabled(isEnable);
    ui->prevButton->setDisabled(isEnable);
    ui->nextButton->setDisabled(isEnable);
    ui->dirWidget->setDisabled(isEnable);
    ui->textViewer->setDisabled(isEnable);
    ui->treeWidget->setDisabled(isEnable);
}

void main_window::addFileDirectory(QString dir){
    clear();
    if(dir.isEmpty()){
        dir = QFileDialog::getExistingDirectory(this, "Select Directory for Scanning",QString(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    }
    if(dir.isEmpty()) return;
    QThread * indThread = new QThread();
    searcher = new  TrigramsSearcher(dir,trigramsRepository,watcher);
    searcher->setPattern(dir);
    searcher->moveToThread(indThread);
    auto* progressWindow = new ProgressDialog(&thread, this);
       connect(indThread, SIGNAL (started()), searcher, SLOT (indexDir()));
        connect(searcher, SIGNAL(filesCounted(int)),progressWindow, SLOT(setRange(int)));
       connect(searcher, SIGNAL(fileIndexing()), progressWindow, SLOT(update()));
       connect(searcher, SIGNAL (finished(int)),indThread, SLOT (quit()));
       connect(searcher, SIGNAL(finished(int)),  progressWindow, SLOT(done(int)));
       connect(indThread, SIGNAL (finished()), indThread, SLOT (deleteLater()));
       connect(searcher,SIGNAL(addPreprocessedDir(QString)),this,SLOT(addPreprocessedDir(QString)));
       connect(searcher,SIGNAL(foundDuplicate(QString)), this,SLOT(foundDuplicate(QString)));
    indThread->start();
    if (progressWindow->exec() == QDialog::Rejected) {
            indThread->requestInterruption();
            progressWindow->stopSearch();
        }
   delete progressWindow;
}

void main_window::addPreprocessedDir(QString curDir){
     ui->dirWidget->addFileDir(curDir);
     find();
}

void main_window::foundDuplicate(QString dir){
    QMessageBox::warning(this, "Directory has already added",QString("Directory \n\n %1 \n\n has already added.").arg(dir), QMessageBox::Ok);
    return;
}

void main_window::removeDirectory(const QString dir){
    ui->dirWidget->deleteDir(dir);
    ui->treeWidget->deleteDir(dir);
    ui->progressBar->setRange(0,trigramsRepository->getTrigramData()[dir].size());
    block(true);
    ui->lineEdit->setDisabled(true);
    watcher->removePath(dir);
    QThread* remThread = new QThread();
    searcher = new  TrigramsSearcher(dir,trigramsRepository,watcher);
    searcher->moveToThread(remThread);
       connect(remThread, SIGNAL (started()), searcher, SLOT (removeDirectory()));
       connect(searcher, SIGNAL(updateBar(int)), ui->progressBar, SLOT(setValue(int)));
        connect(searcher, SIGNAL (finished()), this, SLOT (endRemoving()));
         connect(searcher, SIGNAL (finished()),remThread,SLOT(quit()));
       connect(remThread, SIGNAL (finished()), remThread, SLOT (deleteLater()));
    remThread->start();
}

void main_window::endRemoving(){
    block(false);
    ui->lineEdit->setDisabled(false);
    clear();
}


void main_window::updateFile(QString path){
   QFile fl(path);
   if(!fl.exists()) return;
   block(true);
   TrigramsSearcher localSearcher(path,trigramsRepository,watcher);
   trigramsRepository->insertFile(path,localSearcher.getFileTrigrams());
   if(ui->textViewer->getFilePath() == path){
       ui->textViewer->openFile(path);
       QMessageBox::warning(this, "Update",QString("File \n\n %1 \n\n was updated").arg(path), QMessageBox::Ok);
   }
   block(false);
}

void main_window::updateDirectory(QString dir){
   if (QMessageBox::warning(this, "Changing",
                           QString("%1 \n\n changed. Do you want to reindex it?").arg(dir),
                           QMessageBox::Yes | QMessageBox::Reset) == QMessageBox::Yes){
     removeDirectory(dir);
     addFileDirectory(dir);
   } else{
     removeDirectory(dir);
   }

}


void main_window::clear(){
    ui->treeWidget->clear();
    ui->textViewer->clear();
    ui->foundAmountLabel->clear();
    ui->fileNameLabel->clear();
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
