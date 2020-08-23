#ifndef MENUBAR_H
#define MENUBAR_H
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "NameEntryDialog.h"

class MenuBar : public QMenuBar
{
    Q_OBJECT
private:
    NameEntryDialog *nameDialog;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *quitAction;
    QAction *saveAction;
    QAction *aboutAction;
signals:
    void sigShowAboutDialog();
    void sigSaveFile(QString fileName);
    void sigSnackBar(QString message,QColor color);
public:
    MenuBar(QWidget *parent=nullptr);
    ~MenuBar();
    void init();
    void setUpConnections();
    void applyStyle();
public slots:
    void slotEnableSave(bool enable);
    void slotSaveFile(QString fileName);

};

#endif // MENUBAR_H
