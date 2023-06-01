#include "case2.h"
#include "ui_case2.h"
#include <QDebug>
#include "case1.h"
#include "case3.h"

// ПРИ ВОЗМОЖНОСТИ ДОБАВИТЬ ФОТО К ПОДОЗРЕВАЕМЫМ
Case2::Case2(QWidget *parent, QSqlDatabase* db) :
    QDialog(parent),
    ui(new Ui::Case2),
    db(db)
{
    ui->setupUi(this);
    model = new QSqlTableModel(nullptr, *db);
    model->setTable("criminal");
    model->setFilter("criminalID = '2'");
    model->select();
    ui->tableView->setModel(model);
}

Case2::~Case2()
{
    delete ui;
}
int table3 = 0;
void Case2::on_pushButton_2_clicked()
{
    table3 = 2;
    model->setTable("hurtman");
    model->setFilter("hurtID = '2'");
    model->select();
    ui->tableView->setModel(model);
}


void Case2::on_pushButton_clicked()
{
    table3 = 1;
    model->setTable("criminal");
    model->setFilter("criminalID = '2'");
    model->select();
    ui->tableView->setModel(model);
}


void Case2::on_pushButton_3_clicked()
{
    table3 = 3;
    model->setTable("Murder_case");
    model->setFilter("CaseID = '2'");
    model->select();
    ui->tableView->setModel(model);
}


void Case2::on_Insert_Row_clicked()
{
    model->insertRow(model->rowCount());
}


void Case2::on_tableView_clicked(const QModelIndex &index)
{
    DelRow = index.row();
    QSqlQuery query = QSqlQuery(*db);
    if (table3 == 1)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, Foto_adress FROM criminal WHERE ID =:id AND CriminalID = 2");
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
    else if (table3 == 2)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, status, Foto FROM hurtman WHERE ID =:id AND hurtID = 2");
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
    else if (table3 == 3)
    {
        query.prepare("SELECT Case_history, Case_evidence, Foto FROM Murder_case WHERE ID =:id AND CaseID = 2");
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


void Case2::on_Del_Row_clicked()
{
    model->removeRow(DelRow);
}


void Case2::on_download_foto_clicked()
{
    adress = QFileDialog::getOpenFileName(0, "Загрузить изображение", "/", "*.(*)");
    ui->foto->setScaledContents(true);
    ui->foto->setPixmap(QPixmap(adress));
    ui->FIO->setText(adress);
}


void Case2::on_pushButton_5_clicked()
{
    close();
    Case1 window(nullptr, db);
    window.setModal(true);
    window.exec();
}


void Case2::on_pushButton_4_clicked()
{
    close();
    case3 window(nullptr, db);
    window.setModal(true);
    window.exec();
}

