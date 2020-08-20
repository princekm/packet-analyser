#include "CaptureWidget.h"
#include <QDebug>
#include <QHeaderView>
#include "UIManager.h"
#include "Worker.h"
#include <stdio.h>
#ifdef _WIN32
#include <winsock2.h>
#endif
CaptureWidget::CaptureWidget(QWidget *parent):Widget(parent)
{
    init();
    setUpConnections();
    applyStyle();
    slotSetPacketCount();
}

const QString CaptureWidget::getProtocolName(unsigned char type)
{
    QString protocol;
    switch(type) {
    case IPPROTO_TCP:
        protocol="TCP";
        break;
    case IPPROTO_UDP:
        protocol="UDP";
        break;
    case IPPROTO_ICMP:
        protocol="ICMP";
        break;
    case IPPROTO_IP:
        protocol="IP";
        break;
    default:
        protocol=QString::number(type);
    }
    return protocol;

}

const QString CaptureWidget::getTCPPayload(struct sniff_ip *ip,const   unsigned char *packet)
{
    QString payloadString;
    unsigned char *payload;                    /* Packet payload */
    struct sniff_tcp *tcp;            /* The TCP header */

    int size_ip;
    int size_tcp;
    int size_payload;

    size_ip = IP_HL(ip)*4;

    tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
    size_tcp = TH_OFF(tcp)*4;



    payload = ( unsigned char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
    size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);
    emit sigPayload(payload,size_payload);
    if (size_payload > 0) {
        QByteArray array=QByteArray::fromRawData((char*)payload, size_payload);
        payloadString.append(array.toHex(':'));
    }
    else
    {
    }
    return payloadString;

}

const QString CaptureWidget::getUDPPayload( sniff_ip *ip, const unsigned char *packet)
{
    QString payloadString;
    unsigned char *payload;                    /* Packet payload */
    struct sniff_udp *udp;            /* The UDP header */

    int size_ip;
    int size_udp;
    int size_payload;

    size_ip = IP_HL(ip)*4;

    udp = (struct sniff_udp*)(packet + SIZE_ETHERNET + size_ip);
    size_udp = 8;

    payload = ( unsigned char *)(packet + SIZE_ETHERNET + size_ip + size_udp);
    size_payload = ntohs(ip->ip_len) - (size_ip + size_udp);
    emit sigPayload(payload,size_payload);

    if (size_payload > 0) {
        QByteArray array=QByteArray::fromRawData((char*)payload, size_payload);
        payloadString.append(array.toHex(':'));
    }
    else
    {
    }
    return payloadString;

}



CaptureWidget::~CaptureWidget()
{

}

