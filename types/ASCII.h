#ifndef ASCII_H
#define ASCII_H
#include "Format.h"

class ASCII : public Format
{
public:
    ASCII(TypeObject &typeObject);

    // Format interface
public:

    // Format interface
public:
    QString toString(char *val,bool &ok,bool bigEndian=true);
};

#endif // ASCII_H
