#ifndef LINEALDIALOG_H
#define LINEALDIALOG_H
#include "listasimple.h"
#include <QDialog>
#include <QFileDialog>

namespace Ui {
class LinealDialog;
}

class LinealDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinealDialog(QWidget *parent = nullptr);
    ~LinealDialog();
    void Show_list();

private slots:


    void on_btn_insert_clicked();

    void on_btn_vizu_clicked();



    void on_btn_regresar_clicked();

    void on_btn_delete_clicked();

    void on_btn_find_clicked();



    void on_btn_inset_last_clicked();

    void on_btn_delete_last_clicked();

private:
    Ui::LinealDialog *ui;
    Linked_List<int> L;

};

#endif // LINEALDIALOG_H
