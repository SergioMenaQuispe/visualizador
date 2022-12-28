#include "linealdialog.h"
#include "ui_linealdialog.h"
#include <QFileDialog>

LinealDialog::LinealDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinealDialog)

{
    ui->setupUi(this);

}

LinealDialog::~LinealDialog()
{
    delete ui;
}


void LinealDialog::Show_list()
{


    string comando="dot -Tjpeg linked_list.dot. -o linked_list.jpeg";
    system(comando.c_str());




}
void LinealDialog::on_btn_insert_clicked()
{


    this->L.insert_front(this->ui->txt_value->toPlainText().toInt());
    L.show();
    Show_list();
    QPixmap pix("linked_list.jpeg");
    ui->label_2->setPixmap(pix);

}
void LinealDialog::on_btn_inset_last_clicked()
{
    this->L.insert_last(this->ui->txt_value->toPlainText().toInt());
    L.show();
    Show_list();
    QPixmap pix("linked_list.jpeg");
    ui->label_2->setPixmap(pix);
}


void LinealDialog::on_btn_vizu_clicked()
{

}




void LinealDialog::on_btn_regresar_clicked()
{
    this->close();
}


void LinealDialog::on_btn_delete_clicked()
{
    this->L.delete_front();
    L.show();
    Show_list();
    QPixmap pix("linked_list.jpeg");
    ui->label_2->setPixmap(pix);
}
void LinealDialog::on_btn_delete_last_clicked()
{
    this->L.delete_last();
    L.show();
    Show_list();
    QPixmap pix("linked_list.jpeg");
    ui->label_2->setPixmap(pix);
}


void LinealDialog::on_btn_find_clicked()
{

   L.show(L.find(this->ui->txt_value->toPlainText().toInt()));
   Show_list();
   QPixmap pix("linked_list.jpeg");
   ui->label_2->setPixmap(pix);
}








