#include "SettingsWidget.h"
#include "UIManager.h"
SettingsWidget::~SettingsWidget()
{

}

SettingsWidget::SettingsWidget(Worker *worker,QWidget *parent)
{
    this->worker=worker;
    init();
    setUpConnections();
    applyStyle();
    loadInterfaceNames();
}


void SettingsWidget::init()
{
    QSize mainFrameSize(UIManager::Size::frameSize);
    mainFrame = new QFrame();

    mainFrame->setFixedSize(mainFrameSize);
    selectInterfaceLabel = new QLabel("Interface:");
    selectInterfaceLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    selectEndianLabel = new QLabel("Endianness:");
    selectEndianLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    interfaceNames = new QComboBox;
    endianNames = new QComboBox;
    endianNames->addItem("Big Endian");
    endianNames->addItem("Little Endian");

    innerLayout = new QGridLayout(mainFrame);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(mainFrame);
    innerLayout->setSpacing(2);
    innerLayout->setMargin(2);
    innerLayout->addWidget(selectInterfaceLabel,0,0);
    innerLayout->addWidget(interfaceNames,0,1);
    innerLayout->addWidget(selectEndianLabel,1,0);
    innerLayout->addWidget(endianNames,1,1);
}

void SettingsWidget::setUpConnections()
{
    connect(worker,SIGNAL(sigInterfaceList(QStringList )),this,SLOT(slotAddInterfaceNames(QStringList)));
    connect(interfaceNames,SIGNAL(currentTextChanged(QString)),Worker::getDataStore(),SLOT(slotSetInterfaceName(QString)));
    connect(endianNames,SIGNAL(currentTextChanged(QString)),Worker::getDataStore(),SLOT(slotSetEndianness(QString)));
    connect(this,SIGNAL(sigFetchInterfaceNames()),worker,SLOT(slotFetchEthernetInterfaces()));
}

void SettingsWidget::applyStyle()
{
    setStyleSheet("QLabel{color:white}");
    endianNames->setAttribute(Qt::WA_MacShowFocusRect, 0);
    interfaceNames->setAttribute(Qt::WA_MacShowFocusRect, 0);

}

void SettingsWidget::loadInterfaceNames()
{
    emit sigFetchInterfaceNames();
}

void SettingsWidget::slotAddInterfaceNames(QStringList interfaceNameList)
{
    interfaceNames->addItems(interfaceNameList);
}

