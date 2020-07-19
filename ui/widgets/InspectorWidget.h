#ifndef INSPECTORWIDGET_H
#define INSPECTORWIDGET_H
#include "Widget.h"
#include <QComboBox>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QTreeWidgetItem>

class InspectorWidget : public Widget
{
    Q_OBJECT
public:
    explicit InspectorWidget(QWidget *parent=nullptr);

    // Widget interface
private:
    QStringList columnNames;
    QLabel *selectLabel;
    QComboBox *packetTypeBox;
    QTreeWidget *packetTree;
    QVBoxLayout *mainLayout;
    QHBoxLayout *selectionLayout;
    QTreeWidgetItem *rootItem;

    void init();
    void initTree();
    void setUpConnections();
    void applyStyle();
private slots:
    void slotAddPacketTypes(QString packetType);
    void slotDeletePacketTypes(QString packetType);
    void slotPopulateTree(QString fileName);
};

#endif // INSPECTORWIDGET_H
