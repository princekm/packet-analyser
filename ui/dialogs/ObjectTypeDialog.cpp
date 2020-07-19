#include "ObjectTypeDialog.h"
#include "Worker.h"
#include <QDebug>
#include "UIManager.h"
ObjectTypeDialog::ObjectTypeDialog(QWidget *parent):QDialog(parent)
{

}
void ObjectTypeDialog::build()
{
    init();
    setupConnections();
    applyStyle();
    hide();
}

void ObjectTypeDialog::init()
{

    QSize wSize(UIManager::Size::objectDialogSize);
    setFixedSize(wSize);
    variableEdit = new QLineEdit();
    variableEdit->setAttribute(Qt::WA_MacShowFocusRect, 0);
    label = new QLabel("Variable Name");
    label->setAlignment(Qt::AlignCenter);
    okButton = new QPushButton("OK");
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(label);
    mainLayout->addWidget(variableEdit);
    mainLayout->addWidget(okButton);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setWindowFlags(Qt::FramelessWindowHint);

}

void ObjectTypeDialog::setupConnections()
{
    connect(okButton,SIGNAL(clicked()),this,SLOT(slotProcessOk()));

}

void ObjectTypeDialog::applyStyle()
{
    label->setStyleSheet("QLabel{background:#2980b9;color:white}");

}

void ObjectTypeDialog::slotProcessOk()
{
    if(!variableEdit->text().isEmpty())
    {
        Object object(variableEdit->text(),"Object",0);
        emit sigData(object);
        hide();
    }
}



