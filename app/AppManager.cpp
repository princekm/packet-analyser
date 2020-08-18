#include "AppManager.h"
#include <QApplication>

AppManager::AppManager()
{
    init();
    setupConnections();
    attachWorkerThread();

}
void AppManager::setupConnections()
{
    QObject::connect(workerThread,SIGNAL(started()),worker,SLOT(slotLoad()));
    QObject::connect(worker,SIGNAL(sigFinished()),workerThread,SLOT(quit()));
    QObject::connect(worker,SIGNAL(sigReady()),uiManager,SLOT(slotReady()));



}

void AppManager::init()
{
    QFont f = qApp->font();
    f.setFamily("Monaco");
    f.setPointSize(10);
    qApp->setFont(f);
    worker = new Worker();
    uiManager = new UIManager(worker);
    workerThread = new QThread();

}

void AppManager::attachWorkerThread()
{
    worker->moveToThread(workerThread);
}

AppManager::~AppManager()
{

}

void AppManager::start()
{
  workerThread->start();
  //uiManager->start();

}
