#ifndef DATATYPEDIALOG_H
#define DATATYPEDIALOG_H
#include "ObjectTypeDialog.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "TypeObject.h"
#include <QLineEdit>
class DataTypeDialog : public ObjectTypeDialog
{
    Q_OBJECT
public:
    explicit DataTypeDialog(QWidget *parent=nullptr);
    ~DataTypeDialog();
protected:
    virtual void init() override;
    virtual void setupConnections() override;
    virtual void applyStyle() override;
    void loadTypes();
    QLabel *sizeLabel;
    QComboBox *typeBox;
    QComboBox *formatBox;
signals:
    void sigLoadTypes();
    void sigData(TypeObject object );
private slots:
    void slotSetSizeOfType(QString  text);





    // ObjectTypeDialog interface
private slots:
    void slotProcessOk() override;
};

#endif // DATATYPEDIALOG_H
