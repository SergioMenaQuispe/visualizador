#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:




    void on_actionLista_Simple_triggered();

    void on_actionListas_Dobles_triggered();

    void on_actionPilas_triggered();

    void on_actionColas_triggered();

    void on_pushButton_clicked();

    void on_actionArbol_Binario_triggered();

    void on_actionHash_triggered();

    void on_actionSparse_triggered();

    void on_actionGraph_triggered();

    void on_actionPrim_triggered();

    void on_actionKruskal_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
