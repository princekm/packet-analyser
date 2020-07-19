#include "NameEntryDialog.h"
#include "Worker.h"
#include "UIManager.h"
NameEntryDialog::~NameEntryDialog()
{

}

void NameEntryDialog::slotEnteredName()
{
    hide();
    emit sigName(nameEdit->text());
    nameEdit->clear();
}

EntryType NameEntryDialog::getType() const
{
    return type;
}

void NameEntryDialog::setType(const EntryType &value)
{
    type = value;
}


NameEntryDialog::NameEntryDialog(QWidget *parent)
{
    init();
    setupConnections();
    applyStyle();


}
void NameEntryDialog::init()
{
    QSize wSize(UIManager::Size::nameDialogSize);
    setType(NONE_TYPE);
    mainLayout = new QVBoxLayout(this);
    heading = new QLabel("Enter Name");
    heading->setAlignment(Qt::AlignCenter);
    nameEdit = new QLineEdit();
    mainLayout->addWidget(heading);
    mainLayout->addWidget(nameEdit);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(2);
    setFixedSize(wSize);
    setWindowFlags(Qt::FramelessWindowHint);
}

void NameEntryDialog::setupConnections()
{
    connect(nameEdit,SIGNAL(returnPressed()),this,SLOT(slotEnteredName()));
}

void NameEntryDialog::applyStyle()
{
    heading->setStyleSheet("QLabel{background:#2980b9;color:white}");
}
