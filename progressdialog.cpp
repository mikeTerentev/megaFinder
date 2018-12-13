#include "progressdialog.h"
#include "ui_progressdialog.h"


ProgressDialog::ProgressDialog(QThread* searchThread, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}