void CaptureWidget::init()
{
    table = new QTableWidget;
    busyTimer = new QTimer();
    table->setWordWrap(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableHeaders<<"Source"<<"Destination"<<"Protocol"<<"Payload"<<"Size"<<"Time";
    table->setColumnCount(tableHeaders.count());
    table->setColumnWidth(0,120);
    table->setColumnWidth(1,120);
    table->setHorizontalHeaderLabels(tableHeaders);
    QHeaderView* header = table ->horizontalHeader();
    header->setSectionResizeMode(3,QHeaderView::Stretch);

    deviceLabel = new QLabel("");
    totalLabel = new QLabel("");
    mainLayout = new QVBoxLayout(this);
    filterEdit = new QLineEdit;
    filterEdit->setEnabled(false);
    filterEdit->setPlaceholderText("Enter the filter here ...");
    filterEdit->setAttribute(Qt::WA_MacShowFocusRect, 0);

    startStopButton = new QPushButton("Start");
    clearButton = new QPushButton("Clear");

    QIcon startIcon(UIManager::Resources::START_ICON);
    QIcon stopIcon(UIManager::Resources::STOP_ICON);
    QIcon clearIcon(UIManager::Resources::CLEAR_ICON);

    startStopButton->setIcon(startIcon);
    clearButton->setIcon(clearIcon);


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
    connect(busyTimer,SIGNAL(timeout()),this,SIGNAL(sigBusySignal()));
    connect(startStopButton,SIGNAL(clicked()),this,SLOT(slotStartStop()));
    connect(Worker::getDataStore(),SIGNAL(sigInterfaceChanged(QString)),this,SLOT(slotSetInterfaceName(QString)));
    connect(filterEdit,SIGNAL(returnPressed()),this,SLOT(slotFilter()));
    connect(filterEdit,SIGNAL(textEdited(QString)),this,SLOT(slotResetFilterEdit()));
    connect(clearButton,SIGNAL(clicked()),this,SLOT(slotClearTable()));
    connect(table->verticalHeader(), SIGNAL(sectionClicked(int)),this,SLOT(slotRowClicked(int)) );
}

void CaptureWidget::applyStyle()
{
    setStyleSheet("QLabel{color:black}");
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

void CaptureWidget::slotDisplayCaptured(const pcap_pkthdr *pkthdr,const  unsigned char *packet)
{



    slotSetPacketCount();
    /* declare pointers to packet headers */
    struct sniff_ethernet *ethernet;  /* The ethernet header [1] */
    struct sniff_ip *ip;              /* The IP header */


    /* define ethernet header */
    ethernet = (struct sniff_ethernet*)(packet);

    /* define/compute ip header offset */
    int size_ip;

    ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
    size_ip = IP_HL(ip)*4;
    QString srcIP(inet_ntoa(ip->ip_src));
    QString destIP(inet_ntoa(ip->ip_dst));
    QString protocol=getProtocolName(ip->ip_p);

    if(protocol == "TCP" || protocol == "UDP" )
    {
        QString payloadString;
        table->insertRow(0);
        QColor color;
        if(protocol == "TCP"){
            struct sniff_tcp *tcp=nullptr;            /* The TCP header */
            tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
            srcIP+=":"+QString::number(ntohs(tcp->th_sport));
            destIP+=":"+QString::number(ntohs(tcp->th_dport));
            payloadString =getTCPPayload(ip,packet);
            color.setRgb(44, 62, 80);
        }
        else if(protocol == "UDP")
        {
            struct sniff_udp *udp=nullptr;
            udp = (struct sniff_udp*)(packet + SIZE_ETHERNET + size_ip);
            srcIP+=":"+QString::number(ntohs(udp->th_sport));
            destIP+=":"+QString::number(ntohs(udp->th_dport));
            payloadString =getUDPPayload(ip,packet);
            color.setRgb(211, 84, 0);


        }
        auto model = table->model();

        model->setData(model->index(0,3),payloadString);
        model->setData(model->index(0,4),QString::number((payloadString.length()+1)/3));
        model->setData(model->index(0,5),QString::number(pkthdr->ts.tv_usec));
        model->setData(model->index(0,0),srcIP);
        model->setData(model->index(0,1),destIP);
        model->setData(model->index(0,2),protocol);

        for(int col=0;col<table->columnCount();++col)
        {

            table->item(0, col)->setBackground(color);
            table->item(0, col)->setForeground(Qt::white);


        }
    }


}


void CaptureWidget::slotStartStop()
{
    QString text=startStopButton->text();
    QIcon startIcon(UIManager::Resources::START_ICON);
    QIcon stopIcon(UIManager::Resources::STOP_ICON);


    if(text=="Start")
    {
        emit sigStartCapture();
        emit sigEnable(false);
        busyTimer->start(100);
        filterEdit->setEnabled(true);

        startStopButton->setIcon(stopIcon);
        slotSetPacketCount();
    }
    else if(text=="Stop ")
    {
        busyTimer->stop();
        emit sigEnable(true);
        emit sigStopCapture();
        filterEdit->setEnabled(false);
        filterEdit->clear();
        filterEdit->setStyleSheet("background:#ffffff;color:black");

        startStopButton->setIcon(startIcon);

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

void CaptureWidget::slotFilter()
{
    QString filterString=filterEdit->text();
    if(!filterString.isEmpty())
    {
        emit sigFilter(filterString);
    }
}

void CaptureWidget::slotFilterReady(bool ok)
{
    if(ok)
    {
        slotClearInfo();
        slotClearTable();
        filterEdit->setStyleSheet("background:#1abc9c;color:white");
    }
    else
    {
        filterEdit->setStyleSheet("background:#fd79a8;color:red");
    }
}

void CaptureWidget::slotRowClicked(int row)
{
}

void CaptureWidget::slotResetFilterEdit()
{
    if(filterEdit->text().isEmpty())
    {
        filterEdit->setStyleSheet("background:#ffffff;color:black");

    }
}
