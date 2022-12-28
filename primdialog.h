#ifndef PRIMDIALOG_H
#define PRIMDIALOG_H
#include "prim.h"
#include <QDialog>

namespace Ui {
class PrimDialog;
}

class PrimDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrimDialog(QWidget *parent = nullptr);
    ~PrimDialog();
    void Show_list();
    void Show_listA();

private slots:
    void on_btn_insertV_clicked();

    void on_btn_insertA_clicked();

    void on_btn_prim_clicked();

    void on_btn_regresarP_clicked();

private:
    Ui::PrimDialog *ui;
    GraphP g;
    GraphP *a=new GraphP;
};

#endif // PRIMDIALOG_H
