#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include "Widget.h"
#include "Worker.h"
class UIManager : public QObject
{
    Q_OBJECT
private:
    Worker *worker;
    Widget *startScreen;
    Widget *mainScreen;
    void init();
    void setupConnections();
    void start();

public:
    class Size
    {
    public:
        static const int WIDGET_HEIGHT;
        static const QSize windowSize;
        static const QSize headingSize;
        static const QSize snackSize;
        static const QSize frameSize;
        static const QSize nameDialogSize;
        static const QSize typeDialogSize;
        static const QSize arrayDialogSize;
        static const QSize objectDialogSize;

    };
    class Resources
    {
    public:
        static const QString FOLDER_ICON;
        static const QString FILE_ICON;
        static const QString CLOSE_ICON;
        static const QString APP_ICON;
        static const QString ADD_ICON;
        static const QString DELETE_ICON;
        static const QString INFO_ICON;
        static const QString TICK_ICON;
        static const QString CAPTURE_ICON;
        static const QString SAVE_ICON;
        static const QString START_ICON;
        static const QString STOP_ICON;
        static const QString BOX_ICON;
        static const QString CLEAR_ICON;
        static const QString EDIT_ICON;
        static const QString VIEW_ICON;
        static const QString FILTER_ICON;

        static const QString FILE_EXTENSION;
        static const QColor NOTIFY_COLOR;
        static const QColor ERROR_COLOR;

    };
    explicit UIManager(Worker *worker,QObject *parent = nullptr);
    ~UIManager();

signals:
private slots:
    void slotReady();

};

#endif // UIMANAGER_H
