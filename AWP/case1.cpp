#include "case1.h"
#include "ui_case1.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "case2.h"
#include "case3.h"
// ПРИ ВОЗМОЖНОСТИ ДОБАВИТЬ ФОТО К ПОДОЗРЕВАЕМЫМ
Case1::Case1(QWidget *parent, QSqlDatabase* db) :
    QDialog(parent),
    ui(new Ui::Case1),
    db(db)
{
    ui->setupUi(this);
    model = new QSqlTableModel(nullptr, *db);
    model->setTable("criminal");
    model->setFilter("criminalID = '1'");
    model->select();
    ui->tableView->setModel(model);

}
int table2 = 0;
Case1::~Case1()
{
    delete ui;
    delete model;
}

void Case1::on_Show_hurtman_clicked()
{
    table2 = 2;
    model->setTable("hurtman");
    model->setFilter("hurtID = '1'");
    model->select();
    ui->tableView->setModel(model);
}


void Case1::on_Show_criminal_clicked()
{
    table2 = 1;
    model->setTable("criminal");
    model->setFilter("criminalID = '1'");
    model->select();
    ui->tableView->setModel(model);
}


void Case1::on_Show_case_clicked()
{
    table2 = 3;
    model->setTable("Murder_case");
    model->setFilter("CaseID = '1'");
    model->select();
    ui->tableView->setModel(model);
}


void Case1::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
}


void Case1::on_pushButton_2_clicked()
{
    model->removeRow(DelRow);
}


void Case1::on_tableView_clicked(const QModelIndex &index)
{
    DelRow = index.row();
    QSqlQuery query = QSqlQuery(*db);
    if (table2 == 1)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, Foto_adress FROM criminal WHERE ID =:id AND CriminalID = 1");
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
    else if (table2 == 2)
    {
        query.prepare("SELECT name, dateBirth, phone, adress, status, Foto FROM hurtman WHERE ID =:id AND hurtID = 1");
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
    else if (table2 == 3)
    {
        query.prepare("SELECT Case_history, Case_evidence, Foto FROM Murder_case WHERE ID =:id AND CaseID = 1");
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


void Case1::on_download_foto_clicked()
{
    adress = QFileDialog::getOpenFileName(0, "Загрузить изображение", "/", "*.(*)");
    ui->foto->setScaledContents(true);
    ui->foto->setPixmap(QPixmap(adress));
    ui->FIO->setText(adress);
}


void Case1::on_pushButton_5_clicked()
{
    close();
    case3 window(nullptr, db);
    window.setModal(true);
    window.exec();
}


void Case1::on_pushButton_4_clicked()
{
    close();
    Case2 window(nullptr, db);
    window.setModal(true);
    window.exec();
}

