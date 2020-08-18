#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Widget.h"
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>

class SplashScreen : public Widget
{
    Q_OBJECT
private:

    QVBoxLayout *mainLayout;
    QLabel *label;
    QProgressBar *progressBar;
public:
    explicit SplashScreen(QWidget *parent = nullptr);

signals:
    void sigNext();

    // Widget interface
private:
    void init() override;
    void setUpConnections() override;
    void applyStyle() override;

private slots:
    void slotProgress(int percentage);


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // STARTSCREEN_H
