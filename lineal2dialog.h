#ifndef LINEAL2DIALOG_H
#define LINEAL2DIALOG_H
#include "double_linked_list.h"
#include <QDialog>

namespace Ui {
class lineal2Dialog;
}

class lineal2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit lineal2Dialog(QWidget *parent = nullptr);
    ~lineal2Dialog();
    void Show_list();

private slots:
    void on_btn_regresarLD_clicked();

    void on_btn_insert_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::lineal2Dialog *ui;
    Double_Linked_List<int> LD;
};

#endif // LINEAL2DIALOG_H
