#include "sparsedialog.h"
#include "ui_sparsedialog.h"

SparseDialog::SparseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SparseDialog)
{
    ui->setupUi(this);
}

SparseDialog::~SparseDialog()
{
    delete ui;
}
void SparseDialog::Show_list()
{
    string comando="dot -Tjpeg sparse.dot. -o sparse.jpeg";
    system(comando.c_str());

}

void SparseDialog::on_btn_insert_clicked()
{
    this->m.Insert(this->ui->txt_value->toPlainText().toInt(),this->ui->txt_value2->toPlainText().toInt(),this->ui->txt_value3->toPlainText().toInt());
    m.show();
    Show_list();
    QPixmap pix("sparse.jpeg");
    ui->label_3->setPixmap(pix);
}


void SparseDialog::on_btn_regresarS_clicked()
{
    this->close();
}

