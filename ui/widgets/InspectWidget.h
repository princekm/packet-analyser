#ifndef INSPECTWIDGET_H
#define INSPECTWIDGET_H
#include "Widget.h"

class InspectWidget : public Widget
{
    Q_OBJECT
public:
    InspectWidget(QWidget *parent=nullptr);
    ~InspectWidget();
};

#endif // INSPECTWIDGET_H
