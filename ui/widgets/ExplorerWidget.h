#ifndef EXPLORERWIDGET_H
#define EXPLORERWIDGET_H
#include "Widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QPoint>
#include "NameEntryDialog.h"
#include <QMap>
#include <QPoint>
#include <QScrollArea>
#include <QFileInfo>
#include <QTreeWidget>
#include "Worker.h"

class ExplorerWidget : public Widget
{
    Q_OBJECT


public:
    explicit ExplorerWidget(Worker *worker,QWidget *parent=nullptr);
    ~ExplorerWidget();

    // Widget interface
private:
    QString rootFolderName;
    QString fileString;
    QString folderString;
    Worker *worker;
    QTreeWidget *treeWidget;
    NameEntryDialog *nameEntryDialog;
    QAction *addFileAction;
    QAction *addFolderAction;
    QAction *deleteAction;
    QAction *captureAction;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *captureButton;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;

    void init() override;
    void setUpConnections() override;
    void applyStyle() override;
    void initActions();
    void populateTree();
    bool clearFolder(const QString &folder);
    QTreeWidgetItem* createFileEntry(QTreeWidgetItem *parentItem,QFileInfo fileInfo);
    QTreeWidgetItem* createFolderEntry(QTreeWidgetItem *parentItem,QFileInfo fileInfo,int count);

signals:
    void sigSnackBar(QString,QColor color);
    void sigEditPacket(QTreeWidgetItem *item,int column);
    void sigCapture();

private slots:
    void slotShowContextMenu(const QPoint &pos);
    void slotAddFile();
    void slotShowAddMenu();
    void slotAddFolder();
    void slotDelete();
    void slotCreateFile(QString name);
    void slotEnableButtons();
    void slotEditPacket(QTreeWidgetItem *item,int column);
    void slotCapture();




};

#endif // EXPLORERWIDGET_H
