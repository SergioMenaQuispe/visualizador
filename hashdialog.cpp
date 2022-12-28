#include "hashdialog.h"
#include "ui_hashdialog.h"

HashDialog::HashDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HashDialog)
{
    ui->setupUi(this);
}

HashDialog::~HashDialog()
{
    delete ui;
}
void HashDialog::Show_list()
{
    string comando="dot -Tjpeg hash.dot. -o hash.jpeg";
    system(comando.c_str());

}
void HashDialog::on_btn_insert_clicked()
{
    this->h.Insert(this->ui->txt_value->toPlainText().toStdString(),this->ui->txt_value2->toPlainText().toInt());
    h.show();
    Show_list();
    QPixmap pix("hash.jpeg");
    ui->label_3->setPixmap(pix);
}


void HashDialog::on_btn_regresarH_clicked()
{
    this->close();
}


void HashDialog::on_btn_delete_clicked()
{
    this->h.delete_key(this->ui->txt_value->toPlainText().toStdString());
    h.show();
    Show_list();
    QPixmap pix("hash.jpeg");
    ui->label_3->setPixmap(pix);
}


void HashDialog::on_btn_find_clicked()
{

    h.show(h.find(this->ui->txt_value->toPlainText().toStdString()));
    Show_list();
    QPixmap pix("hash.jpeg");
    ui->label_2->setPixmap(pix);
}

