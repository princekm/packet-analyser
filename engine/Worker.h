#ifndef PACKETPARSER_H
#define PACKETPARSER_H

#include <QObject>
#include "DataStore.h"
#include <pcap.h>
#include <QTimer>
#include <QDir>
#include "EthHeader.h"

class Worker : public QObject
{
    Q_OBJECT

private:

    pcap_t* deviceHandle;
    pcap_if *alldevs;
    QTimer *timer;

    static DataStore *dataStore;


    void init();
    void createRootFolderIfNotExists();
    void createFolder(QDir dir,QString name);

    QString getIPv4Address(bpf_u_int32 ip_raw);
    void setupConnections();
public:
    enum MessageType{MSG_ERROR,MSG_INFO};

    explicit Worker(QObject *parent = nullptr);
    ~Worker();
    static DataStore *getDataStore();

signals:
    void sigReady();
    void sigFiltered(bool error);
    void sigCaptureReady(QString deviceName);
    void sigProgress(int percentage);
    void sigInterfaceList(QStringList interfaceNameList);
    void sigFinished();
    void sigInfo(QString,Worker::MessageType);
    void sigCaptured(const struct pcap_pkthdr* pkthdr,const unsigned char* packet);
    void sigEmitDeviceDetails(QStringList list);
private slots:

    void slotParse();
    void slotLoad();
    void slotFetchEthernetInterfaces();
    void slotStartCapture();
    void slotSetFilter(QString filterString);
    void slotStopCapture();
    void slotCapture();
    void slotFetchDeviceDetails();

signals:

};

#endif // PACKETPARSER_H
