#include "DataStore.h"
#include <QDebug>
QString DataStore::getInterfaceName() const
{
    return interfaceName;
}



int DataStore::getSizeof(QString typeName)
{
   return getDataTypeMap().value(typeName);
}



QMap<QString, int> DataStore::getDataTypeMap() const
{
    return dataTypeMap;
}

QStringList DataStore::getFormatList() const
{
    return formatList;
}



DataStore::DataStore(QObject *parent) : QObject(parent)
{


    dataTypeMap.insert("int",4);
    dataTypeMap.insert("unsigned int",4);
    dataTypeMap.insert("short",2);
    dataTypeMap.insert("unsigned short",2);
    dataTypeMap.insert("char",1);
    dataTypeMap.insert("unsigned char",1);
    dataTypeMap.insert("float",4);
    dataTypeMap.insert("double",8);
    dataTypeMap.insert("long",4);
    dataTypeMap.insert("long long",4);
    dataTypeMap.insert("long double",16);


    formatList.append("HEX");
    formatList.append("OCT");
    formatList.append("DEC");
    formatList.append("ASCII");
    formatList.append("BIN");



}

void DataStore::slotSetInterfaceName(QString interfaceName)
{
    this->interfaceName = interfaceName;
    emit sigInterfaceChanged(interfaceName);
}

void DataStore::slotSetEndianness(QString endianness)
{
    this->endianness=endianness;
    emit sigEndiannessChanged(endianness);
}

void DataStore::slotRespondTypes()
{
    QStringList datatypes;
    QList <QString> list= dataTypeMap.keys();
    qDebug()<<"request received"<<list.count();
    foreach(QString key,dataTypeMap.keys())
    {
        qDebug()<<key;
        list<<key;
    }
    emit sigDataTypeList(datatypes);
}



