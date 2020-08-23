#include "AppManager.h"
#include <QApplication>

AppManager::AppManager()
{
    init();
    setupConnections();
    attachWorkerThread();
    applyStyle();

}
void AppManager::setupConnections()
{
    QObject::connect(workerThread,SIGNAL(started()),worker,SLOT(slotLoad()));
    QObject::connect(worker,SIGNAL(sigFinished()),workerThread,SLOT(quit()));
    QObject::connect(worker,SIGNAL(sigReady()),uiManager,SLOT(slotReady()));

    QObject::connect(loggerThread,SIGNAL(started()),logger,SLOT(slotLoad()));
    QObject::connect(logger,SIGNAL(sigFinished()),loggerThread,SLOT(quit()));


}

void AppManager::init()
{

    worker = new Worker();
    logger = new Logger();
    uiManager = new UIManager(worker,logger);
    workerThread = new QThread();
    loggerThread = new QThread();

}

void AppManager::applyStyle()
{
    if(qApp)
    {
        QFont f = qApp->font();
        f.setFamily("Monaco");
        f.setPointSize(12);
        qApp->setFont(f);
    }
}

void AppManager::attachWorkerThread()
{
    worker->moveToThread(workerThread);
    logger->moveToThread(loggerThread);
}

AppManager::~AppManager()
{

}

void AppManager::start()
{
    workerThread->start();
    loggerThread->start();
}
