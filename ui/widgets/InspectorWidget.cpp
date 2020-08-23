#include "InspectorWidget.h"
#include <QDebug>
#include "UIManager.h"
#include "Format.h"
#include "Decimal.h"
#include "Binary.h"
#include "ASCII.h"
#include "HexaDecimal.h"

InspectorWidget::InspectorWidget(QWidget *parent):Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();
    loadPacketTypes();

}

void InspectorWidget::init()
{
    mainLayout = new QVBoxLayout(this);
    doubleClickedItem=nullptr;
    formatDialog = new FormatDialog();
    countLabel = new QLabel("Total:0");
    selectLabel = new QLabel("Select Packet:");
    byteOrderLabel = new QLabel("Byte Order:");
    selectLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    byteOrderLabel->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    selectionLayout = new QHBoxLayout;
    startStopButton = new QPushButton("Filter");
    startStopButton->setDisabled(true);

    QIcon startIcon(UIManager::Resources::FILTER_ICON);

    startStopButton->setIcon(startIcon);

    initTree();
    packetTypeBox = new QComboBox;
    endiannessBox = new QComboBox;
    endiannessBox->addItem("Little Endian");
    endiannessBox->addItem("Big Endian");
    selectionLayout->addWidget(selectLabel);
    selectionLayout->addWidget(packetTypeBox);
    selectionLayout->addWidget(byteOrderLabel);

    selectionLayout->addWidget(endiannessBox);
    selectionLayout->addWidget(startStopButton);
    selectionLayout->addWidget(countLabel);
    mainLayout->addLayout(selectionLayout);
    mainLayout->addWidget(packetTree);
    selectionLayout->setMargin(0);
    selectionLayout->setSpacing(2);

}

void InspectorWidget::initTree()
{
    rootItem = new QTreeWidgetItem;
    rootItem->setText(0,"root");
    rootItem->setIcon(0,QIcon(UIManager::Resources::FOLDER_ICON));
    packetTree = new QTreeWidget;
    packetTree->setMinimumWidth(UIManager::Size::windowSize.width());
    packetTree->setColumnCount(5);
    packetTree->setColumnWidth(0,300);

    QTreeWidgetItem *topItem=new QTreeWidgetItem;
    packetTree->addTopLevelItem(topItem);
    packetTree->addTopLevelItem(rootItem);
    packetTree->topLevelItem(0)->setIcon(0,QIcon(UIManager::Resources::VIEW_ICON));
    columnNames<<"Name"<<"Type"<<"Format"<<"Size"<<"Value";
    int i=0;
    for(QString header:columnNames)
    {
        packetTree->headerItem()->setText(i,header);
        i++;
    }

}

void InspectorWidget::incrementTotalCount()
{
    int count=countLabel->text().split(':')[1].toInt();
    count+=1;
    countLabel->setText("Total:"+QString::number(count));
}

void InspectorWidget::resetCount()
{
    countLabel->setText("Total:0");
}

void InspectorWidget::setUpConnections()
{
    connect(formatDialog,SIGNAL(sigFormat(QString)),this,SLOT(slotChangeFormat(QString)));
    connect(startStopButton,SIGNAL(clicked()),this,SLOT(slotStartStop()));
    connect(packetTypeBox,SIGNAL(currentTextChanged( QString )),this,SLOT(slotPopulateTree(QString)));
    connect(packetTree,SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int )),this,SLOT(slotItemDoubleClicked(QTreeWidgetItem *, int )));
    connect(endiannessBox,SIGNAL(currentTextChanged(QString)),this,SLOT(slotNotifyEndianness(QString)));
}

