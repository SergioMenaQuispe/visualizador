#include "kruskaldialog.h"
#include "ui_kruskaldialog.h"

KruskalDialog::KruskalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KruskalDialog)
{
    ui->setupUi(this);
}

KruskalDialog::~KruskalDialog()
{
    delete ui;
}
void KruskalDialog::Show_list()
{
    string comando="dot -Tjpeg graph.dot. -o graph.jpeg";
    system(comando.c_str());

}
void KruskalDialog::Show_listA()
{
    string comando="dot -Tjpeg arbol.dot. -o arbol.jpeg";
    system(comando.c_str());

}

void KruskalDialog::on_btn_insertV_clicked()
{
    this->g.insertarVertice(this->ui->txt_value->toPlainText().toStdString()[0]);
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
}


void KruskalDialog::on_btn_insertA_clicked()
{
    this->g.insertarArista(this->ui->txt_value2->toPlainText().toStdString()[0],this->ui->txt_value3->toPlainText().toStdString()[0],this->ui->txt_value4->toPlainText().toInt());
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
}


void KruskalDialog::on_btn_kruskal_clicked()
{

    this->g.algoritmoKruskal(a);
    g.show();
    a->show_arbol();
    Show_list();
    Show_listA();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
    QPixmap pixA("arbol.jpeg");
    ui->label_5->setPixmap(pixA);
}


void KruskalDialog::on_btn_regresarK_clicked()
{
    this->close();
}

