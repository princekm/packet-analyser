#include "Object.h"

QString Object::getVariableName() const
{
    return variableName;
}

void Object::setVariableName(const QString &value)
{
    variableName = value;
}



Object::~Object()
{

}

QString Object::getTypeName() const
{
    return typeName;
}

void Object::setTypeName(const QString &value)
{
    typeName = value;
}


int Object::getSize() const
{
    return size;
}

void Object::setSize(int value)
{
    size = value;
}

Object::Object(QString variableName,QString typeName, int size)
{
    setVariableName(variableName);
    setTypeName(typeName);
    setSize(size);
}
