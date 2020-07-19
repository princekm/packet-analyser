#include "ArrayTypeObject.h"

int ArrayTypeObject::getIndices() const
{
    return indices;
}

void ArrayTypeObject::setIndices(int value)
{
    indices = value;
}

ArrayTypeObject::ArrayTypeObject(QString variableName,QString typeName, QString format, int size,int indices):TypeObject(variableName,typeName,format,size)
{
    setIndices(indices);
}
