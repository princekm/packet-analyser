#include "AboutDialog.h"
#include "UIManager.h"
AboutDialog::AboutDialog(QWidget *parent):QDialog(parent)
{
    init();
    setupConnections();
    applyStyle();
}

AboutDialog::~AboutDialog()
{

}

void AboutDialog::init()
{
    setWindowTitle("About");
    mainLayout = new QVBoxLayout(this);
    label = new QLabel("Packet Analyser");
    headLayout = new QHBoxLayout();
    textEdit = new QTextEdit;
    textEdit->setPlainText("Version 1.0");
    iconButton = new QToolButton();
    textEdit->setReadOnly(true);
    iconButton->setIcon(QIcon(UIManager::Resources::APP_ICON));

    headLayout->addWidget(iconButton);
    headLayout->addWidget(label);
    mainLayout->addLayout(headLayout);
    mainLayout->addWidget(textEdit);


}

void AboutDialog::setupConnections()
{

}

void AboutDialog::applyStyle()
{

}
