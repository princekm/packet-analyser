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
#include <QToolButton>
#include <QStringList>
class MainScreen :public Widget
{
    Q_OBJECT
public:
    explicit MainScreen(Worker *worker,QWidget *parent=nullptr);
    ~MainScreen();

    // Widget interface
private:
    QStringList menuList;
    QToolButton *toolButton;
    SnackBar *snackBar;
    QToolButton *closeButton;
    QLabel *heading;
    Worker *worker;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    SettingsWidget *settingsWidget;
    ExplorerWidget *explorerWidget;
    PacketEditor *packetEditorWidget;
    CaptureWidget *captureWidget;

    void init() override;
    void setUpConnections() override;
    void applyStyle() override;
signals:
    void sigSnackBar(QString info,QColor color);
private slots:
    void slotCloseApp();

    void slotInterfaceNameNotify(QString interfaceName);
    void slotEndiannessNotify(QString interfaceName);
    void slotAddEditorTab();
    void slotRemoveEditorTab();
    void slotAddCapturesTab();
    void slotRemoveCapturesTab();
    void slotProcessWorkerInfo(QString message,Worker::MessageType type);
};

#endif // MAINSCREEN_H
