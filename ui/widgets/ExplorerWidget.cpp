#include "ExplorerWidget.h"
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QDir>
#include <QScrollArea>
#include <QDebug>
#include <QFile>
#include "Worker.h"
#include "UIManager.h"
ExplorerWidget::~ExplorerWidget()
{

}



ExplorerWidget::ExplorerWidget(Worker *worker, QWidget *parent)
{
    this->worker=worker;
    init();
    setUpConnections();
    applyStyle();
    populateTree();
}


void ExplorerWidget::init()
{


    rootFolderName="Packets";
    rootItem = new QTreeWidgetItem();
    rootItem->setIcon(0,QIcon(UIManager::Resources::FOLDER_ICON));
    rootItem->setText(0,rootFolderName);
    fileString = "File";
    folderString = "Folder";
    treeWidget = new QTreeWidget;
    treeWidget->setFixedWidth(UIManager::Size::windowSize.width());
    nameEntryDialog = new NameEntryDialog();
    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("Delete");
    captureButton = new QPushButton("Capture");
    deleteButton->setDisabled(true);
    captureButton->setDisabled(true);
    addButton->setDisabled(true);
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(captureButton);
    mainLayout = new QVBoxLayout(this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    initActions();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(treeWidget,Qt::AlignCenter);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(10);



}

void ExplorerWidget::slotShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QTreeWidgetItem *parentItem=itemsSelected.at(0);
        QVariant variant=parentItem->data(2,Qt::DisplayRole);

        QString type=variant.value<QString>();

        if(type==folderString)
        {
            contextMenu.addAction(addFileAction);
            if(parentItem == treeWidget->topLevelItem(0))
                contextMenu.addAction(addFolderAction);
            else if(QObject::sender()!=addButton)
                contextMenu.addAction(deleteAction);
        }
        contextMenu.addAction(captureAction);
        contextMenu.exec(mapToGlobal(pos));
    }

}

void ExplorerWidget::slotAddFile()
{
    nameEntryDialog->setType(EntryType::FILE_TYPE);
    nameEntryDialog->exec();
}

void ExplorerWidget::slotShowAddMenu()
{
    slotShowContextMenu(addButton->pos());
}

void ExplorerWidget::slotAddFolder()
{
    nameEntryDialog->setType(EntryType::FOLDER_TYPE);
    nameEntryDialog->exec();

}

bool ExplorerWidget::clearFolder(const QString &folder)
{
    bool deleted=true;
    QDir dir(folder);
    QFileInfoList infoList = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    foreach (QFileInfo fileInfo, infoList) {

        if (fileInfo.isFile())
        {
            emit sigFileDeleted(fileInfo.filePath());
            deleted&=QFile::remove(fileInfo.filePath());

        }
        else if (fileInfo.isDir())
            return clearFolder(fileInfo.filePath());
    }
    deleted&=dir.rmdir(dir.absolutePath());
    return deleted;
}

QString ExplorerWidget::getSelectedItemType(QTreeWidgetItem *item)
{
    QString string=item->text(2);
    return  string;
}

QString ExplorerWidget::getFullName(QTreeWidgetItem *widgetItem)
{
    if(widgetItem)
    {
        QString name=widgetItem->text(0);
        QString fileType=widgetItem->text(2);
        QString path=name.prepend(getFullName(widgetItem->parent()));
        if(fileType!=fileString)
            path.append("/");
        return path;
    }
    return "";
}
void ExplorerWidget::slotDelete()
{
    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QTreeWidgetItem *selectedItem=itemsSelected.at(0);
        QVariant variant=selectedItem->data(2,Qt::DisplayRole);
        QString type=variant.value<QString>();
        QString fullName;
        fullName=getFullName(selectedItem);
        if(type==folderString)
        {
            QDir dir(fullName);
            QFileInfoList list = dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
            if(dir.exists()){
                if(clearFolder(fullName))
                {
                    emit  sigSnackBar("'"+fullName + "' is deleted",UIManager::Resources::NOTIFY_COLOR);
                    selectedItem->parent()->removeChild(selectedItem);
                    treeWidget->repaint();
                }
                else

                    emit  sigSnackBar("'"+fullName + "' could not be deleted",UIManager::Resources::ERROR_COLOR);
            }
        }
        else if(type == fileString)
        {
            bool deleted=QFile::remove(fullName);
            if(deleted)
            {
                emit sigSnackBar("'"+fullName + "' is deleted",UIManager::Resources::NOTIFY_COLOR);
                emit sigFileDeleted(getFullName(selectedItem));
                selectedItem->parent()->removeChild(selectedItem);
            }
            else
                emit sigSnackBar("'"+fullName + "' could not be deleted",UIManager::Resources::ERROR_COLOR);


        }
    }
}


