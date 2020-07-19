#include "Worker.h"
#include "QThread"
#include <QDebug>
#include "pcap.h"


DataStore* Worker::dataStore=nullptr;

Worker::Worker(QObject *parent) : QObject(parent),deviceHandle(nullptr)
{
}

void Worker::startCaptureLoop(u_char *useless, const pcap_pkthdr *pkthdr, const u_char *packet)
{
   // qDebug()<<"Captured";
}

Worker::~Worker()
{

}

void Worker::slotParse()
{

}

DataStore *Worker::getDataStore()
{
    return dataStore;
}

void Worker::slotFetchEthernetInterfaces()
{
    pcap_if *alldevs;
    pcap_if_t *d;
    char errbuf[PCAP_ERRBUF_SIZE+1];
    QStringList interfaceNameList;
    if (pcap_findalldevs(&alldevs,errbuf)!=-1)
    {
        QStringList retval;
        for(d=alldevs;d;d=d->next){
            interfaceNameList<<QString(d->name);
        }
    }
    emit sigInterfaceList(interfaceNameList);

}

void Worker::init()
{
    dataStore = new DataStore;
    timer = new QTimer;
    qRegisterMetaType<Worker::MessageType>("Worker::MessageType");
    qRegisterMetaType<pcap_pkthdr>("pcap_pkthdr");

    connect(timer,SIGNAL(timeout()),this,SLOT(slotCapture()));


}

void Worker::setupConnections()
{

}

void Worker::slotLoad()
{
    Worker::init();
    emit sigReady();
    int percentage=0;
    while(percentage<=100)
    {
        emit sigProgress(percentage);
        thread()->usleep(100000);
        percentage+=10;
    }

}

void Worker::slotSetFilePath(QString path)
{

}
void my_callback(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char* packet)
{
    static int count = 1;
    fprintf(stdout,"%d, ",count);
    if(count == 4)
        fprintf(stdout,"Come on baby sayyy you love me!!! ");
    if(count == 7)
        fprintf(stdout,"Tiiimmmeesss!! ");
    fflush(stdout);
    count++;
}

void Worker::slotStartCapture()
{
    int i;
    const char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr hdr;     /* pcap.h                    */
    struct ether_header *eptr;  /* net/ethernet.h            */
    struct bpf_program fp;      /* hold compiled program     */
    bpf_u_int32 maskp;          /* subnet mask               */
    bpf_u_int32 netp;           /* ip                        */



    dev=dataStore->getInterfaceName().toStdString().c_str();

    pcap_lookupnet(dev,&netp,&maskp,errbuf);

    deviceHandle = pcap_open_live(dev,BUFSIZ,1,100,errbuf);

    QString message;
    if(deviceHandle == NULL)
    {
        message=dataStore->getInterfaceName()+errbuf;
        emit sigInfo(message,ERROR);
        return;
    }
    else
    {
        emit sigCaptureReady(dataStore->getInterfaceName());
    }
    emit sigInfo("Starting capture for device:"+dataStore->getInterfaceName(),INFO);

    /* Lets try and compile the program.. non-optimized */
    //    if(pcap_compile(deviceHandle,&fp,"port *",0,netp) == -1)
    //    {
    //        message=dataStore->getInterfaceName()+errbuf;
    //        emit sigInfo(message,ERROR);
    //        return;
    //    }

    //    /* set the compiled program as the filter */
    //    if(pcap_setfilter(deviceHandle,&fp) == -1)
    //    {
    //        message="Error Setting filter for device:"+dataStore->getInterfaceName();
    //        emit sigInfo(message,ERROR);
    //        return;
    //    }

    /* ... and loop */
    timer->start(100);
    //    pcap_loop(deviceHandle,-1,startCaptureLoop,NULL);
}

void Worker::slotStopCapture()
{
    qDebug()<<"Stopping"<<deviceHandle;
    if(deviceHandle!=nullptr){
        timer->stop();
        emit sigInfo("Stopping capture for device:"+dataStore->getInterfaceName(),INFO);
        pcap_close(deviceHandle);
        deviceHandle=nullptr;

    }
}

void Worker::slotCapture()
{
    struct pcap_pkthdr* pkthdr;
    const u_char* packet;
  //  qDebug()<<"Capturing";
    if(deviceHandle){
        int result=pcap_next_ex(deviceHandle,&pkthdr,&packet);
        if(result!=0)
        {
            emit sigCaptured(pkthdr,packet);
        }
    }
}
