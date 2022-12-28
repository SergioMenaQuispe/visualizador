#include "pilasdialog.h"
#include "ui_pilasdialog.h"

PilasDialog::PilasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PilasDialog)
{
    ui->setupUi(this);
}

PilasDialog::~PilasDialog()
{
    delete ui;
}
void PilasDialog::Show_list()
{
    string comando="dot -Tjpeg stack.dot. -o stack.jpeg";
    system(comando.c_str());

}
void PilasDialog::on_btn_regresarPi_clicked()
{
    this->close();
}


void PilasDialog::on_btn_insert_clicked()
{
    this->p.push(this->ui->txt_value->toPlainText().toInt());
    p.show();
    Show_list();
    QPixmap pix("stack.jpeg");
    ui->label_3->setPixmap(pix);
}


void PilasDialog::on_btn_delete_clicked()
{
    this->p.pop();
    p.show();
    Show_list();
    QPixmap pix("stack.jpeg");
    ui->label_3->setPixmap(pix);
}

