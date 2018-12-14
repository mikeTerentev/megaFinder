#include "textviewer.h"

#include <QMessageBox>
#include <QTextCursor>

void TextViewer::save(){
    if(document()->isModified()){

    }
}
void TextViewer::search()
{
        amount = 0;
        currentUsage=0;
        extraSelections.clear();
        moveCursor(QTextCursor::Start);
        while(find(line))
        {
            amount++;
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);
            extra.cursor = textCursor();
            extraSelections.append(extra);
        }

   setExtraSelections(extraSelections);
   moveCursor(QTextCursor::Start);
}

void TextViewer::next(){
   qDebug()<<"search next place";
   if (amount == 0)
       return;
   extraSelections.clear();
   QTextCursor cursor = textCursor();
   cursor.clearSelection();
   setTextCursor(cursor);
   if (!find(line) && amount != 0){
       moveCursor(QTextCursor::Start);
       currentUsage = 0;
       find(line);
   }
    currentUsage++;
    textCursor().select(QTextCursor::BlockUnderCursor);
}

void TextViewer::openFile(QString path){
    filePath = path;
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Can't open file",
                             QString("File \n\n %1 \n\n can't be opened.").arg(filePath),
                             QMessageBox::Ok);
    }
    QTextStream ReadFile(&file);
    document()->setPlainText(ReadFile.readAll());
    search();
    isChanged = false;
}

void TextViewer::enableFlag(){
    qDebug()<<"text modifited";
    isChanged = true;
}
