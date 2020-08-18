#include "Binary.h"


Binary::Binary(TypeObject &typeObject):Format(typeObject)
{

}

QString Binary::toString(char *val, bool &ok, bool bigEndian)
{
    QString stringValue;
    QByteArray byteArray(val,typeObject.getSize());
    for(int i=0;i<typeObject.getSize();++i)
    {
        stringValue.append(binaryOf(byteArray.at(i)));
        if(i!=typeObject.getSize()-1)
            stringValue.append(":");
    }

    return stringValue;
}

QString Binary::binaryOf(unsigned char c)
{
    QString binaryString;
    for(int i=0;i<8;++i)
    {
        binaryString.prepend(QString::number((c>>1)&1));
        c=c>>1;
    }
    return binaryString;
}
