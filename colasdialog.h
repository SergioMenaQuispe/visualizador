#ifndef COLASDIALOG_H
#define COLASDIALOG_H
#include <cola.h>
#include <QDialog>

namespace Ui {
class ColasDialog;
}

class ColasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColasDialog(QWidget *parent = nullptr);
    ~ColasDialog();
    void Show_list();


private slots:
    void on_btn_regresarCo_clicked();


    void on_btn_insert_clicked();

    void on_btn_delete_clicked();

private:
    Ui::ColasDialog *ui;
    Queque<int> q;
};

#endif // COLASDIALOG_H
