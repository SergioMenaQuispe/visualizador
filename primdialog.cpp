#include "primdialog.h"
#include "ui_primdialog.h"

PrimDialog::PrimDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimDialog)
{
    ui->setupUi(this);
}

PrimDialog::~PrimDialog()
{
    delete ui;
}
void PrimDialog::Show_list()
{
    string comando="dot -Tjpeg graph.dot. -o graph.jpeg";
    system(comando.c_str());

}
void PrimDialog::Show_listA()
{
    string comando="dot -Tjpeg arbol.dot. -o arbol.jpeg";
    system(comando.c_str());

}
void PrimDialog::on_btn_insertV_clicked()
{
    this->g.insertarVertice(this->ui->txt_value->toPlainText().toStdString()[0]);
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_3->setPixmap(pix);
}


void PrimDialog::on_btn_insertA_clicked()
{
    this->g.insertarArista(this->ui->txt_value2->toPlainText().toStdString()[0],this->ui->txt_value3->toPlainText().toStdString()[0],this->ui->txt_value4->toPlainText().toInt());
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_3->setPixmap(pix);
}


void PrimDialog::on_btn_prim_clicked()
{
    this->g.algoritmoPrim(a);
    g.show();
    a->show_arbol();
    Show_list();
    Show_listA();
    QPixmap pix("graph.jpeg");
    ui->label_3->setPixmap(pix);
    QPixmap pixA("arbol.jpeg");
    ui->label_5->setPixmap(pixA);
}


void PrimDialog::on_btn_regresarP_clicked()
{
    this->close();
}

