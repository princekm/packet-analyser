#include "MenuBar.h"
#include <QApplication>
#include "UIManager.h"
MenuBar::MenuBar(QWidget *parent):QMenuBar(parent)
{
    init();
    setUpConnections();
    applyStyle();
}

MenuBar::~MenuBar()
{

}

void MenuBar::init()
{
    nameDialog = new NameEntryDialog;
    nameDialog->hide();
    fileMenu = new QMenu("File");
    helpMenu = new QMenu("Help");
    quitAction = new QAction("Quit");
    saveAction = new QAction("Save");
    aboutAction = new QAction("About");
    addMenu(fileMenu);
    addMenu(helpMenu);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);
    helpMenu->addAction(aboutAction);
    slotEnableSave(false);

}

void MenuBar::setUpConnections()
{
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));
    connect(aboutAction,SIGNAL(triggered()),this,SIGNAL(sigShowAboutDialog()));
    connect(saveAction,SIGNAL(triggered()),nameDialog,SLOT(exec()));
    connect(nameDialog,SIGNAL(sigName(QString)),this,SLOT(slotSaveFile(QString)));
}

void MenuBar::applyStyle()
{

}

void MenuBar::slotEnableSave(bool enable)
{
  saveAction->setEnabled(enable);
}

void MenuBar::slotSaveFile(QString fileName)
{
    if(fileName.isEmpty())
    {
        emit sigSnackBar("Empty File Name",UIManager::Resources::ERROR_COLOR);
    }
    else
    {
        emit sigSaveFile(fileName);
    }
}
