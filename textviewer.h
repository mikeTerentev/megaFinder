#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include <QTextBrowser>

#include <QDebug>
#include <QFile>
#include <QPlainTextEdit>
#include <QTextStream>

class TextViewer : public QTextEdit
{
     Q_OBJECT
public:
    TextViewer(QWidget *parent = nullptr):QTextEdit(parent){
       // setReadOnly(true);
        moveCursor(QTextCursor::Start);
    }
    ~TextViewer()=default;
    void search();

    void setLine(const QString& tx){
        line = tx;
    }
    void save();

    int getAmount(){
        return amount;
    }

    int getCurrentUsage(){
        return currentUsage;
    }
public slots:
    void openFile(QString dir);

    void next();
    void enableFlag();
private:
   QList<QTextEdit::ExtraSelection>::iterator it;
    bool isChanged = false;
    int amount, currentUsage = 0;
    QString line;
    QList<QTextEdit::ExtraSelection> extraSelections;
    QColor color = QColor(Qt::yellow).lighter(120);

};

#endif // TEXTVIEWER_H
