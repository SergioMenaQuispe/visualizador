#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H
#include <grafo.h>
#include <QDialog>

namespace Ui {
class GraphDialog;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = nullptr);
    ~GraphDialog();
    void Show_list();

private slots:
    void on_btn_insert_clicked();

    void on_btn_insertA_clicked();

    void on_btn_delete_clicked();



    void on_btn_regresarG_clicked();

private:
    Ui::GraphDialog *ui;
    Graph g;
};

#endif // GRAPHDIALOG_H
