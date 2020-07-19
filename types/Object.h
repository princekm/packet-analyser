#ifndef OBJECT_H
#define OBJECT_H
#include<QString>

class Object
{
protected:
    QString variableName;
    QString typeName;
    int size;

public:
    explicit Object(QString variableName,QString typeName,int size);
    ~Object();
    QString getTypeName() const;
    void setTypeName(const QString &value);
    int getSize() const;
    void setSize(int value);
    QString getVariableName() const;
    void setVariableName(const QString &value);
};

#endif // OBJECT_H
