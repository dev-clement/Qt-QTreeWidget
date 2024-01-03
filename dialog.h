#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void addRoot(const QString& name, const QString& description);
    void addChild(QTreeWidgetItem *parent, const QString& name, const QString& description);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