void ExplorerWidget::slotCreateFile(QString name)
{

    nameEntryDialog->getType();

    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QTreeWidgetItem *parentItem=itemsSelected.at(0);
        QVariant variant=parentItem->data(2,Qt::DisplayRole);
        QString type=variant.value<QString>();
        QString fullName=getFullName(parentItem);

        if(nameEntryDialog->getType()==EntryType::FILE_TYPE)
        {
            QFile file(fullName+"/"+name+UIManager::Resources::FILE_EXTENSION);
            bool opened=file.open(QFile::WriteOnly);
            if(opened){

                file.write(QByteArray());
                QFileInfo fileInfo(file);
                createFileEntry(itemsSelected.at(0),fileInfo);
                file.close();
                emit sigSnackBar("File '"+name+"' created successfully",UIManager::Resources::NOTIFY_COLOR);
                parentItem->setExpanded(true);
            }
        }
        else if(nameEntryDialog->getType()==EntryType::FOLDER_TYPE)
        {
            QVariant variant=parentItem->data(0,Qt::DisplayRole);
            QString dirName = variant.value<QString>();
            QDir dir(fullName);
            bool created=dir.mkdir(name);
            if(created)
            {
                createFolderEntry(itemsSelected.at(0),name,0);
                emit sigSnackBar("Folder '"+name+"' created successfully",UIManager::Resources::NOTIFY_COLOR);
                parentItem->setExpanded(true);
            }
        }

    }

    nameEntryDialog->setType(EntryType::NONE_TYPE);

}

void ExplorerWidget::slotEnableButtons()
{
    QList<QTreeWidgetItem*> itemsSelected=treeWidget->selectedItems();

    if(itemsSelected.count()==1)
    {
        QVariant variant=itemsSelected.at(0)->data(2,Qt::DisplayRole);
        if(variant.value<QString>()== folderString)
        {
            addButton->setEnabled(true);
        }
        else
        {
            addButton->setEnabled(false);
        }
        bool delAndCapEnabled=treeWidget->topLevelItem(0)!=itemsSelected.at(0);
        captureButton->setEnabled(true);
        deleteButton->setEnabled(delAndCapEnabled);
    }


}

void ExplorerWidget::slotEditPacket(QTreeWidgetItem *item, int column)
{
    QVariant variant=item->data(2,Qt::DisplayRole);
    if(variant.value<QString>()== fileString)
    {
        emit sigEditPacket(item,column);
    }
}

void ExplorerWidget::slotCapture()
{
    QTreeWidgetItem *item=treeWidget->selectedItems().at(0);
    QString filetypeString=getSelectedItemType(item);
    qDebug()<<filetypeString;
    if(filetypeString==fileString)
    {
        emit sigCapture();
        emit sigAddCapturePacket(getFullName(treeWidget->selectedItems().at(0)));
    }

}

void ExplorerWidget::slotUpdateFileSize(int size)
{
    treeWidget->selectedItems().at(0)->setText(1,"Size:"+QString::number(size)+" B");
}

