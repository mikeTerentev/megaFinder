#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>



main_window::main_window(QWidget *parent)
        :  QMainWindow(parent) ,ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->dirWidget->setMainWindow(this);
    ui->treeWidget->setTextViewer(ui->textViewer);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->NAME_COL,  QHeaderView::Stretch);
    ui->treeWidget->header()->setSectionResizeMode(ui->treeWidget->DIR_COL, QHeaderView::Stretch);
    ui->treeWidget->header()->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->dirWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    ui->actionScan_Directory->setIcon(style.standardIcon(QCommonStyle::SP_DialogOpenButton));
    ui->actionExit->setIcon(style.standardIcon(QCommonStyle::SP_DialogCloseButton));
    ui->actionAbout->setIcon(style.standardIcon(QCommonStyle::SP_DialogHelpButton));
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, this, &main_window::show_about_dialog);

    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem * , int)), this, SLOT(fileClicked(QTreeWidgetItem * )));
    connect(ui->treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem * , QTreeWidgetItem * )), this, SLOT(fileClicked(QTreeWidgetItem * )));

    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(find()));
    connect(ui->nextButton,SIGNAL(pressed()),this,SLOT(next()));
    connect(ui->textViewer,SIGNAL(textChanged()),ui->textViewer,SLOT(enableFlag()));

    connect(ui->dirWidget, SIGNAL(itemClicked(QTreeWidgetItem *,int)), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));
    connect(ui->dirWidget, SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem * )), ui->dirWidget, SLOT(fileClicked(QTreeWidgetItem * )));

    connect(ui->addFileButton, SIGNAL(clicked()),this,SLOT(addFileDirectory()));
}

main_window::~main_window() {}

void main_window::findNextFile(){
    ui->textViewer->search();
    next();
}

void main_window::find(){
    QString pattern = ui->lineEdit->text();
    ui->textViewer->setLine(pattern);
    QList<QString> files = searcher.find(pattern);
    ui->treeWidget->addFileFiles(files);
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
    QString dir = QFileDialog::getExistingDirectory(this, "Select Directory for Scanning",QString(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (searcher.addFileDir(dir)){
       ui->dirWidget->addFileDir(dir);
       searcher.indexDir(dir);
    }
    else
    {
        QMessageBox::warning(this, "Directory has already addFileed",QString("Directory \n\n %1 \n\n has already addFileed.").arg(dir), QMessageBox::Ok);
    }
}

void main_window::deleteDir(QString dir){
    searcher.deleteDir(dir);
    ui->dirWidget->deleteDir(dir);
}

void main_window::fileClicked(QTreeWidgetItem * widget){
    ui->treeWidget->fileSelected(widget);
    ui->treeWidget->onTreeWidgetClicked();
    findNextFile();
}

void main_window::show_about_dialog() {
    QMessageBox::aboutQt(this);
}