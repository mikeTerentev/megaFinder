#ifndef FINDERALGORITHM_H
#define FINDERALGORITHM_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QSet>


class FileIndexer : public QObject
{
    Q_OBJECT
public:
    FileIndexer(QString pattern);

    FileIndexer() = default;

    QString getLine()
    {
        return pattern;
    }
    void setLine(const QString &text)
    {
        pattern = text;
    }
private:
   QSet<QString> getDirectories(){
        return directories;
    }

private:
    QSet<QString> directories;
    QString pattern;
    QList<QString> foundFiles;
public slots:
    QSet<QString> findTrigrams(QString file);
    void indexDir(const QString &dir);
};

#endif // FINDERALGORITHM_H