#include "ASCII.h"

ASCII::ASCII(TypeObject &typeObject):Format(typeObject)
{

}

QString ASCII::toString(char *val, bool &ok, bool bigEndian)
{
    QString stringValue;
    QByteArray byteArray(val,typeObject.getSize());
    for(int i=0;i<typeObject.getSize();++i)
    {
        stringValue.append(byteArray.at(i));
        if(i!=typeObject.getSize()-1)
            stringValue.append(":");
    }

    return stringValue;

}
