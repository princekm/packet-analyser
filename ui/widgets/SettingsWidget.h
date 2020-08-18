#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H
#include "Widget.h"
#include <QComboBox>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include "Worker.h"
#include <QTextEdit>
class SettingsWidget : public Widget
{
    Q_OBJECT
private:
    QGridLayout *innerLayout;
    QVBoxLayout *mainLayout;
    QLabel *selectInterfaceLabel;
    QFrame *mainFrame;
    QComboBox *interfaceNames;
    QTextEdit *infoEdit;
    Worker *worker;
public:
    explicit SettingsWidget(Worker *worker,QWidget *parent=nullptr);
    ~SettingsWidget();

    // Widget interface
private:
    void init() override;
    void setUpConnections() override;
    void applyStyle() override;
    void loadInterfaceNames();
signals:
    void sigFetchInterfaceNames();
    void sigInterfaceSelected(QString name);
private slots:
    void slotEnable(bool enable);
    void slotAddInterfaceNames(QStringList interfaceNameList);
    void slotDisplayInterfaceDetails(const QStringList list);
};

#endif // SETTINGSWIDGET_H
