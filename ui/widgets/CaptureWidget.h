#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H
#include "Widget.h"
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "pcap.h"
class CaptureWidget : public Widget
{
    Q_OBJECT
private:
    QStringList tableHeaders;
    QTableWidget *table;
    QLabel *totalLabel;
    QLabel *deviceLabel;
    QVBoxLayout *mainLayout;
    QHBoxLayout *filterLayout;
    QLineEdit *filterEdit;
    QPushButton *startStopButton;
    QPushButton *clearButton;

public:
    explicit CaptureWidget(QWidget *parent=nullptr);
    ~CaptureWidget();

    // Widget interface
private:
    void init();
    void setUpConnections();
    void applyStyle();
signals:
    void sigStartCapture();
    void sigStopCapture();
private slots:
    void slotSetInterfaceName(QString name);
    void slotSetPacketCount();
    void slotDisplayCaptured(const struct pcap_pkthdr* pkthdr,const unsigned char* packet);
    void slotStartStop();
    void slotClearTable();
    void slotClearInfo();
};

#endif // CAPTUREWIDGET_H
