#include "SettingsWidget.h"
#include "UIManager.h"
#include <QDebug>
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
    mainFrame->setMinimumSize(mainFrameSize);
    selectInterfaceLabel = new QLabel("Interface:");
    selectInterfaceLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    interfaceNames = new QComboBox;
    infoEdit = new QLabel();
    infoEdit->setAlignment(Qt::AlignHCenter);
    infoEdit->setMinimumWidth(mainFrameSize.width()/2);
    //infoEdit->setReadOnly(true);
    innerLayout = new QGridLayout(mainFrame);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(mainFrame,2);
    innerLayout->setSpacing(2);
    innerLayout->setMargin(2);
    innerLayout->addWidget(selectInterfaceLabel,0,0);
    innerLayout->addWidget(interfaceNames,0,1);
    mainLayout->addWidget(infoEdit,2);

}

void SettingsWidget::setUpConnections()
{
    connect(worker,SIGNAL(sigInterfaceList(QStringList )),this,SLOT(slotAddInterfaceNames(QStringList)));
    connect(worker,SIGNAL(sigEmitDeviceDetails(QStringList )),this,SLOT(slotDisplayInterfaceDetails(QStringList)));

    connect(interfaceNames,SIGNAL(currentTextChanged(QString)),Worker::getDataStore(),SLOT(slotSetInterfaceName(QString)));
    connect(this,SIGNAL(sigFetchInterfaceNames()),worker,SLOT(slotFetchEthernetInterfaces()));
}

void SettingsWidget::applyStyle()
{
    setStyleSheet("QLabel{color:black}");
    infoEdit->setStyleSheet("QTextEdit{border:none;color:black;background:white;text-align:center}");
    interfaceNames->setAttribute(Qt::WA_MacShowFocusRect, 0);


}

void SettingsWidget::loadInterfaceNames()
{
    emit sigFetchInterfaceNames();
}

void SettingsWidget::slotEnable(bool enable)
{
    interfaceNames->setEnabled(enable);
}

void SettingsWidget::slotAddInterfaceNames(QStringList interfaceNameList)
{
    interfaceNames->addItems(interfaceNameList);
}

void SettingsWidget::slotDisplayInterfaceDetails(const QStringList list)
{
    infoEdit->clear();
    infoEdit->setText("Device Details:\n");
    for(QString string:list)
    {
//        QString deviceString="Device:"+list.at(0);
        infoEdit->setText(infoEdit->text()+"\n"+string);
  //      infoEdit->setText(deviceString);
    }
}

