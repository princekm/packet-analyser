#include "PacketEditor.h"
#include "UIManager.h"
#include "Worker.h"
#include <QFile>
#include <QMenu>
#include <QDebug>

PacketEditor::PacketEditor(QWidget *parent):Widget(parent)
{
    init();
    setupConnections();
    applyStyle();
}

void PacketEditor::init()
{
    initActions();
    QSize wSize(UIManager::Size::windowSize);
    setWindowFlags(Qt::FramelessWindowHint);

    dataTypeDialog = new DataTypeDialog;
    arrayDialog = new ArrayDialog;
    objectDialog = new ObjectTypeDialog;
    dataTypeDialog->build();
    arrayDialog->build();
    objectDialog->build();
    mainLayout = new QVBoxLayout(this);
    rootItem = new QTreeWidgetItem();
    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("Delete");
    saveButton = new QPushButton("Save");
    deleteButton->setDisabled(true);
    addButton->setDisabled(true);
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(saveButton);

    treeWidget = new QTreeWidget();
    treeWidget->setFixedWidth(wSize.width());
    treeWidget->addTopLevelItem(rootItem);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(treeWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(2);
    setFixedSize(wSize);
    setContextMenuPolicy(Qt::CustomContextMenu);


    treeWidget->setColumnCount(4);

    rootItem = new QTreeWidgetItem();
    rootItem->setIcon(0,QIcon(":/folder.png"));
    rootItem->setText(0,"root");
    rootItem->setText(1,"Object");
    rootItem->setText(2,"NA");
    rootItem->setText(3,"0 B");
    treeWidget->headerItem()->setText(0,"Name");
    treeWidget->headerItem()->setText(1,"Type");
    treeWidget->headerItem()->setText(2,"Format");
    treeWidget->headerItem()->setText(3,"Size");
    treeWidget->addTopLevelItem(rootItem);


    setWindowFlags(Qt::FramelessWindowHint);

}

void PacketEditor::setupConnections()
{
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),this, SLOT(slotShowContextMenu(const QPoint &)));

    connect(treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(slotEnableButtons()));
    connect(addButton,SIGNAL(clicked()),this,SLOT(slotShowAddMenus()));
    connect(addTypeAction,SIGNAL(triggered()),this,SLOT(slotCreateType()));
    connect(addArrayAction,SIGNAL(triggered()),this,SLOT(slotCreateArray()));
    connect(addObjectAction,SIGNAL(triggered()),this,SLOT(slotCreateObject()));
    connect(deleteAction,SIGNAL(triggered()),this,SLOT(slotDelete()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(slotDelete()));

    connect(dataTypeDialog,SIGNAL(sigData(TypeObject)),this,SLOT(slotHandleDataType(TypeObject)));
    connect(objectDialog,SIGNAL(sigData(Object)),this,SLOT(slotHandleObjectType(Object)));
    connect(arrayDialog,SIGNAL(sigData(ArrayTypeObject)),this,SLOT(slotHandleArrayType(ArrayTypeObject)));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(slotSave()));

}

void PacketEditor::slotEnableButtons()
{
    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QVariant variant=itemsSelected.at(0)->data(1,Qt::DisplayRole);
        bool addEnabled=variant.value<QString>()== "Object";
        addButton->setEnabled(addEnabled);
        QVariant name=itemsSelected.at(0)->data(0,Qt::DisplayRole);
        bool delEnabled=name.toString()!="root";
        deleteButton->setEnabled(delEnabled);

    }


}

void PacketEditor::slotShowAddMenus()
{
    slotShowContextMenu(addButton->pos());
}

void PacketEditor::initActions()
{
    addTypeAction = new QAction("New Type",this);
    addObjectAction = new QAction("New Object",this);
    addArrayAction = new QAction("New Array",this);
    deleteAction = new QAction("Delete",this);

}

void PacketEditor::recursiveDelete(QTreeWidgetItem *item)
{
    if(item)
    {
        for(int i=0;i<item->childCount();++i)
        {
            QTreeWidgetItem *childItem= item->child(i);
            recursiveDelete(childItem);
        }
        item->parent()->removeChild(item);
    }
}

