#ifndef ARBOLESDIALOG_H
#define ARBOLESDIALOG_H
#include <arbolb.h>
#include <QDialog>

namespace Ui {
class ArbolesDialog;
}

class ArbolesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArbolesDialog(QWidget *parent = nullptr);
    ~ArbolesDialog();
    void Show_list();

private slots:
    void on_btn_insert_clicked();

    void on_btn_delete_clicked();

    void on_btn_regresarA_clicked();

    void on_btn_find_clicked();

    void on_pushButton_4_clicked();

    void on_btn_minimo_clicked();

private:
    Ui::ArbolesDialog *ui;
    Tree<int> a;
};

#endif // ARBOLESDIALOG_H
