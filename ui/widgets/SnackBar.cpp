#include "SnackBar.h"

void SnackBar::setCounter(int value)
{
    counter = value;
}

SnackBar::SnackBar(QWidget *parent):Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();
}


void SnackBar::init()
{
    mainLayout = new QHBoxLayout(this);
    infoText = new QLabel("");
    infoText->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(infoText);
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
    infoText->setStyleSheet("QLabel{color:white;background:blue}");
}

void SnackBar::slotSetText(QString string,QColor color)
{
    infoText->setText(string);
    infoText->setStyleSheet("QLabel{color:white;background:"+color.name()+"}");
    setCounter(0);
    if(!isVisible())
    {
        show();
    }
    raise();
    if(!displayTimer->isActive()){
        displayTimer->start(1000);
    }


}

void SnackBar::slotTimeout()
{
    counter+=1;
    if(counter==5){
        hide();
        displayTimer->stop();
    }
}
