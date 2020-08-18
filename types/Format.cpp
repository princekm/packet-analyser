#include "Format.h"
#include <QDebug>

Format::Format(TypeObject &typeObject)
{
    this->typeObject=typeObject;
}

QString Format::toString(char *val, bool &ok, bool bigEndian)
{

    QString stringValue;
    QByteArray byteArray(val,typeObject.getSize());
    ok=true;
    QDataStream ds(&byteArray,QIODevice::ReadWrite);
    if(bigEndian)
        ds.setByteOrder(QDataStream::BigEndian);
    else
        ds.setByteOrder(QDataStream::LittleEndian);

    if(typeObject.getFormat()=="DEFAULT")
    {
        QString typeName = typeObject.getTypeName();
        if(typeName == "char")
        {
            QChar value=QChar(byteArray.at(0));
            stringValue = value;
            if(!value.isPrint())
                ok=false;
        }
        else if(typeName == "unsigned char")
        {
            QChar value=QChar(byteArray.at(0));
            stringValue = value;
            if(!value.isPrint())
                ok=false;
        }
        else if(typeName == "short")
        {
            qint16 value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "unsigned short")
        {
            quint16 value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "int")
        {
            qint32  value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "unsigned int")
        {
            quint32  value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "float")
        {
            float  value;// >> ds;

            ds.setFloatingPointPrecision(QDataStream::SinglePrecision);
            ds>>value;

            stringValue.setNum(value);
        }
        else if(typeName == "double")
        {
            qreal  value;// >> ds;
            ds.setFloatingPointPrecision(QDataStream::DoublePrecision);
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "long")
        {
            qint64 value;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "unsigned long")
        {
            quint64 value;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "long long")
        {
            qlonglong  value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "unsigned long long")
        {
            qulonglong  value;// >> ds;
            ds>>value;
            stringValue.setNum(value);
        }
        else if(typeName == "long double")
        {
            double  value;// >> ds;
            ds.setFloatingPointPrecision(QDataStream::DoublePrecision);
            ds>>value;
            stringValue.setNum(value);

        }

    }
    return stringValue;
}
