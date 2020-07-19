#ifndef NAMEENTRYDIALOG_H
#define NAMEENTRYDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "Enum.h"
class NameEntryDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NameEntryDialog(QWidget *parent=nullptr);
    ~NameEntryDialog();
    EntryType getType() const;
    void setType(const EntryType &value);

signals:
    void sigName(QString name);
private slots:
    void slotEnteredName();
private:
    EntryType type;
    QLabel *heading;
    QLineEdit *nameEdit;
    QVBoxLayout *mainLayout;
    void init();
    void setupConnections();
    void applyStyle();

};

#endif // NAMEENTRYDIALOG_H
