#include "DataTypeDialog.h"
#include "UIManager.h"
#include "Worker.h"
#include <QDebug>
DataTypeDialog::DataTypeDialog(QWidget *parent):ObjectTypeDialog(parent)
{
}

DataTypeDialog::~DataTypeDialog()
{

}



void DataTypeDialog::init()
{
    ObjectTypeDialog::init();
    typeBox = new QComboBox;
    formatBox = new QComboBox;
    formatBox->addItems(Worker::getDataStore()->getFormatList());
    sizeLabel = new QLabel;
    sizeLabel->setAlignment(Qt::AlignCenter);
    mainLayout->insertWidget(2,typeBox);
    mainLayout->insertWidget(3,sizeLabel);
    mainLayout->insertWidget(4,formatBox);
    setWindowFlags(Qt::FramelessWindowHint);
    QSize wSize(UIManager::Size::typeDialogSize);
    setFixedSize(wSize);
    loadTypes();


}

void DataTypeDialog::setupConnections()
{
    ObjectTypeDialog::setupConnections();
    connect(typeBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotSetSizeOfType(QString)));

}

void DataTypeDialog::applyStyle()
{
    label->setStyleSheet("QLabel{background:#2980b9;color:white}");

}

void DataTypeDialog::loadTypes()
{
    foreach(QString key,Worker::getDataStore()->getDataTypeMap().keys())
    {
        typeBox->addItem(key);
    }
    slotSetSizeOfType(typeBox->currentText());

}

void DataTypeDialog::slotSetSizeOfType(QString text)
{
    QString labelText="Size:"+QString::number(Worker::getDataStore()->getSizeof(text));
    labelText.append(" B");
    sizeLabel->setText(labelText);
}



void DataTypeDialog::slotProcessOk()
{
  //  if(!variableEdit->text().isEmpty())
    {
        TypeObject typeObject(variableEdit->text(),typeBox->currentText(),formatBox->currentText(),Worker::getDataStore()->getSizeof(typeBox->currentText()));
        emit sigData(typeObject);
        hide();

    }

}
