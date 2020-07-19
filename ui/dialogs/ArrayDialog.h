#ifndef ARRAYDIALOG_H
#define ARRAYDIALOG_H
#include <DataTypeDialog.h>
#include <QSpinBox>
#include "ArrayTypeObject.h"
class ArrayDialog : public DataTypeDialog
{
    Q_OBJECT
public:
    explicit ArrayDialog(QWidget *parent=nullptr);
private:

    QSpinBox *spinBox;
    void init() override;
signals:
    void sigData(ArrayTypeObject object );

private slots:




    // ObjectTypeDialog interface
private slots:
    void slotProcessOk() override;

    // ObjectTypeDialog interface
protected:
    void setupConnections() override;
};

#endif // ARRAYDIALOG_H
