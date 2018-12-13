#ifndef STOPSEARCH_H
#define STOPSEARCH_H

#include <QDialog>
#include <QThread>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    ProgressDialog(QThread* searchThread, QWidget *parent = 0);

    ~ProgressDialog();

public slots:

private:
    Ui::ProgressDialog *ui;
};

#endif // STOPSEARCH_H
