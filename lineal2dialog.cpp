#include "lineal2dialog.h"
#include "ui_lineal2dialog.h"
#include <QFileDialog>

lineal2Dialog::lineal2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lineal2Dialog)
{
    ui->setupUi(this);
}

lineal2Dialog::~lineal2Dialog()
{
    delete ui;
}
void lineal2Dialog::Show_list()
{


    string comando="dot -Tjpeg double_linked_list.dot. -o double_linked_list.jpeg";
    system(comando.c_str());




}
void lineal2Dialog::on_btn_insert_clicked()
{
    this->LD.insert_at(this->ui->txt_value->toPlainText().toInt(),this->ui->txt_value2->toPlainText().toInt());
    LD.show();
    Show_list();
    QPixmap pix("double_linked_list.jpeg");
    ui->label_3->setPixmap(pix);
}
void lineal2Dialog::on_btn_regresarLD_clicked()
{
    this->close();
}

void lineal2Dialog::on_pushButton_3_clicked()
{
    LD.show(LD.find(this->ui->txt_value2->toPlainText().toInt()));
    Show_list();
    QPixmap pix("double_linked_list.jpeg");
    ui->label_3->setPixmap(pix);
}

