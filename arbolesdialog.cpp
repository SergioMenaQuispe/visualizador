#include "arbolesdialog.h"
#include "ui_arbolesdialog.h"

ArbolesDialog::ArbolesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArbolesDialog)
{
    ui->setupUi(this);
}

ArbolesDialog::~ArbolesDialog()
{
    delete ui;
}
void ArbolesDialog::Show_list()
{
    string comando="dot -Tjpeg tree.dot. -o tree.jpeg";
    system(comando.c_str());

}

void ArbolesDialog::on_btn_insert_clicked()
{
    this->a.Add_r(this->ui->txt_value->toPlainText().toInt());
    a.show();
    Show_list();
    QPixmap pix("tree.jpeg");
    ui->label_2->setPixmap(pix);
}


void ArbolesDialog::on_btn_delete_clicked()
{
    this->a.Delete(this->ui->txt_value->toPlainText().toInt());
    a.show();
    Show_list();
    QPixmap pix("tree.jpeg");
    ui->label_2->setPixmap(pix);
}


void ArbolesDialog::on_btn_regresarA_clicked()
{
    this->close();
}


void ArbolesDialog::on_btn_find_clicked()
{
    a.show(a.find(this->ui->txt_value->toPlainText().toInt()));
    Show_list();
    QPixmap pix("tree.jpeg");
    ui->label_2->setPixmap(pix);
}


void ArbolesDialog::on_pushButton_4_clicked()
{
    a.show(a.Max());
    Show_list();
    QPixmap pix("tree.jpeg");
    ui->label_2->setPixmap(pix);
}


void ArbolesDialog::on_btn_minimo_clicked()
{
    a.show(a.Min());
    Show_list();
    QPixmap pix("tree.jpeg");
    ui->label_2->setPixmap(pix);
}

