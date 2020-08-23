#include "UIManager.h"
#include "MainScreen.h"
#include "SplashScreen.h"

const QString UIManager::Resources::FOLDER_ICON=":/folder.png";
const QString UIManager::Resources::FILE_ICON=":/file.png";
const QString UIManager::Resources::APP_ICON=":/ethernet.png";
const QString UIManager::Resources::ADD_ICON=":/add.png";
const QString UIManager::Resources::CAPTURE_ICON=":/camera.png";
const QString UIManager::Resources::SAVE_ICON=":/save.png";
const QString UIManager::Resources::INFO_ICON=":/info.png";
const QString UIManager::Resources::TICK_ICON=":/ok.png";
const QString UIManager::Resources::DELETE_ICON=":/trash.png";
const QString UIManager::Resources::FILE_EXTENSION=".xml";
const QString UIManager::Resources::CLOSE_ICON=":/close.png";
const QString UIManager::Resources::START_ICON=":/start.png";
const QString UIManager::Resources::STOP_ICON=":/stop.png";
const QString UIManager::Resources::EDIT_ICON=":/edit.png";
const QString UIManager::Resources::CLEAR_ICON=":/clear.png";
const QString UIManager::Resources::BOX_ICON=":/packets.png";
const QString UIManager::Resources::FILTER_ICON=":/filter.png";
const QString UIManager::Resources::VIEW_ICON=":/view.png";
const QColor UIManager::Resources::NOTIFY_COLOR=QColor("#16a085");
const QColor UIManager::Resources::ERROR_COLOR=QColor("#c0392b");


const int UIManager::Size::WIDGET_HEIGHT=30;
const QSize UIManager::Size::windowSize=QSize(700,500);
const QSize UIManager::Size::headingSize=QSize(windowSize.width(),WIDGET_HEIGHT);
const QSize UIManager::Size::snackSize=QSize(windowSize.width(),WIDGET_HEIGHT);
const QSize UIManager::Size::frameSize=QSize(windowSize.width()*0.7,WIDGET_HEIGHT*4);
const QSize UIManager::Size::nameDialogSize=QSize(150,2*WIDGET_HEIGHT);
const QSize UIManager::Size::typeDialogSize=QSize(150,WIDGET_HEIGHT*5);
const QSize UIManager::Size::arrayDialogSize=QSize(150,WIDGET_HEIGHT*6);
const QSize UIManager::Size::objectDialogSize=QSize(150,WIDGET_HEIGHT*3);

UIManager::UIManager(Worker *worker, Logger *logger, QObject *parent) : QObject(parent)
{
    this->worker=worker;
    this->logger=logger;
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
    mainScreen = new MainScreen(worker,logger);
    startScreen =  new SplashScreen();
}

void UIManager::setupConnections()
{
    connect(worker,SIGNAL(sigProgress(int)),startScreen,SLOT(slotProgress(int)));
    connect(startScreen,SIGNAL(sigNext()),mainScreen,SLOT(showMaximized()));
    connect(startScreen,SIGNAL(sigNext()),startScreen,SLOT(hide()));
}
