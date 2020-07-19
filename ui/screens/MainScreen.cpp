#include "MainScreen.h"
#include "Enum.h"
#include <QApplication>
#include "UIManager.h"
MainScreen::MainScreen(Worker *worker, QWidget *parent)
{
    this->worker=worker;
    init();
    setUpConnections();
    applyStyle();

}

MainScreen::~MainScreen()
{

}


void MainScreen::init()
{
    setAttribute(Qt::WA_MacShowFocusRect, 0);

    QSize wSize(UIManager::Size::windowSize);
    QSize headingSize(UIManager::Size::headingSize);
    QSize snackSize(UIManager::Size::snackSize);
    QSize iconSize(headingSize.height(),headingSize.height());
    setFixedSize(wSize);
    closeButton = new QToolButton();

    heading = new QLabel(qApp->objectName());
    toolButton =  new QToolButton(heading);
    toolButton->setFixedSize(iconSize);
    toolButton->move(wSize.width()-toolButton->width(),0);
    closeButton->setParent(heading);
    heading->setFixedSize(headingSize);
    heading->setAlignment(Qt::AlignCenter);
    setWindowFlags(Qt::FramelessWindowHint);
    settingsWidget = new SettingsWidget(worker);
    explorerWidget = new ExplorerWidget(worker);
    captureWidget = new CaptureWidget();
    packetEditorWidget = new PacketEditor();
    tabWidget = new QTabWidget();
    mainLayout = new QVBoxLayout(this);
    menuList << "Settings" <<"Packets"<<"Editor"<<"Captures"<<"Inspect";
    tabWidget->addTab(settingsWidget,menuList.at(0));
    tabWidget->addTab(explorerWidget,menuList.at(1));

    mainLayout->addWidget(heading);
    mainLayout->addWidget(tabWidget);
    mainLayout->setMargin(0);
    snackBar = new SnackBar();
    snackBar->setParent(this);
    snackBar->setFixedSize(snackSize);
    snackBar->move(0,wSize.height()-snackSize.height());

}

void MainScreen::setUpConnections()
{
    connect(worker,SIGNAL(sigInfo(QString,Worker::MessageType)),this,SLOT(slotProcessWorkerInfo(QString,Worker::MessageType)));

    connect(worker,SIGNAL(sigCaptured(const struct pcap_pkthdr*,const unsigned char*)),captureWidget,SLOT(slotDisplayCaptured(const struct pcap_pkthdr* ,const unsigned char*)))  ;

    connect(captureWidget,SIGNAL(sigStartCapture()),worker,SLOT(slotStartCapture()));
    connect(captureWidget,SIGNAL(sigStopCapture()),worker,SLOT(slotStopCapture()));

    connect(closeButton,SIGNAL(clicked()),this,SLOT(slotCloseApp()));
    connect(Worker::getDataStore(),SIGNAL(sigInterfaceChanged(QString)),this,SLOT(slotInterfaceNameNotify(QString)));
    connect(Worker::getDataStore(),SIGNAL(sigEndiannessChanged(QString)),this,SLOT(slotEndiannessNotify(QString)));

    connect(this,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(explorerWidget,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(packetEditorWidget,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(explorerWidget,SIGNAL(sigEditPacket(QTreeWidgetItem *,int )),packetEditorWidget,SLOT(slotEditPacket(QTreeWidgetItem *,int )));
    connect(explorerWidget,SIGNAL(sigEditPacket(QTreeWidgetItem *,int )),this,SLOT(slotAddEditorTab()));
    connect(explorerWidget,SIGNAL(sigCapture()),this,SLOT(slotAddCapturesTab()));
    connect(worker,SIGNAL(sigCaptureReady(QString)),captureWidget,SLOT(slotSetInterfaceName(QString)));
}


void MainScreen::applyStyle()
{
    setStyleSheet("QFrame{background:#2c3e50}");
    heading->setStyleSheet("QLabel{background:#2980b9;color:white}");
    toolButton->setStyleSheet("QToolButton{background:transparent}");
    closeButton->setStyleSheet("QToolButton{background:transparent}");
    toolButton->setIcon(QIcon(UIManager::Resources::APP_ICON));
    closeButton->setIcon(QIcon(UIManager::Resources::CLOSE_ICON));

}

void MainScreen::slotCloseApp()
{
    QApplication::exit(0);
}

void MainScreen::slotInterfaceNameNotify(QString interfaceName)
{
    QString text="Selected Interface:";
    emit sigSnackBar(text+interfaceName,UIManager::Resources::NOTIFY_COLOR);
}

void MainScreen::slotEndiannessNotify(QString interfaceName)
{
    QString text="Selected Endianness:";
    emit sigSnackBar(text+interfaceName,UIManager::Resources::NOTIFY_COLOR);
}

void MainScreen::slotAddEditorTab()
{
    tabWidget->insertTab(2,packetEditorWidget,menuList.at(2));
    tabWidget->setCurrentWidget(packetEditorWidget);

}

void MainScreen::slotRemoveEditorTab()
{
    tabWidget->removeTab(2);
}

void MainScreen::slotAddCapturesTab()
{
    tabWidget->insertTab(2,captureWidget,menuList.at(3));
    tabWidget->setCurrentWidget(captureWidget);

}

void MainScreen::slotRemoveCapturesTab()
{
    tabWidget->removeTab(3);

}

void MainScreen::slotProcessWorkerInfo(QString message, Worker::MessageType type)
{
    emit sigSnackBar(message,UIManager::Resources::NOTIFY_COLOR);
}
