#ifndef BINARY_H
#define BINARY_H
#include "Format.h"

class Binary : public Format
{
public:
    Binary(TypeObject &typeObject);

    // Format interface
public:
    QString toString(char *val,bool &ok,bool bigEndian=true);
    QString binaryOf(unsigned char c);
};

#endif // BINARY_H
