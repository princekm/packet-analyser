#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H
#include "Widget.h"
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "pcap.h"
#include "Logger.h"
#include "PacketDialog.h"
class CaptureWidget : public Widget
{
    Q_OBJECT
private:
    PacketDialog *packetDialog;
    Logger *logger;
    QTimer *busyTimer;
    QStringList tableHeaders;
    QTableWidget *table;
    QLabel *totalLabel;
    QLabel *deviceLabel;
    QVBoxLayout *mainLayout;
    QHBoxLayout *filterLayout;
    QLineEdit *filterEdit;
    QPushButton *startStopButton;
    QPushButton *clearButton;
    const QString getProtocolName(unsigned char type);
    const QString getTCPPayload(  struct sniff_ip *ip ,const   unsigned char *packet);
    const QString getUDPPayload(  struct sniff_ip *ip ,const   unsigned char *packet);

public:
    explicit CaptureWidget(Logger *logger,QWidget *parent=nullptr);
    ~CaptureWidget();

    // Widget interface
private:
    void init();
    void setUpConnections();
    void applyStyle();
signals:
    void sigPopup(QStringList);
    void sigClear();
    void sigLog(QStringList row);
    void sigRowAvailable(bool);
    void sigEnable(bool enable);
    void sigPayload(uchar *data,int len);
    void sigBusySignal();
    void sigStartCapture();
    void sigStopCapture();
    void sigFilter(QString filterString);
    void sigInspectPacket(QString packetName);
private slots:
    void slotSaveTable(QString fileName);
    void slotSetInterfaceName(QString name);
    void slotSetPacketCount();
    void slotDisplayCaptured(const struct pcap_pkthdr* pkthdr, const unsigned char* packet);
    void slotStartStop();
    void slotClearTable();
    void slotClearInfo();
    void slotFilter();
    void slotFilterReady(bool ok);
    void slotRowClicked(int);
    void slotResetFilterEdit();
    void slotPopupCellContents(int row,int col);
};


#endif // CAPTUREWIDGET_H
