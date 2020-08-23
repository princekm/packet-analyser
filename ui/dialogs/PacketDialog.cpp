#include "PacketDialog.h"

void PacketDialog::init()
{
 srcLabel = new QLabel;
 dstLabel = new QLabel;
 timeLabel = new QLabel;
 payloadLabel = new QLabel("Payload:");
 sizeLabel = new QLabel;
 protocolLabel = new QLabel;
 payloadText = new QTextEdit;
 payloadText->setAlignment(Qt::AlignJustify);
 payloadText->setReadOnly(true);
 mainLayout = new QVBoxLayout(this);
 mainLayout->addWidget(srcLabel);
 mainLayout->addWidget(dstLabel);
 mainLayout->addWidget(timeLabel);
 mainLayout->addWidget(sizeLabel);
 mainLayout->addWidget(payloadLabel);
 mainLayout->addWidget(payloadText);


}

void PacketDialog::setupConnections()
{

}

void PacketDialog::applyStyle()
{
    payloadText->setTextColor(Qt::blue);
}

PacketDialog::PacketDialog(QWidget *parent):QDialog(parent)
{
    init();
    setupConnections();
    applyStyle();
}

PacketDialog::~PacketDialog()
{

}

void PacketDialog::slotUpdateInfo(QStringList list)
{
    if(list.length()==6)
    {
        srcLabel->setText("Source:"+list.at(0));
        dstLabel->setText("Destination:"+list.at(1));
        timeLabel->setText("Time:"+list.at(5));
        sizeLabel->setText("Payload Size:"+list.at(4));
        protocolLabel->setText("PROTOCOL"+list.at(2));
        payloadText->setText(list.at(3));
    }
}