void PacketEditor::updateDelete(QTreeWidgetItem *item, int size)
{
    QTreeWidgetItem *tempItem=item;
    while(1)
    {
        if(tempItem->text(1)=="Object")
        {
            qDebug()<<"object";
            QString sizeString = tempItem->text(3).split(" ")[0];
            int bytes=sizeString.toInt()-size;
            qDebug()<<bytes;
            sizeString = QString::number(bytes);
            qDebug()<<sizeString;
            tempItem->setText(3,sizeString+" B");
        }
        if(tempItem->text(0)=="root")
        {
            qDebug()<<"breaking";
            break;
        }
        tempItem=tempItem->parent();
    }

}

void PacketEditor::updateArrayChildren(QTreeWidgetItem *item)
{
    QString variableName=item->text(0);
    {
        if(item->childCount()==0)
        {
            item->parent()->removeChild(item);
        }
        else
        {
            for(int i=0;i<item->childCount();++i)
            {
                QTreeWidgetItem *child= item->child(i);
                QString arrayElementName=variableName+"["+QString::number(i)+"]";
                if(child->text(0)!=arrayElementName)
                    child->setText(0,arrayElementName);
            }
        }
    }
}

QString PacketEditor::saveToFile(QTreeWidgetItem *item)
{
    static QString text="";
    static QString indentation="";

    if(item)
    {
        QString variableName=item->text(0);
        QString typeName=item->text(1);
        QString format=item->text(2);
        QString size=item->text(3);

        text+=indentation+"<"+typeName+" name=\""+variableName+"\" format=\""+format+"\" size=\""+size+"\" >\n";
        indentation+=" ";
        for(int i=0;i<item->childCount();++i)
        {
            saveToFile(item->child(i));
        }
        indentation.remove(indentation.length()-1,1);
        text+=indentation+"</"+typeName+">\n";
    }
    return text;
}

QTreeWidgetItem* PacketEditor::isArrayElement(QTreeWidgetItem *item)
{
    QTreeWidgetItem *tempItem=item;
    QTreeWidgetItem *arrayObject=nullptr;
    while(1)
    {
        if(tempItem->text(1).endsWith("Array"))
        {
            arrayObject=tempItem;
            break;
        }
        if(tempItem->text(0)=="root")
            break;
        tempItem=tempItem->parent();
    }
    return arrayObject;
}

void PacketEditor::slotSave()
{
    qDebug()<<rootItem->text(0);
    QString text=saveToFile(rootItem);
    qDebug()<<text;
    if(file.isOpen())
        file.close();
    file.open(QFile::WriteOnly);
    if(file.isOpen())
    {
        int bytesWritten=file.write(text.toLatin1());

        if(bytesWritten>0)
            sigSnackBar("'"+treeWidget->topLevelItem(0)->text(0)+"' is saved",UIManager::Resources::NOTIFY_COLOR);
        else
            sigSnackBar("'"+treeWidget->topLevelItem(0)->text(0)+"' could not be saved",UIManager::Resources::ERROR_COLOR);
        file.close();
    }
    else
        sigSnackBar("'"+treeWidget->topLevelItem(0)->text(0)+"' could not be saved",UIManager::Resources::ERROR_COLOR);

}

