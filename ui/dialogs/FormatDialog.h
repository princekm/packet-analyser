#ifndef FORMATDIALOG_H
#define FORMATDIALOG_H
#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>

class FormatDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FormatDialog(QWidget *parent=nullptr);
    ~FormatDialog();

protected:
     void init() ;
     void setupConnections() ;
     void applyStyle() ;
private:
     QComboBox *formatBox;
     QVBoxLayout *mainLayout;
     QPushButton *okButton;

signals:
     void sigFormat(QString format);
private slots:
    void slotOk();
};

#endif // FORMATDIALOG_H
