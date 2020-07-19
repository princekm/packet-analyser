#ifndef ARRAYTYPEOBJECT_H
#define ARRAYTYPEOBJECT_H
#include "TypeObject.h"

class ArrayTypeObject : public TypeObject
{
private:
    int indices;
public:
    ArrayTypeObject(QString variableName,QString typeName, QString format, int size,int indices);
    int getIndices() const;
    void setIndices(int value);
};

#endif // ARRAYTYPEOBJECT_H
