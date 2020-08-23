#ifndef INSPECTORWIDGET_H
#define INSPECTORWIDGET_H
#include "Widget.h"
#include "FormatDialog.h"
#include <QComboBox>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QTreeWidgetItem>
#include <QDomDocument>
#include <QPushButton>
#include <QFile>

class InspectorWidget : public Widget
{
    Q_OBJECT
public:
    explicit InspectorWidget(QWidget *parent=nullptr);

    // Widget interface
private:
    QFile file;
    QStringList columnNames;
    QLabel *selectLabel;
    QComboBox *packetTypeBox;
    QComboBox *endiannessBox;
    QTreeWidget *packetTree;
    QVBoxLayout *mainLayout;
    QHBoxLayout *selectionLayout;
    QTreeWidgetItem *rootItem;
    QTreeWidgetItem *doubleClickedItem;
    QDomDocument domDocument;
    QPushButton *startStopButton;
    QLabel *countLabel;
    QLabel *byteOrderLabel;
    FormatDialog *formatDialog;
    void init();
    void initTree();
    void incrementTotalCount();
    void resetCount();
    void setUpConnections();
    void applyStyle();
    void populateTree();
    void fillValue();
    void createTree(QDomNode node,QTreeWidgetItem *item);
    void loadPacketTypes();
    void populateValues(uchar *data,int offset,QTreeWidgetItem *item);
    void clearValues(QTreeWidgetItem *item);

    void removeAllChildren(QTreeWidgetItem *item);
signals:
    void sigInspect(bool turnOn);
    void sigRequestFileList();
    void sigSnackBar(QString,QColor);
private slots:
    void slotAddPacketTypes(QString packetType);
    void slotNotifyEndianness(QString);
    void slotDeletePacketTypes(QString packetType);
    void slotPopulateTree(QString fileName);
    void slotUpdateFileList(QStringList fileList);
    void slotPayload(uchar *data,int len);
    void slotStartStop();
    void slotDisable(bool);
    void slotItemDoubleClicked(QTreeWidgetItem *item, int column);
    void slotChangeFormat(QString format);

};

#endif // INSPECTORWIDGET_H
