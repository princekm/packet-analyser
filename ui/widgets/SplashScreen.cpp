#include "SplashScreen.h"
#include <QDebug>
#include "Worker.h"
#include <QPainter>
#include <QApplication>
#include "UIManager.h"
SplashScreen::SplashScreen(QWidget *parent) : Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();

}
void SplashScreen::init()
{
    QSize wSize(UIManager::Size::windowSize);
    mainLayout = new QVBoxLayout(this);
    label = new QLabel(qApp->objectName());
    label->setAlignment(Qt::AlignCenter);
    progressBar = new QProgressBar();
    progressBar->setRange(0,100);
    setFixedSize(wSize);
    mainLayout->addWidget(label);
    mainLayout->addWidget(progressBar);
    setWindowFlags(Qt::FramelessWindowHint);

}


void SplashScreen::setUpConnections()
{

}

void SplashScreen::applyStyle()
{
    QFont f = label->font();
    f.setFamily("Monaco");
    f.setPointSize(20);
    label->setFont(f);
    label->setStyleSheet("QLabel{color:#2c3e50;}");

}

void SplashScreen::slotProgress(int percentage)
{
    progressBar->setValue(percentage);
    if(percentage==100)
        emit sigNext();
}


void SplashScreen::paintEvent(QPaintEvent *event)
{
    Widget::paintEvent(event);
    QPainter painter(this);
    QPixmap pixmap(UIManager::Resources::APP_ICON);
    painter.drawPixmap(0,0,width()/4,height()/4, pixmap);
}
