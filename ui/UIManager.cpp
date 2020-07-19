#include "UIManager.h"
#include "MainScreen.h"
#include "SplashScreen.h"

const QString UIManager::Resources::FOLDER_ICON=":/folder.png";
const QString UIManager::Resources::FILE_ICON=":/file.png";
const QString UIManager::Resources::APP_ICON=":/ethernet.png";
const QString UIManager::Resources::FILE_EXTENSION=".proto";
const QString UIManager::Resources::CLOSE_ICON=":/close.png";
const QColor UIManager::Resources::NOTIFY_COLOR=QColor("#16a085");
const QColor UIManager::Resources::ERROR_COLOR=QColor("#c0392b");


const int UIManager::Size::WIDGET_HEIGHT=30;
const QSize UIManager::Size::windowSize=QSize(700,500);
const QSize UIManager::Size::headingSize=QSize(windowSize.width(),WIDGET_HEIGHT);
const QSize UIManager::Size::snackSize=QSize(windowSize.width(),WIDGET_HEIGHT);
const QSize UIManager::Size::frameSize=QSize(windowSize.width()*0.7,windowSize.height()*0.5);
const QSize UIManager::Size::nameDialogSize=QSize(150,2*WIDGET_HEIGHT);
const QSize UIManager::Size::typeDialogSize=QSize(150,WIDGET_HEIGHT*5);
const QSize UIManager::Size::arrayDialogSize=QSize(150,WIDGET_HEIGHT*6);
const QSize UIManager::Size::objectDialogSize=QSize(150,WIDGET_HEIGHT*3);

UIManager::UIManager(Worker *worker, QObject *parent) : QObject(parent)
{
    this->worker=worker;
}

void UIManager::start()
{
    startScreen->show();
}

UIManager::~UIManager()
{
    delete startScreen;
}

void UIManager::slotReady()
{
    init();
    setupConnections();
    start();

}

void UIManager::init()
{
    mainScreen = new MainScreen(worker);
    startScreen =  new SplashScreen();
}

void UIManager::setupConnections()
{
    connect(worker,SIGNAL(sigProgress(int)),startScreen,SLOT(slotProgress(int)));
    connect(startScreen,SIGNAL(sigNext()),mainScreen,SLOT(show()));
    connect(startScreen,SIGNAL(sigNext()),startScreen,SLOT(hide()));
}
