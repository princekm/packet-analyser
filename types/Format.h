#ifndef FORMAT_H
#define FORMAT_H
#include "TypeObject.h"
#include <QDataStream>
class Format
{
protected:
    TypeObject typeObject;
public:
    Format(TypeObject &typeObject);
    virtual QString toString(char *val,bool &ok,bool bigEndian=true);
};

#endif // FORMAT_H
