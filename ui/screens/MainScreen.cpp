#include "MainScreen.h"
#include "Enum.h"
#include <QApplication>
#include "UIManager.h"
#include <QDebug>
MainScreen::MainScreen(Worker *worker, QWidget *parent)
{
    this->worker=worker;
    init();
    setUpConnections();
    applyStyle();
    emit sigConnected();

}

MainScreen::~MainScreen()
{

}


void MainScreen::init()
{
    setAttribute(Qt::WA_MacShowFocusRect, 0);
    setWindowTitle(qApp->applicationName());
    setWindowIcon(QIcon(UIManager::Resources::APP_ICON));

    QSize wSize(UIManager::Size::windowSize);
    QSize headingSize(UIManager::Size::headingSize);
    QSize snackSize(UIManager::Size::snackSize);
    QSize iconSize(headingSize.height(),headingSize.height());
    setMinimumSize(wSize);

    heading = new QLabel();
    indicator = new QProgressBar();
    heading->setLayout(new QHBoxLayout);
    heading->layout()->addWidget(indicator);
    indicator->setRange(0,359);
    indicator->setValue(0);
    indicator->setTextVisible(false);
    indicator->hide();
    // indicator->setWrapping(true);
    indicator->setFixedSize(headingSize.height()*5,headingSize.height());

    heading->setFixedHeight(headingSize.height());
    heading->setAlignment(Qt::AlignCenter);
    settingsWidget = new SettingsWidget(worker);
    explorerWidget = new ExplorerWidget(worker);
    captureWidget = new CaptureWidget();
    packetEditorWidget = new PacketEditor();
    inspectorWidget = new InspectorWidget;

    tabWidget = new QTabWidget();
    mainLayout = new QVBoxLayout(this);
    menuList << "Settings" <<"Explorer"<<"Inspect"<<"Sniffer"<<"Editor"<<"Help";
    tabWidget->addTab(settingsWidget,menuList.at(0));
    tabWidget->addTab(explorerWidget,menuList.at(1));
    tabWidget->addTab(inspectorWidget,menuList.at(2));
    tabWidget->addTab(captureWidget,menuList.at(3));


    snackBar = new SnackBar(heading);
    snackBar->setMinimumSize(headingSize);

    mainLayout->addWidget(heading);
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(snackBar);
    mainLayout->setMargin(0);


}

