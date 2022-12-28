#ifndef KRUSKALDIALOG_H
#define KRUSKALDIALOG_H
#include <kruskal.h>
#include <QDialog>

namespace Ui {
class KruskalDialog;
}

class KruskalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KruskalDialog(QWidget *parent = nullptr);
    ~KruskalDialog();
    void Show_list();
    void Show_listA();

private slots:
    void on_btn_insertV_clicked();

    void on_btn_insertA_clicked();

    void on_btn_kruskal_clicked();

    void on_btn_regresarK_clicked();

private:
    Ui::KruskalDialog *ui;
    GraphK g;
    GraphK *a=new GraphK;
};

#endif // KRUSKALDIALOG_H
