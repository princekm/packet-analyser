#include "Decimal.h"

Decimal::Decimal(TypeObject &typeObject):Format(typeObject)
{

}

QString Decimal::toString(char *val, bool &ok, bool bigEndian)
{
    QString stringValue;
    QByteArray byteArray(val,typeObject.getSize());
    for(int i=0;i<typeObject.getSize();++i)
    {
        stringValue.append(QString::number((int)byteArray.at(i)));
        if(i!=typeObject.getSize()-1)
            stringValue.append(":");
    }
    return stringValue;
}

