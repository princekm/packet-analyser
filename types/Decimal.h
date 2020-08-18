#ifndef DECIMAL_H
#define DECIMAL_H
#include "Format.h"

class Decimal : public Format
{
public:
    Decimal(TypeObject &typeObject);

    // Format interface
public:

    // Format interface
public:
    QString toString(char *val,bool &ok,bool bigEndian=true);
};

#endif // DECIMAL_H
