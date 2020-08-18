#include "HexaDecimal.h"

HexaDecimal::HexaDecimal(TypeObject &typeObject):Format(typeObject)
{

}

QString HexaDecimal::toString(char *val, bool &ok, bool bigEndian)
{
    QString stringValue;
    QByteArray byteArray(val,typeObject.getSize());
    stringValue=byteArray.toHex(':');
    return stringValue;

}
