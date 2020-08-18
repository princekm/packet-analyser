#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "Widget.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include "SettingsWidget.h"
#include "ExplorerWidget.h"
#include "Worker.h"
#include "SnackBar.h"
#include "PacketEditor.h"
#include "CaptureWidget.h"
#include "InspectorWidget.h"
#include <QToolButton>
#include <QStringList>
#include <QDial>
#include <QProgressBar>
class MainScreen :public Widget
{
    Q_OBJECT
public:
    explicit MainScreen(Worker *worker,QWidget *parent=nullptr);
    ~MainScreen();

    // Widget interface
private:
    QLabel *heading;
    QProgressBar *indicator;
    QStringList menuList;
    SnackBar *snackBar;
    Worker *worker;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    SettingsWidget *settingsWidget;
    ExplorerWidget *explorerWidget;
    PacketEditor *packetEditorWidget;
    CaptureWidget *captureWidget;
    InspectorWidget *inspectorWidget;

    void init() override;
    void setUpConnections() override;
    void applyStyle() override;

signals:
    void sigSnackBar(QString info,QColor color);
    void sigConnected();

private slots:

    void slotInspect(bool turnOn);
    void slotRotateDial();
    void slotCloseApp();
    void slotInterfaceNameNotify(QString interfaceName);
    void slotAddEditorTab();
    void slotRemoveEditorTab();
    void slotAddCapturesTab();
    void slotGotoInspectorTab();
    void slotRemoveInspectorTab();
    void slotEnable(bool enable);

    void slotRemoveCapturesTab();
    void slotProcessWorkerInfo(QString message,Worker::MessageType type);
};

#endif // MAINSCREEN_H
