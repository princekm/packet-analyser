#ifndef OBJECTTYPEDIALOG_H
#define OBJECTTYPEDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "Object.h"
class ObjectTypeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ObjectTypeDialog(QWidget *parent=nullptr);

    virtual void build();
protected:
    virtual void init();
    virtual void setupConnections();
    virtual void applyStyle();
    QLineEdit *variableEdit;
    QLabel *label;
    QVBoxLayout *mainLayout;
    QPushButton *okButton;
signals:
    void sigData(Object object );
private slots:
    virtual void slotProcessOk();

};

#endif // OBJECTTYPEDIALOG_H
