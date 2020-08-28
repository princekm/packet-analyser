#include "DataStore.h"
#include <QDebug>
QString DataStore::getInterfaceName() const
{
    return interfaceName;
}

void DataStore::setMD5Hash(QString hash)
{
    this->md5Hash=hash;
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



QString DataStore::getMd5Hash() const
{
    return md5Hash;
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
    dataTypeMap.insert("unsigned long",4);
    dataTypeMap.insert("long long",4);
    dataTypeMap.insert("unsigned long long",4);
    dataTypeMap.insert("long double",16);


    formatList.append("DEFAULT");
    formatList.append("HEXADECIMAL");
    formatList.append("DECIMAL");
    formatList.append("ASCII");
    formatList.append("BINARY");



}

void DataStore::slotSetInterfaceName(QString interfaceName)
{
    this->interfaceName = interfaceName;
    emit sigInterfaceChanged(interfaceName);
}


void DataStore::slotRespondTypes()
{
    QStringList datatypes;
    QList <QString> list= dataTypeMap.keys();
    foreach(QString key,dataTypeMap.keys())
    {
        list<<key;
    }
    emit sigDataTypeList(datatypes);
}



