
#include <QApplication>
#include "AppManager.h"
#include <QDebug>
#include <QIcon>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(UIManager::Resources::APP_ICON));
    a.setApplicationName("Packet Analyser");
    AppManager *appManager = new AppManager();
    appManager->start();
    return a.exec();
}
