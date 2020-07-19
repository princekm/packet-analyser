#include "CaptureWidget.h"
#include <QDebug>
CaptureWidget::CaptureWidget(QWidget *parent):Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();
}

CaptureWidget::~CaptureWidget()
{

}

void CaptureWidget::init()
{
    table = new QTableWidget;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableHeaders<<"Src"<<"Dest"<<"Protocol"<<"Packet"<<"Size"<<"Part"<<"Time";
    table->setColumnCount(tableHeaders.count());
    table->setHorizontalHeaderLabels(tableHeaders);
    deviceLabel = new QLabel("");
    totalLabel = new QLabel("");
    mainLayout = new QVBoxLayout(this);
    filterEdit = new QLineEdit;
    filterEdit->setAttribute(Qt::WA_MacShowFocusRect, 0);

    startStopButton = new QPushButton("Start");
    clearButton = new QPushButton("Clear");
    filterLayout=  new QHBoxLayout;
    filterLayout->addWidget(filterEdit);
    filterLayout->addWidget(startStopButton);
    filterLayout->addWidget(clearButton);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(deviceLabel);
    mainLayout->addWidget(totalLabel);
    mainLayout->addLayout(filterLayout);
    mainLayout->addWidget(table);
}

void CaptureWidget::setUpConnections()
{
    connect(startStopButton,SIGNAL(clicked()),this,SLOT(slotStartStop()));
    connect(clearButton,SIGNAL(clicked()),this,SLOT(slotClearTable()));
}

void CaptureWidget::applyStyle()
{
    setStyleSheet("QLabel{color:white}");
    table->setStyleSheet("QTableWidget{color:black;background:white}");
}

void CaptureWidget::slotSetInterfaceName(QString name)
{
    deviceLabel->setText("Device:"+name);
}

void CaptureWidget::slotSetPacketCount()
{
    totalLabel->setText("Packets:"+QString::number(table->rowCount()));
}

void CaptureWidget::slotDisplayCaptured(const pcap_pkthdr *pkthdr, const unsigned char *packet)
{
    qDebug()<<"captured";
    table->insertRow(0);
    auto model = table->model();
    model->setData(model->index(0,4),QString::number(pkthdr->len));
    model->setData(model->index(0,5),QString::number(pkthdr->caplen));
    model->setData(model->index(0,6),QString::number(pkthdr->ts.tv_usec));
    slotSetPacketCount();
}


void CaptureWidget::slotStartStop()
{
    qDebug()<<"Start/Stop";
    QString text=startStopButton->text();
    if(text=="Start")
    {
        emit sigStartCapture();
        slotSetPacketCount();
    }
    else if(text=="Stop ")
    {
        emit sigStopCapture();
        slotClearInfo();

    }
    QString nextText = (text=="Start"?"Stop ":"Start");
    startStopButton->setText(nextText);
}

void CaptureWidget::slotClearTable()
{
    table->setRowCount(0);
    slotSetPacketCount();

}

void CaptureWidget::slotClearInfo()
{
    totalLabel->clear();
    deviceLabel->clear();
}
