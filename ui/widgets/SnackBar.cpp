#include "SnackBar.h"
#include "UIManager.h"
void SnackBar::setCounter(int value)
{
    counter = value;
}

SnackBar::SnackBar(QWidget *parent):Widget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    init();
    setUpConnections();
    applyStyle();
}


void SnackBar::init()
{
    mainLayout = new QVBoxLayout(this);
    iconButton = new QPushButton();
    iconButton->setFixedHeight(UIManager::Size::snackSize.height());
    mainLayout->addWidget(iconButton);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    displayTimer = new QTimer(this);
    setCounter(0);
    hide();

}

void SnackBar::setUpConnections()
{
    connect(displayTimer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
}

void SnackBar::applyStyle()
{
    iconButton->setStyleSheet("QPushButton{color:white;background:#95a5a6;border:none}");
}

void SnackBar::slotSetText(QString string,QColor color)
{
//    QWidget *parent = parentWidget();
//    if(parent)
//    {
//        move(parent->pos());
//    }
    if(color==UIManager::Resources::NOTIFY_COLOR)
    {
        iconButton->setIcon(QIcon(UIManager::Resources::TICK_ICON));
        iconButton->setStyleSheet("QPushButton{color:white;background:#27ae60;border:none}");

    }
    else
    {
        iconButton->setIcon(QIcon(UIManager::Resources::INFO_ICON));
        iconButton->setStyleSheet("QPushButton{color:white;background:#c0392b;border:none}");

    }
    iconButton->setText(string);
    setCounter(0);
    if(!isVisible())
    {
        show();
    }
    raise();
    if(!displayTimer->isActive()){
        displayTimer->start(1000);
    }
    repaint();


}

void SnackBar::slotTimeout()
{
    counter+=1;
    if(counter==5){
        hide();
        displayTimer->stop();
    }
}
