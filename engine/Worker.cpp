#include "Worker.h"
#include "QThread"
#include <QDebug>
#include "pcap.h"
#include <QCoreApplication>
#include <QFileInfo>
#include <QDir>
#include <QCryptographicHash>
#include <QFile>
DataStore* Worker::dataStore=nullptr;

Worker::Worker(QObject *parent) : QObject(parent),deviceHandle(nullptr)
{
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
    createRootFolderIfNotExists();
    dataStore = new DataStore;
    timer = new QTimer;
    qRegisterMetaType<Worker::MessageType>("Worker::MessageType");
    qRegisterMetaType<pcap_pkthdr>("pcap_pkthdr");
    setupConnections();


}

void Worker::createRootFolderIfNotExists()
{
    QString path=QCoreApplication::applicationDirPath();
    QDir dir(path);
    createFolder(dir,"Packets");
    createFolder(dir,"Logs");





}

void Worker::createFolder(QDir dir, QString name)
{
    QFileInfo fileInfo(dir.path()+"/"+name);
    if(fileInfo.exists())
    {
        if(!fileInfo.isDir())
        {

        }
    }
    else
    {
        dir.mkdir(name);
        emit sigInfo("'"+name+"' folder is created",MSG_INFO);
    }
}



QString Worker::getIPv4Address(bpf_u_int32 ip_raw)
{
    QByteArray ipArray((char*)(&ip_raw),sizeof(ip_raw));
    QString ipTextHex=ipArray.toHex(':');
    QStringList hexList=ipTextHex.split(':');
    QString ipAddress;
    for(QString hex:hexList)
    {
        //        hex.to
        ipAddress+=QString::number(hex.toInt(nullptr,16),10)+".";
    }
    return ipAddress;

}

void Worker::setupConnections()
{
    connect(dataStore,SIGNAL(sigInterfaceChanged(QString)),this,SLOT(slotFetchDeviceDetails()));
    connect(timer,SIGNAL(timeout()),this,SLOT(slotCapture()));
}

void Worker::slotLoad()
{
    Worker::init();
    QFile file(qApp->applicationFilePath());
    file.open(QFile::ReadOnly);
    file.readAll();
    qDebug()<<qApp->applicationFilePath();
    QCryptographicHash hash(QCryptographicHash::Sha1);
   if( hash.addData(&file))
   {

       QByteArray result=hash.result();

//       qDebug()<<result.size();
       QString md5Hash(result.toHex());
       qDebug()<<result.toHex();
       Worker::getDataStore()->setMD5Hash(md5Hash);
       for(char c:result)
       {
       //    printf("%x",c);
       }
   }
   else
   {
       qDebug()<<"Error";
   }
    emit sigReady();
    int percentage=0;
    while(percentage<=100)
    {
        emit sigProgress(percentage);
        thread()->usleep(100000);

        percentage+=5;
    }


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
        emit sigInfo(message,MSG_ERROR);
        return;
    }
    else
    {
        emit sigCaptureReady(dataStore->getInterfaceName());
    }
    emit sigInfo("Starting capture for device:"+dataStore->getInterfaceName(),MSG_INFO);

    timer->start(500);

}

void Worker::slotSetFilter(QString filterString)
{
    struct bpf_program fp;      /* hold compiled program     */
    bpf_u_int32 netp;           /* ip                        */
    QString message;
    char errbuf[PCAP_ERRBUF_SIZE];
    const char *dev;
    bpf_u_int32 maskp;          /* subnet mask               */

    dev=dataStore->getInterfaceName().toStdString().c_str();

    pcap_lookupnet(dev,&netp,&maskp,errbuf);
    if(deviceHandle){
        if(pcap_compile(deviceHandle,&fp,filterString.toStdString().c_str(),0,netp) == -1)
        {
            message="Error:";
            strcpy(errbuf,pcap_geterr(deviceHandle));
            message+=message.fromLatin1(errbuf,strlen(errbuf));
            printf("%s\n",errbuf);
            emit sigInfo(message,MSG_ERROR);
            emit sigFiltered(false);

            return;
        }

        /* set the compiled program as the filter */
        if(pcap_setfilter(deviceHandle,&fp) == -1)
        {
            message="Error Setting filter for device:"+dataStore->getInterfaceName();
            emit sigInfo(message,MSG_ERROR);
            emit sigFiltered(false);

            return;
        }
        else
        {
            message = "Filter applied Successfully";
            emit sigInfo(message,MSG_INFO);
            emit sigFiltered(true);

        }
    }
    else
    {
        message="Error:Capture not started  for device:"+dataStore->getInterfaceName();
        emit sigInfo(message,MSG_ERROR);
        emit sigFiltered(false);


    }

}

void Worker::slotStopCapture()
{
    if(deviceHandle!=nullptr){
        timer->stop();
        emit sigInfo("Stopping capture for device:"+dataStore->getInterfaceName(),MSG_INFO);
        pcap_close(deviceHandle);
        deviceHandle=nullptr;
    }
}

void Worker::slotCapture()
{
    struct pcap_pkthdr* pkthdr;
    const u_char* packet;
    if(deviceHandle){
        int result=pcap_next_ex(deviceHandle,&pkthdr,&packet);
        if(result!=0)
        {
            emit sigCaptured(pkthdr,packet);
        }
    }
}

void Worker::slotFetchDeviceDetails()
{

    pcap_if_t *d;
    const char *dev;
    QStringList list;
    char ip[13];
    char subnet_mask[13];
    bpf_u_int32 ip_raw; /* IP address as integer */
    bpf_u_int32 subnet_mask_raw; /* Subnet mask as integer */
    int lookup_return_code;
    char error_buffer[PCAP_ERRBUF_SIZE]; /* Size defined in pcap.h */
    struct in_addr address; /* Used for both ip & subnet */
    dev=dataStore->getInterfaceName().toStdString().c_str();
    for(d=alldevs;d;d=d->next){
        if(strcmp(d->name,dev)==0)
        {
            list<<QString(d->name);
            list<<QString(d->description);

            lookup_return_code = pcap_lookupnet(dev,&ip_raw,&subnet_mask_raw,error_buffer);
            if (lookup_return_code != -1)
            {

                QByteArray ipArray((char*)(&ip_raw),sizeof(ip_raw));
                QString ipRaw = ipArray.toHex();
                qDebug()<<ipRaw;
                //                qDebug()<<"hello"<<getIPv4Address(ip_raw);
                //                list<<getIPv4Address(ip_raw);
            }

        }
    }
    emit sigEmitDeviceDetails(list);

}
