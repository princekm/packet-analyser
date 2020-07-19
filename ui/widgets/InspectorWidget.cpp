#include "InspectorWidget.h"
#include <QDebug>

InspectorWidget::InspectorWidget(QWidget *parent):Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();
}

void InspectorWidget::init()
{
    mainLayout = new QVBoxLayout(this);
    selectLabel = new QLabel("Select Packet:");
    selectLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    selectionLayout = new QHBoxLayout;

    initTree();
    packetTypeBox = new QComboBox;
    selectionLayout->addWidget(selectLabel);
    selectionLayout->addWidget(packetTypeBox);
    mainLayout->addLayout(selectionLayout);
    mainLayout->addWidget(packetTree);
    selectionLayout->setMargin(0);
    selectionLayout->setSpacing(0);

}

void InspectorWidget::initTree()
{
    rootItem = new QTreeWidgetItem;
    packetTree = new QTreeWidget;
    packetTree->setColumnCount(5);
    columnNames<<"Name"<<"Type"<<"Format"<<"Size"<<"Value";
    int i=0;
    for(QString header:columnNames)
    {
        packetTree->headerItem()->setText(i,header);
        i++;
    }

}

void InspectorWidget::setUpConnections()
{
    connect(packetTypeBox,SIGNAL(currentTextChanged( QString )),this,SLOT(slotPopulateTree(QString)));
}

void InspectorWidget::applyStyle()
{
    setStyleSheet("QLabel{color:white}");
}

void InspectorWidget::slotAddPacketTypes(QString packetType)
{
    int index=packetTypeBox->findText(packetType);
    if(index==-1)
    {
        packetTypeBox->addItem(packetType);
    }
    else
    {
        packetTypeBox->setCurrentText(packetType);
    }

}

void InspectorWidget::slotDeletePacketTypes(QString packetType)
{
    qDebug()<<"delete"+packetType;
    int index=packetTypeBox->findText(packetType);
    if(index>-1)
        packetTypeBox->removeItem(index);
}

void InspectorWidget::slotPopulateTree(QString fileName)
{

}
