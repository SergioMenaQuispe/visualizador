#include "graphdialog.h"
#include "ui_graphdialog.h"

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
}

GraphDialog::~GraphDialog()
{
    delete ui;
}
void GraphDialog::Show_list()
{
    string comando="dot -Tjpeg graph.dot. -o graph.jpeg";
    system(comando.c_str());

}

void GraphDialog::on_btn_insert_clicked()
{
    this->g.insertarVertice(this->ui->txt_value->toPlainText().toStdString()[0]);
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
}


void GraphDialog::on_btn_insertA_clicked()
{
    this->g.insertarArista(this->ui->txt_value2->toPlainText().toStdString()[0],this->ui->txt_value3->toPlainText().toStdString()[0]);
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
}


void GraphDialog::on_btn_delete_clicked()
{
    this->g.eliminarVertice(this->ui->txt_value->toPlainText().toStdString()[0]);
    g.show();
    Show_list();
    QPixmap pix("graph.jpeg");
    ui->label_4->setPixmap(pix);
}





void GraphDialog::on_btn_regresarG_clicked()
{
    this->close();
}

