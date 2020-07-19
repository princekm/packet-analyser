#include "ArrayDialog.h"
#include "UIManager.h"
#include "Worker.h"
#include <QDebug>
ArrayDialog::ArrayDialog(QWidget *parent):DataTypeDialog(parent)
{

}

void ArrayDialog::init()
{
    DataTypeDialog::init();
    spinBox = new QSpinBox();
    spinBox->setRange(1,100);
    mainLayout->insertWidget(3,spinBox);
    QSize wSize(UIManager::Size::arrayDialogSize);
    setFixedSize(wSize);

}



void ArrayDialog::slotProcessOk()
{
    if(!variableEdit->text().isEmpty())
    {
        ArrayTypeObject typeObject(variableEdit->text(),typeBox->currentText(),formatBox->currentText(),Worker::getDataStore()->getSizeof(typeBox->currentText()),spinBox->value());
        emit sigData(typeObject);
        hide();

    }

}


void ArrayDialog::setupConnections()
{
    DataTypeDialog::setupConnections();

}
