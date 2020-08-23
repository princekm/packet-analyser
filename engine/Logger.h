#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <QObject>
#include <QFile>
#include "Worker.h"
class Logger : public QObject
{
    Q_OBJECT
private:
    QFile *file;
public:
    explicit Logger(QObject *parent = nullptr);
    ~Logger();

signals:
    void sigFinished();
    void sigSnackBar(QString ,Worker::MessageType);

private slots:
    void slotLoad();
    void slotClear();
    virtual void slotLog(QStringList row);
    void slotSaveLog(QString fileName);

};

#endif // FILEWRITER_H
