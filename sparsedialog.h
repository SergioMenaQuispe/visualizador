#ifndef SPARSEDIALOG_H
#define SPARSEDIALOG_H
#include <sparse.h>
#include <QDialog>

namespace Ui {
class SparseDialog;
}

class SparseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SparseDialog(QWidget *parent = nullptr);
    ~SparseDialog();
    void Show_list();

private slots:
    void on_btn_insert_clicked();

    void on_btn_regresarS_clicked();

private:
    Ui::SparseDialog *ui;
    Matrix<int> m;
};

#endif // SPARSEDIALOG_H