void PacketEditor::slotDelete()
{
    QTreeWidgetItem *currentItem= treeWidget->currentItem();
    QVariant typeVariant=currentItem->data(1,Qt::DisplayRole);
    QVariant typeName=currentItem->data(0,Qt::DisplayRole);
    QString type=typeVariant.value<QString>();
    QString name=typeName.value<QString>();
    QTreeWidgetItem *parentItem=currentItem->parent();

    qDebug()<<name;
    if(name!="root")
    {
        if(type=="Object")
        {
            int size=currentItem->text(3).split(" ")[0].toInt();
            updateDelete(parentItem,size);
            recursiveDelete(currentItem);
            emit sigSnackBar("'"+name+"' of type '"+type+ "' is  deleted",UIManager::Resources::NOTIFY_COLOR);
        }
        else if(type.endsWith("Array"))
        {

            int size=currentItem->text(3).split(" ")[0].toInt();

            updateDelete(parentItem,size);

            for(int i=0;i<currentItem->childCount();++i)
            {
                QTreeWidgetItem *child=currentItem->child(i);
                currentItem->removeChild(child);
            }
            currentItem->parent()->removeChild(currentItem);
            emit sigSnackBar("'"+name+"' of type '"+type+ "' is  deleted",UIManager::Resources::NOTIFY_COLOR);

        }
        else
        {
            int size=currentItem->text(3).split(" ")[0].toInt();
            qDebug()<<"size to be deleted"<<size;
            QTreeWidgetItem *arrayObject=isArrayElement(currentItem);
            if(arrayObject)
            {
                int arraySize=arrayObject->text(3).split(" ")[0].toInt();
                arraySize-=size;
                arrayObject->setText(3,QString::number(arraySize)+" B");
                arrayObject->removeChild(currentItem);
            }
            else
            {
                qDebug()<<"not array";
                parentItem->removeChild(currentItem);
            }
            treeWidget->repaint();

            updateDelete(parentItem,size);

            if(arrayObject)
            {
                updateArrayChildren(arrayObject);
            }

            emit sigSnackBar("'"+name+"' of type '"+type+ "' is  deleted",UIManager::Resources::NOTIFY_COLOR);
            treeWidget->repaint();
        }
    }


}

void PacketEditor::slotHandleDataType(TypeObject typeObject)
{
    QTreeWidgetItem *currentItem= treeWidget->currentItem();
    QTreeWidgetItem *childItem= new QTreeWidgetItem();
    childItem->setIcon(0,QIcon(":/file.png"));
    childItem->setText(0,typeObject.getVariableName());
    childItem->setText(1,typeObject.getTypeName());
    childItem->setText(2,typeObject.getFormat());
    QString sizeInfo("");
    sizeInfo.append(QString::number(typeObject.getSize()));
    sizeInfo.append(" B");
    childItem->setText(3,sizeInfo);
    currentItem->addChild(childItem);

    QTreeWidgetItem *tempItem = currentItem;
    while(1)
    {
        if(tempItem->text(1)=="Object")
        {
            QString sizeString = tempItem->text(3).split(" ")[0];
            int bytes=sizeString.toInt()+typeObject.getSize();
            sizeString = QString::number(bytes);
            tempItem->setText(3,sizeString+" B");
        }
        if(tempItem->text(0)=="root")
            break;
        tempItem=tempItem->parent();

    }
    currentItem->setExpanded(true);
    emit sigSnackBar("Created Variable '"+typeObject.getVariableName()+"' of type '"+typeObject.getTypeName()+"'",QColor("#16a085"));



}

void PacketEditor::slotHandleObjectType(Object typeObject)
{
    qDebug()<<"Hello baby";
    QTreeWidgetItem *currentItem= treeWidget->currentItem();
    QTreeWidgetItem *childItem= new QTreeWidgetItem();
    childItem->setIcon(0,QIcon(":/folder.png"));
    childItem->setText(0,typeObject.getVariableName());
    childItem->setText(1,typeObject.getTypeName());
    childItem->setText(2,"NA");
    QString sizeInfo("");
    sizeInfo.append(QString::number(typeObject.getSize()));
    sizeInfo.append(" B");
    childItem->setText(3,sizeInfo);
    currentItem->addChild(childItem);
    currentItem->setExpanded(true);

    emit sigSnackBar("Created  Variable '"+typeObject.getVariableName()+"' of type '"+typeObject.getTypeName()+"'",QColor("#16a085"));



}

