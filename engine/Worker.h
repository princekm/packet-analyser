#ifndef PACKETPARSER_H
#define PACKETPARSER_H

#include <QObject>
#include "DataStore.h"
#include "pcap.h"
#include <QTimer>
class Worker : public QObject
{
    Q_OBJECT
private:

    pcap_t* deviceHandle;
    static DataStore *dataStore;
    QTimer *timer;
    void init();
    void setupConnections();
public:
    enum MessageType{ERROR,INFO};

    explicit Worker(QObject *parent = nullptr);
     static void startCaptureLoop(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char* packet);
    ~Worker();
    static DataStore *getDataStore();

signals:
    void sigReady();
    void sigCaptureReady(QString deviceName);
    void sigProgress(int percentage);
    void sigInterfaceList(QStringList interfaceNameList);
    void sigFinished();
    void sigInfo(QString,Worker::MessageType);
    void sigCaptured(const struct pcap_pkthdr* pkthdr,const unsigned char* packet);
private slots:
    void slotParse();
    void slotLoad();
    void slotSetFilePath(QString path);
    void slotFetchEthernetInterfaces();
    void slotStartCapture();
    void slotStopCapture();
    void slotCapture();

signals:

};

#endif // PACKETPARSER_H
