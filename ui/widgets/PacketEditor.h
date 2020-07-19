#ifndef PACKETDIALOG_H
#define PACKETDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "Widget.h"
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QAction>
#include <QPoint>
#include "DataTypeDialog.h"
#include "ArrayDialog.h"
#include "ObjectTypeDialog.h"
#include <QFile>
#include <QDomDocument>

class PacketEditor : public Widget
{
    Q_OBJECT
public:
    PacketEditor(QWidget *parent=nullptr);
private:
    QFile file;
    QDomDocument domDocument;
    QTreeWidget *treeWidget;
    QTreeWidgetItem *rootItem ;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QAction *addObjectAction;
    QAction *addTypeAction;
    QAction *addArrayAction;
    QAction *deleteAction;

    ObjectTypeDialog *dataTypeDialog;
    ObjectTypeDialog *arrayDialog;
    ObjectTypeDialog *objectDialog;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    void init();
    void setupConnections();
    void applyStyle();
    void populateTree();
    void createTree(QDomNode node,QTreeWidgetItem *item);
    void initActions();
    void recursiveDelete(QTreeWidgetItem *item);
    void updateDelete(QTreeWidgetItem *item,int size);
    QTreeWidgetItem* isArrayElement(QTreeWidgetItem *item);
    void updateArrayChildren(QTreeWidgetItem *item);
    QString  saveToFile(QTreeWidgetItem *item);
signals:
    void sigSnackBar(QString string,QColor color);
private slots:
    void slotSave();


    void slotDelete();
    void slotHandleDataType(TypeObject typeObject);
    void slotHandleObjectType(Object typeObject);
    void slotHandleArrayType(ArrayTypeObject typeObject);
    void slotEditPacket(QTreeWidgetItem *item,int column);
    void slotEnableButtons();
    void slotShowAddMenus();
    void slotShowContextMenu(const QPoint &pos);
    void slotCreateArray();
    void slotCreateObject();
    void slotCreateType();



};

#endif // PACKETDIALOG_H
