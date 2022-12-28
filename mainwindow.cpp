#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linealdialog.h"
#include "lineal2dialog.h"
#include "pilasdialog.h"
#include "colasdialog.h"
#include "arbolesdialog.h"
#include "hashdialog.h"
#include "sparsedialog.h"
#include "graphdialog.h"
#include "primdialog.h"
#include "kruskaldialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLista_Simple_triggered()
{
    LinealDialog  linealD;
    linealD.setModal(true);
    linealD.exec();
}


void MainWindow::on_actionListas_Dobles_triggered()
{
    lineal2Dialog  lineal2D;
    lineal2D.setModal(true);
    lineal2D.exec();
}


void MainWindow::on_actionPilas_triggered()
{
    PilasDialog  pilasD;
    pilasD.setModal(true);
    pilasD.exec();
}


void MainWindow::on_actionColas_triggered()
{
    ColasDialog  colasD;
    colasD.setModal(true);
    colasD.exec();
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_actionArbol_Binario_triggered()
{
    ArbolesDialog  ArbolD;
    ArbolD.setModal(true);
    ArbolD.exec();
}


void MainWindow::on_actionHash_triggered()
{
    HashDialog  HD;
    HD.setModal(true);
    HD.exec();
}


void MainWindow::on_actionSparse_triggered()
{
    SparseDialog SD;
    SD.setModal(true);
    SD.exec();
}


void MainWindow::on_actionGraph_triggered()
{
    GraphDialog GD;
    GD.setModal(true);
    GD.exec();
}


void MainWindow::on_actionPrim_triggered()
{
    PrimDialog PD;
    PD.setModal(true);
    PD.exec();
}


void MainWindow::on_actionKruskal_triggered()
{
    KruskalDialog KD;
    KD.setModal(true);
    KD.exec();
}

