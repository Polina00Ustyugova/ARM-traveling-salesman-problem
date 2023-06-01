#include "case3.h"
#include "ui_case3.h"
#include "case1.h"
#include "case2.h"
// ПРИ ВОЗМОЖНОСТИ ДОБАВИТЬ ФОТО К ПОДОЗРЕВАЕМЫМ
// ПРИ ВОЗМОЖНОСТИ ОРГАНИЗОВАТЬ ДОБАВЛЕНИЕ СТРОК
// ПРИ ВОЗМОЖНОСТИ ОРГАНИЗОВАТЬ ДОБАВЛЕНИЕ И УДАЛЕНИЕ СТРОК
case3::case3(QWidget *parent, QSqlDatabase* db) :
    QDialog(parent),
    ui(new Ui::case3),
    db(db)
{
    ui->setupUi(this);
    model = new QSqlTableModel(nullptr, *db);
    model->setTable("criminal");
    model->setFilter("criminalID = '3'");
    //model->setTable("criminal");
    //model->setFilter("criminalID = '3'");
    //model->setFilter(QString());
    model->select();

    ui->tableView->setModel(model);
}

case3::~case3()
{
    delete ui;
}
int table = 0;
void case3::on_pushButton_clicked()
{
    table = 2;
    model->setTable("hurtman");
    model->setFilter("hurtID = '3'");
    model->select();
    ui->tableView->setModel(model);
}


void case3::on_pushButton_2_clicked()
{
    table = 1;
    model->setTable("criminal");
    model->setFilter("criminalID = '3'");
    model->select();
    ui->tableView->setModel(model);
}


void case3::on_pushButton_3_clicked()
{
    table = 3;
    model->setTable("Murder_case");
    model->setFilter("CaseID = '3'");
    model->select();
    ui->tableView->setModel(model);
}


void case3::on_pushButton_4_clicked()
{
    model->insertRow(model->rowCount());
}


void case3::on_tableView_clicked(const QModelIndex &index)
{
    DelRow = index.row();
    QSqlQuery query = QSqlQuery(*db);
    if (table == 1)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, Foto_adress FROM criminal WHERE ID =:id AND CriminalID = 3");
        int real_row = index.row() + 1;
        query.bindValue(":id", real_row);
        if(query.exec())
        {
            query.next();
            ui->nameinf->setText(query.value(0).toString());
            ui->dateinf->setText(query.value(1).toString());
            ui->phoneinf->setText(query.value(2).toString());
            ui->adressinf->setText(query.value(3).toString());
            ui->foto->setScaledContents(true);
            ui->foto->setPixmap(QPixmap(query.value(4).toString()));
        }
    }
    else if (table == 2)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, status, Foto FROM hurtman WHERE ID =:id AND hurtID = 3");
        int real_row = index.row() + 1;
        query.bindValue(":id", real_row);
        if(query.exec())
        {
            query.next();
            ui->nameinf->setText(query.value(0).toString());
            ui->dateinf->setText(query.value(1).toString());
            ui->phoneinf->setText(query.value(2).toString());
            ui->adressinf->setText(query.value(3).toString());
            ui->status->setText(query.value(4).toString());
            ui->foto->setScaledContents(true);
            ui->foto->setPixmap(QPixmap(query.value(5).toString()));
        }
    }
    else if (table == 3)
    {
        query.prepare("SELECT Case_history, Case_evidence, Foto FROM Murder_case WHERE ID =:id AND CaseID = 3");
        int real_row = index.row() + 1;
        query.bindValue(":id", real_row);
        if(query.exec())
        {
            query.next();
            ui->nameinf->setText(query.value(0).toString());
            ui->dateinf->setText(query.value(1).toString());
            ui->foto->setScaledContents(true);
            ui->foto->setPixmap(QPixmap(query.value(2).toString()));
        }
    }
}


void case3::on_pushButton_5_clicked()
{
    model->removeRow(DelRow);
}


void case3::on_download_foto_clicked()
{
    adress = QFileDialog::getOpenFileName(0, "Загрузить изображение", "/", "*.(*)");
    ui->foto->setScaledContents(true);
    ui->foto->setPixmap(QPixmap(adress));
    ui->FIO->setText(adress);
}


void case3::on_pushButton_6_clicked()
{
    close();
    Case2 window(nullptr, db);
    window.setModal(true);
    window.exec();
}


void case3::on_pushButton_7_clicked()
{
    close();
    Case1 window(nullptr, db);
    window.setModal(true);
    window.exec();
}

