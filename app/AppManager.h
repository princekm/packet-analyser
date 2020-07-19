#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "UIManager.h"
#include "Worker.h"
#include <QThread>

class AppManager
{
private:
    QThread *workerThread ;
    UIManager *uiManager;
    Worker *worker;
    void setupConnections();
    void init();
    void attachWorkerThread();

public:
    AppManager();
    ~AppManager();
    void start();

};

#endif // APPMANAGER_H
