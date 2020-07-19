#ifndef WIDGET_H
#define WIDGET_H
#include <QFrame>

class Widget : public QFrame
{
    Q_OBJECT
private:
    virtual void init()=0;
    virtual void setUpConnections(){}
    virtual void applyStyle(){
    }
public:
    explicit Widget(QWidget *parent=nullptr);
    ~Widget();

};

#endif // WIDGET_H
