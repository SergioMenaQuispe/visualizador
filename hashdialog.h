#ifndef HASHDIALOG_H
#define HASHDIALOG_H
#include <hash.h>
#include <QDialog>

namespace Ui {
class HashDialog;
}

class HashDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HashDialog(QWidget *parent = nullptr);
    ~HashDialog();
    void Show_list();

private slots:
    void on_btn_insert_clicked();

    void on_btn_regresarH_clicked();

    void on_btn_delete_clicked();

    void on_btn_find_clicked();

private:
    Ui::HashDialog *ui;
    Hash<int> h;
};

#endif // HASHDIALOG_H
