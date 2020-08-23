#ifndef APPMANAGER_H
#define APPMANAGER_H
#include "UIManager.h"
#include "Worker.h"
#include "Logger.h"
#include <QThread>

class AppManager
{
private:
    QThread *workerThread ;
    QThread *loggerThread ;
    UIManager *uiManager;
    Worker *worker;
    Logger *logger;
    void setupConnections();
    void init();
    void applyStyle();
    void attachWorkerThread();

public:
    AppManager();
    ~AppManager();
    void start();

};

#endif // APPMANAGER_H
