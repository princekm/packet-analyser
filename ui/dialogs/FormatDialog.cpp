#include "FormatDialog.h"
#include "Worker.h"
FormatDialog::FormatDialog(QWidget *parent):QDialog(parent)
{
    init();
    setupConnections();
    applyStyle();
}

FormatDialog::~FormatDialog()
{

}

void FormatDialog::init()
{
    mainLayout = new QVBoxLayout(this);
    formatBox = new QComboBox();
    okButton = new QPushButton("OK");
    formatBox->addItems(Worker::getDataStore()->getFormatList());
    mainLayout->addWidget(formatBox);
    mainLayout->addWidget(okButton);
    setWindowFlags(Qt::FramelessWindowHint);
}

void FormatDialog::setupConnections()
{
    connect(okButton,SIGNAL(clicked()),this,SLOT(slotOk()));
}

void FormatDialog::applyStyle()
{

}

void FormatDialog::slotOk()
{
    emit sigFormat(formatBox->currentText());
    hide();
}
