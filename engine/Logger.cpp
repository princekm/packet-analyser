#include "Logger.h"
#include <QDebug>
#include <QCoreApplication>
#include "Worker.h"
Logger::Logger(QObject *parent) : QObject(parent)
{

}

Logger::~Logger()
{

}

void Logger::slotLoad()
{
    file = new QFile();
    QString path=QCoreApplication::applicationDirPath();
    file->setFileName(path+"/Logs/log.txt");
    file->open(QFile::WriteOnly);


}

void Logger::slotClear()
{
    if(file->isOpen())
    {
        file->close();
        file->open(QFile::WriteOnly);
    }
}


void Logger::slotLog(QStringList row)
{
    qDebug()<<row;
    file<<row<<endl;
}

void Logger::slotSaveLog(QString fileName)
{
    QString path=QCoreApplication::applicationDirPath();
    bool done=file->copy(path+"/Logs/"+fileName);
    if(done)
    {

        emit sigSnackBar("Log saved in '"+fileName+"' successfully",Worker::MSG_INFO);
    }
    else
    {
        emit sigSnackBar("Could not save contents in '"+fileName+"'",Worker::MSG_ERROR);

    }
}