void MainScreen::setUpConnections()
{
    connect(worker,SIGNAL(sigInfo(QString,Worker::MessageType)),this,SLOT(slotProcessWorkerInfo(QString,Worker::MessageType)));

    connect(worker,SIGNAL(sigCaptured(const struct pcap_pkthdr*,const unsigned char*)),captureWidget,SLOT(slotDisplayCaptured(const struct pcap_pkthdr* ,const unsigned char*)))  ;

    connect(captureWidget,SIGNAL(sigStartCapture()),worker,SLOT(slotStartCapture()));
    connect(captureWidget,SIGNAL(sigStopCapture()),worker,SLOT(slotStopCapture()));

    connect(Worker::getDataStore(),SIGNAL(sigInterfaceChanged(QString)),this,SLOT(slotInterfaceNameNotify(QString)));

    connect(this,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(explorerWidget,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(packetEditorWidget,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));
    connect(inspectorWidget,SIGNAL(sigSnackBar(QString,QColor)),snackBar,SLOT(slotSetText(QString,QColor)));

    connect(packetEditorWidget,SIGNAL(sigUpdateFileSize(int)),explorerWidget,SLOT(slotUpdateFileSize(int)));

    connect(packetEditorWidget,SIGNAL(sigSaved(QString)),inspectorWidget,SLOT(slotPopulateTree(QString)));

    connect(explorerWidget,SIGNAL(sigEditPacket(QTreeWidgetItem *,int )),packetEditorWidget,SLOT(slotEditPacket(QTreeWidgetItem *,int )));
    connect(explorerWidget,SIGNAL(sigEditPacket(QTreeWidgetItem *,int )),this,SLOT(slotAddEditorTab()));

    connect(captureWidget,SIGNAL(sigInspectPacket(QString)),this,SLOT(slotGotoInspectorTab()));

    connect(explorerWidget,SIGNAL(sigAddCapturePacket(QString)),inspectorWidget,SLOT(slotAddPacketTypes(QString)));
    connect(explorerWidget,SIGNAL(sigFileAdded(QString)),inspectorWidget,SLOT(slotAddPacketTypes(QString)));
    connect(explorerWidget,SIGNAL(sigFileDeleted(QString)),inspectorWidget,SLOT(slotDeletePacketTypes(QString)));
    connect(explorerWidget,SIGNAL(sigCapture()),this,SLOT(slotGotoInspectorTab()));

    connect(inspectorWidget,SIGNAL(sigRequestFileList()),explorerWidget,SLOT(slotHandleRequestFileList()));
    connect(explorerWidget,SIGNAL(sigEmitFileList(QStringList)),inspectorWidget,SLOT(slotUpdateFileList(QStringList)));

    connect(worker,SIGNAL(sigCaptureReady(QString)),captureWidget,SLOT(slotSetInterfaceName(QString)));
    connect(this,SIGNAL(sigConnected()),inspectorWidget,SIGNAL(sigRequestFileList()));

    connect(captureWidget,SIGNAL(sigBusySignal()),this,SLOT(slotRotateDial()));
    connect(inspectorWidget,SIGNAL(sigInspect(bool)),this,SLOT(slotInspect(bool)));
    connect(captureWidget,SIGNAL(sigEnable(bool)),settingsWidget,SLOT(slotEnable(bool)));
    connect(captureWidget,SIGNAL(sigEnable(bool)),inspectorWidget,SLOT(slotDisable(bool)));
    connect(captureWidget,SIGNAL(sigEnable(bool)),this,SLOT(slotEnable(bool)));
    connect(captureWidget,SIGNAL(sigFilter(QString)),worker,SLOT(slotSetFilter(QString)));
    connect(worker,SIGNAL(sigFiltered(bool)),captureWidget,SLOT(slotFilterReady(bool)));
}


void MainScreen::applyStyle()
{
    setStyleSheet("QFrame{background:#ecf0f1;color:black}");

}

void MainScreen::slotInspect(bool turnOn)
{
    if(turnOn)
    {
        connect(captureWidget,SIGNAL(sigPayload(uchar*,int)),inspectorWidget,SLOT(slotPayload(uchar*,int)));
    }
    else
    {
        disconnect(captureWidget,SIGNAL(sigPayload(uchar*,int)),inspectorWidget,SLOT(slotPayload(uchar*,int)));
    }
}

void MainScreen::slotRotateDial()
{
    int val=indicator->value();
    val+=10;
    val%=360;
    indicator->setValue(val);
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


void MainScreen::slotAddEditorTab()
{
    tabWidget->insertTab(2,packetEditorWidget,menuList.at(4));
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

void MainScreen::slotGotoInspectorTab()
{
    tabWidget->setCurrentWidget(inspectorWidget);
}

void MainScreen::slotRemoveInspectorTab()
{

}

void MainScreen::slotEnable(bool enable)
{
    if(!enable)
    {
        indicator->setValue(0);
      //  heading->setText("Capturing");
        indicator->show();
    }
    else
    {
        indicator->hide();
      //  heading->setText("");
     //   heading->repaint();
    }
}

void MainScreen::slotRemoveCapturesTab()
{
    tabWidget->removeTab(3);

}

void MainScreen::slotProcessWorkerInfo(QString message, Worker::MessageType type)
{
    if(type==Worker::MSG_INFO)
        emit sigSnackBar(message,UIManager::Resources::NOTIFY_COLOR);
    else if(type==Worker::MSG_ERROR)
        emit sigSnackBar(message,UIManager::Resources::ERROR_COLOR);

}