void PacketEditor::slotHandleArrayType(ArrayTypeObject typeObject)
{
    QTreeWidgetItem *currentItem= treeWidget->currentItem();

    QTreeWidgetItem *arrayObject = new QTreeWidgetItem();
    currentItem->addChild(arrayObject);
    arrayObject->setIcon(0,QIcon(":/file.png"));
    arrayObject->setText(0,typeObject.getVariableName());
    arrayObject->setText(1,typeObject.getTypeName()+"Array");
    arrayObject->setText(2,typeObject.getFormat());
    arrayObject->setText(3,QString::number(typeObject.getIndices()*typeObject.getSize()));
    QString sizeString;
    int bytes=typeObject.getSize()*typeObject.getIndices();
    sizeString = QString::number(bytes);
    arrayObject->setText(3,sizeString+" B");
    qDebug()<<"here";

    for(int i=0;i<typeObject.getIndices();++i)
    {
        QTreeWidgetItem *childItem= new QTreeWidgetItem();
        childItem->setIcon(0,QIcon(":/file.png"));
        childItem->setText(0,typeObject.getVariableName()+"["+QString::number(i)+"]");
        childItem->setText(1,typeObject.getTypeName());
        childItem->setText(2,typeObject.getFormat());
        QString sizeInfo("");
        sizeInfo.append(QString::number(typeObject.getSize()));
        sizeInfo.append(" B");
        childItem->setText(3,sizeInfo);
        arrayObject->addChild(childItem);
    }

    QTreeWidgetItem *tempItem = arrayObject;
    while(1)
    {
        qDebug()<<"received";

        if(tempItem->text(1)=="Object")
        {
            QString sizeString = tempItem->text(3).split(" ")[0];
            int bytes=sizeString.toInt()+typeObject.getSize()*typeObject.getIndices();
            sizeString = QString::number(bytes);
            tempItem->setText(3,sizeString+" B");
        }
        if(tempItem->text(0)=="root")
            break;
        tempItem=tempItem->parent();

    }
    currentItem->setExpanded(true);
    arrayObject->setExpanded(true);
    emit sigSnackBar("Created Array Variable '"+typeObject.getVariableName()+"' of type '"+typeObject.getTypeName()+"'",QColor("#16a085"));


}

void PacketEditor::applyStyle()
{
    treeWidget->setStyleSheet("QFrame{background:#ecf0f1}");

}

void PacketEditor::slotShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QTreeWidgetItem *item=itemsSelected.at(0);
        QVariant variantName=item->data(0,Qt::DisplayRole);
        QVariant variantType=item->data(1,Qt::DisplayRole);

        QString name=variantName.value<QString>();
        QString type=variantType.value<QString>();

        if(!type.endsWith("Array"))
        {
            if(type=="Object"){
                contextMenu.addAction(addTypeAction);
                contextMenu.addAction(addObjectAction);
                contextMenu.addAction(addArrayAction);
            }
        }

        if(QObject::sender()!=addButton && name!="root")

            contextMenu.addAction(deleteAction);

        contextMenu.exec(mapToGlobal(pos));
    }

}

void PacketEditor::slotCreateArray()
{

    arrayDialog->exec();
}

void PacketEditor::slotCreateObject()
{
    objectDialog->exec();
}

void PacketEditor::slotCreateType()
{
    dataTypeDialog->exec();
}


void PacketEditor::populateTree()
{
    bool parsed=domDocument.setContent(file.readAll());
    if(parsed)
    {
        emit sigSnackBar("File content parsable",UIManager::Resources::NOTIFY_COLOR);
        createTree(domDocument.firstChild(),rootItem);

    }
    else
    {
        //        domDocument
    }

}

void PacketEditor::createTree(QDomNode node, QTreeWidgetItem *item)
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

void PacketEditor::slotEditPacket(QTreeWidgetItem *item, int column)
{
    int colWidth=treeWidget->width()/4;
    treeWidget->setColumnWidth(0,colWidth);
    treeWidget->setColumnWidth(1,colWidth);
    treeWidget->setColumnWidth(2,colWidth);
    treeWidget->setColumnWidth(3,colWidth);

    QVariant variant=item->data(2,Qt::DisplayRole);
    QString type=variant.value<QString>();
    QString fullName;
    QTreeWidgetItem *temp;
    temp=item;

    while(temp->text(0)!="Packets")
    {
        fullName.prepend("/"+temp->text(0));
        temp=temp->parent();
    }
    fullName.prepend("Packets");

    file.setFileName(fullName);
    bool opened=file.open(QFile::ReadWrite);
    if(opened)
    {
        sigSnackBar("File "+fullName+" is opened",UIManager::Resources::NOTIFY_COLOR);
        treeWidget->topLevelItem(0)->setText(0,fullName);
        if(file.size()>0)
        {
            qDebug()<<"file size>0";
            populateTree();
        }
    }
    else
        sigSnackBar("File "+fullName+" could not be opened",UIManager::Resources::ERROR_COLOR);


}
