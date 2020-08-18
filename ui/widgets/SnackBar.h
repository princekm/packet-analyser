#ifndef SNACKBAR_H
#define SNACKBAR_H
#include "Widget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QPushButton>
class SnackBar:public Widget
{
    Q_OBJECT
private:
    QTimer *displayTimer;
    QPushButton *iconButton;
    int counter;
public:
    explicit SnackBar(QWidget *parent=nullptr);

    // Widget interface
    void setCounter(int value);

private:
    QVBoxLayout *mainLayout;
    void init() override;
    void setUpConnections() override;
    void applyStyle() override;
private slots:
    void slotSetText(QString string,QColor color);
    void slotTimeout();
};

#endif // SNACKBAR_H
