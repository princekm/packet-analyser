#include "TypeObject.h"


TypeObject::TypeObject():Object("","",0)
{

}

TypeObject::TypeObject(QString variableName,QString typeName, QString format, int size):Object(variableName,typeName,size)
{
    setFormat(format);
    setSize(size);
}

TypeObject::~TypeObject()
{

}


QString TypeObject::getFormat() const
{
    return format;
}

void TypeObject::setFormat(const QString &value)
{
    format = value;
}
