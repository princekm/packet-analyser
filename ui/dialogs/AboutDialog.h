#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include <QDialog>
#include <QToolButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
class AboutDialog : public QDialog
{
    Q_OBJECT
private:
    QToolButton *iconButton;
    QTextEdit *textEdit;
    QLabel *label;
    QVBoxLayout *mainLayout;
    QHBoxLayout *headLayout;
public:
    AboutDialog(QWidget *parent=nullptr);
    ~AboutDialog();

protected:
     void init() ;
     void setupConnections() ;
     void applyStyle() ;
};

#endif // ABOUTDIALOG_H
