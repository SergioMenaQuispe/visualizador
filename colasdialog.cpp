#include "colasdialog.h"
#include "ui_colasdialog.h"

ColasDialog::ColasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColasDialog)
{
    ui->setupUi(this);
}

ColasDialog::~ColasDialog()
{
    delete ui;
}
void ColasDialog::Show_list()
{
    string comando="dot -Tjpeg queque.dot. -o queque.jpeg";
    system(comando.c_str());

}
void ColasDialog::on_btn_insert_clicked()
{
    this->q.insert(this->ui->txt_value->toPlainText().toInt());
    q.show();
    Show_list();
    QPixmap pix("queque.jpeg");
    ui->label_3->setPixmap(pix);
}
void ColasDialog::on_btn_delete_clicked()
{
    this->q.remove();
    q.show();
    Show_list();
    QPixmap pix("queque.jpeg");
    ui->label_3->setPixmap(pix);
}


void ColasDialog::on_btn_regresarCo_clicked()
{
    this->close();
}








