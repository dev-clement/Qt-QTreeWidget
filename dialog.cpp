#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->nameLineEdit->setPlaceholderText("Name");
    ui->textEdit->setPlaceholderText("Descriptions");
    ui->treeWidget->setColumnCount(2);

    connect(ui->addRootBtn, &QPushButton::clicked, this, [this](){
        addRoot(ui->nameLineEdit->text(), ui->textEdit->toPlainText());
        ui->nameLineEdit->clear();
        ui->textEdit->clear();
    });

    connect(ui->addItemBtn, &QPushButton::clicked, this, [this](){
        addChild(ui->treeWidget->currentItem(),
                 ui->nameLineEdit->text(),
                 ui->textEdit->toPlainText());
        ui->nameLineEdit->clear();
        ui->textEdit->clear();
    });
}

void Dialog::addRoot(const QString &name, const QString &description)
{
    auto *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, name);
    item->setText(1, description);
    ui->treeWidget->addTopLevelItem(item);
}

void Dialog::addChild(QTreeWidgetItem *parent, const QString &name, const QString &description)
{
    auto *item = new QTreeWidgetItem;
    item->setText(0, name);
    item->setText(1, description);
    parent->addChild(item);
}

Dialog::~Dialog()
{
    delete ui;
}
