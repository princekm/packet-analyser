#ifndef PACKETDIALOG_H
#define PACKETDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class PacketDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel *srcLabel;
    QLabel *protocolLabel;
    QLabel *dstLabel;
    QLabel *sizeLabel;
    QLabel *timeLabel;
    QLabel *payloadLabel;
    QTextEdit *payloadText;
    QVBoxLayout *mainLayout;
    void init();
    void setupConnections();
    void applyStyle();
public:
    PacketDialog(QWidget *parent=nullptr);
    ~PacketDialog();
private slots:
    void slotUpdateInfo(QStringList list);
};

#endif // PACKETDIALOG_H
