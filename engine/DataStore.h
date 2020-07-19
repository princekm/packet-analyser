#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QSize>
#include <QMap>
#include <QMultiMap>
class DataStore : public QObject
{
    Q_OBJECT
private:

    QMap <QString,int> dataTypeMap;
    QStringList formatList;
    QString interfaceName;
    QString endianness;


public:
    explicit DataStore(QObject *parent = nullptr);

    QString getInterfaceName() const;


    int getSizeof(QString typeName);


    QMap<QString, int> getDataTypeMap() const;

    QStringList getFormatList() const;


signals:
    void sigInterfaceChanged(QString interfaceName);
    void sigEndiannessChanged(QString endianness);
    void sigDataTypeList(QStringList datatypes);
private slots:
    void slotSetInterfaceName(QString interfaceName);
    void slotSetEndianness(QString endianness);
    void slotRespondTypes();


};

#endif // DATASTORE_H
