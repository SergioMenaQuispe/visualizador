#ifndef PILASDIALOG_H
#define PILASDIALOG_H
#include <pilas.h>
#include <QDialog>

namespace Ui {
class PilasDialog;
}

class PilasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PilasDialog(QWidget *parent = nullptr);
    ~PilasDialog();
    void Show_list();

private slots:
    void on_btn_regresarPi_clicked();

    void on_btn_insert_clicked();

    void on_btn_delete_clicked();

private:
    Ui::PilasDialog *ui;
    Stack<int> p;
};

#endif // PILASDIALOG_H
