#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include "Format.h"

class HexaDecimal : public Format
{
public:
    HexaDecimal(TypeObject &typeObject);

    // Format interface
public:
    QString toString(char *val,bool &ok,bool bigEndian=true) override;
};

#endif // HEXADECIMAL_H