void ExplorerWidget::setUpConnections()
{
    connect(addButton, SIGNAL(clicked()),this, SLOT(slotShowAddMenu()));
    connect(addFileAction, SIGNAL(triggered()), this, SLOT(slotAddFile()));
    connect(addFolderAction, SIGNAL(triggered()), this, SLOT(slotAddFolder()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(slotDelete()));
    connect(captureAction, SIGNAL(triggered()), this, SLOT(slotCapture()));

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(slotDelete()));
    connect(captureButton, SIGNAL(clicked()),this ,SLOT(slotCapture()));

    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),this, SLOT(slotShowContextMenu(const QPoint &)));

    connect(nameEntryDialog, SIGNAL(sigName(QString)), this, SLOT(slotCreateFile(QString)));
    connect(treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(slotEnableButtons()));
    connect(treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int )),this,SLOT(slotEditPacket(QTreeWidgetItem *, int)));

}

void ExplorerWidget::applyStyle()
{
    treeWidget->setStyleSheet("QFrame{background:#ecf0f1;}");
    setStyleSheet("QFrame{background:grey}");

}

void ExplorerWidget::initActions()
{
    addFileAction = new QAction("New File",this);
    addFolderAction = new QAction("New Folder",this);
    deleteAction = new QAction("Delete",this);
    captureAction = new QAction("Capture",this);
}

void ExplorerWidget::populateTree()
{
    treeWidget->setColumnCount(3);
    treeWidget->addTopLevelItem(rootItem);
    treeWidget->headerItem()->setText(0,"Name");
    treeWidget->headerItem()->setText(1,"Details");
    treeWidget->headerItem()->setText(2,"Type");
    QDir dir(rootFolderName);
    int colWidth=treeWidget->width()/3;
    treeWidget->setColumnWidth(0,colWidth);
    treeWidget->setColumnWidth(1,colWidth);
    treeWidget->setColumnWidth(2,colWidth);
    rootItem->setExpanded(true);
    if(dir.exists()){
        QFileInfoList list = dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
        rootItem->setText(1,"Items:"+QString::number(list.count()));
        rootItem->setText(2,folderString);
        for (int i = 0; i < list.count(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isDir())
            {
                QDir dir(fileInfo.absoluteFilePath());
                if(dir.exists())
                {
                    QFileInfoList innerList = dir.entryInfoList(QStringList()<<"*"+UIManager::Resources::FILE_EXTENSION,QDir::Files|QDir::NoDotAndDotDot);
                    QTreeWidgetItem *parentItem= createFolderEntry(rootItem,fileInfo.fileName(),innerList.count());
                    for (int j= 0; j < innerList.count(); ++j)
                    {
                        QFileInfo fileInfo = innerList.at(j);
                        if(fileInfo.isFile())
                            createFileEntry(parentItem,fileInfo.absoluteFilePath());
                    }
                }
                else
                {
                }

            }
            else if(fileInfo.fileName().endsWith(UIManager::Resources::FILE_EXTENSION))
            {
                createFileEntry(rootItem,fileInfo. absoluteFilePath());

            }
        }
    }
}

QTreeWidgetItem* ExplorerWidget::createFileEntry(QTreeWidgetItem *parentItem,QFileInfo fileInfo )
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,fileInfo.fileName());
    item->setIcon(0,QIcon(UIManager::Resources::FILE_ICON));
    item->setText(1,"Size:"+QString::number(fileInfo.size())+" B");
    item->setText(2,fileString);
    parentItem->addChild(item);
    emit sigFileAdded(getFullName(item));
    return item;

}

QTreeWidgetItem* ExplorerWidget::createFolderEntry(QTreeWidgetItem *parentItem, QFileInfo fileInfo,int count)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,fileInfo.fileName());
    item->setIcon(0,QIcon(UIManager::Resources::FOLDER_ICON));
    item->setText(1,"Files:"+QString::number(count));
    item->setText(2,folderString);
    parentItem->addChild(item);
    return  item;

}

