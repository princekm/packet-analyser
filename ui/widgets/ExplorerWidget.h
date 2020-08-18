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
    QTreeWidgetItem *rootItem;
    void init() override;
    void setUpConnections() override;
    void applyStyle() override;
    void initActions();
    void populateTree();
    bool clearFolder(const QString &folder);
    QString getSelectedItemType(QTreeWidgetItem *item);
    QString getFullName(QTreeWidgetItem *widgetItem);
    QTreeWidgetItem* createFileEntry(QTreeWidgetItem *parentItem,QFileInfo fileInfo);
    QTreeWidgetItem* createFolderEntry(QTreeWidgetItem *parentItem,QFileInfo fileInfo,int count);

signals:
    void sigSnackBar(QString,QColor color);
    void sigEditPacket(QTreeWidgetItem *item,int column);
    void sigAddCapturePacket(QString fileName);
    void sigFileAdded(QString name);
    void sigFileDeleted(QString name);
    void sigEmitFileList(QStringList fileList);
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
    void slotUpdateFileSize(int size);
    void slotHandleRequestFileList();




};

#endif // EXPLORERWIDGET_H
