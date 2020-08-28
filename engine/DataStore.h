#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QSize>
#include <QMap>
#include <QMultiMap>
#include <QFile>
class DataStore : public QObject
{
    Q_OBJECT

private:

    QMap <QString,int> dataTypeMap;
    QStringList formatList;
    QString interfaceName;
    QString md5Hash;


public:
    explicit DataStore(QObject *parent = nullptr);
    QString getInterfaceName() const;
    void setMD5Hash(QString hash);
    int getSizeof(QString typeName);
    QMap<QString, int> getDataTypeMap() const;
    QStringList getFormatList() const;


    QString getMd5Hash() const;

signals:
    void sigInterfaceChanged(QString interfaceName);
    void sigDataTypeList(QStringList datatypes);

private slots:
    void slotSetInterfaceName(QString interfaceName);
    void slotRespondTypes();


};

#endif // DATASTORE_H