void InspectorWidget::applyStyle()
{
    setStyleSheet("QLabel{color:black}");
    packetTree->setStyleSheet("QTreeWidget{color:black;background:white}");
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

void InspectorWidget::slotNotifyEndianness(QString endianNess)
{
    emit sigSnackBar("Selected "+endianNess,UIManager::Resources::NOTIFY_COLOR);
}
void InspectorWidget::removeAllChildren(QTreeWidgetItem *item)
{
    if(item)
    {
        for(int i=0;i<item->childCount();++i)
        {
            removeAllChildren(item->child(i));
            item->removeChild(item->child(i));
        }
    }
}
void InspectorWidget::slotDeletePacketTypes(QString packetType)
{
    int index=packetTypeBox->findText(packetType);
    if(index>-1)
        packetTypeBox->removeItem(index);
}
void InspectorWidget::populateTree()
{
    bool parsed=domDocument.setContent(file.readAll());
    if(parsed)
    {
        createTree(domDocument.firstChild(),rootItem);

    }
    else
    {
        emit sigSnackBar("Error:'"+file.fileName()+"' is corrupted",UIManager::Resources::ERROR_COLOR);

    }

}
void InspectorWidget::createTree(QDomNode node, QTreeWidgetItem *item)
{
    if(!node.isNull())
    {
        QDomElement element=node.toElement();
        QString typeName=element.tagName();
        QString variableName=element.attribute("name");
        QString format=element.attribute("format");
        QString size=element.attribute("size");


        item->setText(0,variableName);

        if(typeName=="Object")
            item->setIcon(0,QIcon(UIManager::Resources::FOLDER_ICON));
        else
            item->setIcon(0,QIcon(UIManager::Resources::FILE_ICON));

        item->setText(1,typeName);
        item->setText(2,format);
        item->setText(3,size);
        item->setExpanded(true);
        for(int i=0;i<node.childNodes().count();++i)
        {
            QTreeWidgetItem *child= new QTreeWidgetItem;

            item->addChild(child);
            createTree(node.childNodes().at(i),child);
        }
    }



}

void InspectorWidget::loadPacketTypes()
{
}

void InspectorWidget::populateValues(uchar *data, int offset, QTreeWidgetItem *item)
{
    QString typeString=item->text(1);
    if(typeString=="Object" || typeString.endsWith("Array"))
    {
        int curOffset=offset;
        for(int i=0;i<item->childCount();++i)
        {
            QTreeWidgetItem *childItem=item->child(i);
            populateValues(data,curOffset,childItem);
            int size = childItem->text(3).split(' ')[0].toInt();
            curOffset+=size;
        }
    }
    else
    {
        int size = item->text(3).split(' ')[0].toInt();
        QString valueString;
        QByteArray array=QByteArray::fromRawData((char*)(data+offset), size);
        QString formatString = item->text(2);
        Format *format=nullptr;
        TypeObject typeObject;
        typeObject.setTypeName(item->text(1));
        typeObject.setSize(size);
        typeObject.setFormat(formatString);
        bool bigEndian = endiannessBox->currentText()=="Big Endian"?true:false;
        if(formatString == "DEFAULT")
        {
            format = new Format(typeObject);
        }
        else if(formatString == "HEXADECIMAL")
        {
            format = new HexaDecimal(typeObject);
        }
        else if(formatString == "BINARY")
        {
            format = new Binary(typeObject);
        }
        else if(formatString == "DECIMAL")
        {
            format = new Decimal(typeObject);

        }
        else if(formatString == "ASCII")
        {
            format = new ASCII(typeObject);
        }
        bool ok;
        valueString = format->toString((char*)(data+offset),ok,bigEndian);
        item->setText(4,valueString);
        if(!ok)
            item->setBackground(4,QColor("#c0392b"));
        else
            item->setBackground(4,QColor("#27ae60"));
        item->setForeground(4,Qt::white);

        delete format;
    }

}

void InspectorWidget::clearValues(QTreeWidgetItem *item)
{
    QString typeString=item->text(1);
    if(typeString=="Object" || typeString.endsWith("Array"))
    {
        for(int i=0;i<item->childCount();++i)
        {
            QTreeWidgetItem *childItem=item->child(i);
            clearValues(childItem);
        }
    }
    else
    {
        item->setText(4,"");
        item->setBackground(4,Qt::white);
    }

}


void InspectorWidget::slotPopulateTree(QString fileName)
{
    qDebug()<<fileName;
    file.setFileName(fileName);
    packetTree->topLevelItem(0)->setText(0,fileName);

    bool opened=file.open(QFile::ReadWrite);
    if(opened)
    {
        qDebug()<<"file is updated";
        emit sigSnackBar("File "+fileName+" is updated",UIManager::Resources::NOTIFY_COLOR);
        packetTree->topLevelItem(0)->setText(0,fileName);
        removeAllChildren(rootItem);
        if(file.size()>0)
        {
            populateTree();
        }
        file.close();
    }
    else
        sigSnackBar("File "+fileName+" could not be opened",UIManager::Resources::ERROR_COLOR);

}

void InspectorWidget::slotUpdateFileList(QStringList fileList)
{
    for (QString packetType :fileList) {
        slotAddPacketTypes(packetType)  ;
    }
}

void InspectorWidget::slotPayload(uchar *data, int len)
{
    int packetSize = rootItem->text(3).split(' ')[0].toInt();
    qDebug()<<packetSize;
    qDebug()<<len;
    if(len>=packetSize)
    {
        qDebug("populating received");
        incrementTotalCount();
        populateValues(data,0,rootItem);
    }


}

void InspectorWidget::slotStartStop()
{
    QString buttonText=startStopButton->text();
    if(buttonText=="Filter")
    {
        emit sigInspect(true);
        startStopButton->setText("Stop");
    }
    else
    {
        emit sigInspect(false);
        resetCount();
        clearValues(rootItem);
        startStopButton->setText("Filter");

    }
}

void InspectorWidget::slotDisable(bool enable)
{
    if(!enable)
        startStopButton->setText("Filter");
    startStopButton->setEnabled(!enable);
}

void InspectorWidget::slotItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString type=item->text(1);
    if(column==2 && (type!="Object" && !type.endsWith("Array")))
    {
        doubleClickedItem=item;
        formatDialog->exec();
    }
}

void InspectorWidget::slotChangeFormat(QString format)
{
    if(doubleClickedItem)
        doubleClickedItem->setText(2,format);
}
