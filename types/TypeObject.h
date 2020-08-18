#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H
#include <QString>
#include "Object.h"

class TypeObject:public Object
{
private:
    QString format;

public:
     TypeObject();
    explicit TypeObject(QString variableName,QString typeName,QString format,int size);
    ~TypeObject();
    QString getFormat() const;
    void setFormat(const QString &value);
};

#endif // TYPEOBJECT_H
