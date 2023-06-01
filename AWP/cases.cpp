#include "cases.h"
#include "ui_cases.h"
#include "ui_case1.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "case1.h"
#include "case2.h"
#include "case3.h"
#include "delete_row.h"
#include <QMessageBox>
#include <QMap>

QString m;
QString state;
QString date;
Cases::Cases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cases)
{
    ui->setupUi(this);
    // база данных
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\Case_victim");
    if (db.open()) {
        qDebug() << "Success";
    }
    else { qDebug() << "not success"; }
    // Названия дел и тд.
    // Case 1
    QSqlQuery query;
    query.exec("SELECT Case_name FROM Murder_case WHERE CaseID == 1");
    query.next();
    m = query.value(0).toString();
    // Case 2
    query.exec("SELECT Case_state FROM Murder_case WHERE CaseID == 1");
    query.next();
    state = query.value(0).toString();
    // Case 3
    query.exec("SELECT Date FROM Murder_case WHERE CaseID == 1");
    query.next();
    date = query.value(0).toString();
    // Labels change
    ui->State_name1->setText( QString( "%1" ).arg(state) );
    ui->date_inf1->setText( QString( "%1" ).arg(date) );
    ui->Name_murder1->setText( QString( "%1" ).arg(m) );
    // Case 2
    query.exec("SELECT Case_name FROM Murder_case WHERE CaseID == 2");
    query.next();
    m = query.value(0).toString();
    query.exec("SELECT Case_state FROM Murder_case WHERE CaseID == 2");
    query.next();
    state = query.value(0).toString();
    query.exec("SELECT Date FROM Murder_case WHERE CaseID == 2");
    query.next();
    date = query.value(0).toString();
    ui->State_name2->setText( QString( "%1" ).arg(state) );
    ui->date_inf2->setText( QString( "%1" ).arg(date) );
    ui->Name_murder2->setText( QString( "%1" ).arg(m) );
    // Case 3
    query.exec("SELECT Case_name FROM Murder_case WHERE CaseID == 3");
    query.next();
    m = query.value(0).toString();
    query.exec("SELECT Case_state FROM Murder_case WHERE CaseID == 3");
    query.next();
    state = query.value(0).toString();
    query.exec("SELECT Date FROM Murder_case WHERE CaseID == 3");
    query.next();
    date = query.value(0).toString();
    ui->State_name3->setText( QString( "%1" ).arg(state) );
    ui->date_inf3->setText( QString( "%1" ).arg(date) );
    ui->Name_murder3->setText( QString( "%1" ).arg(m) );
}
Cases::~Cases()
{
    delete ui;
}


void Cases::on_Edit_case1_clicked()
{
        Case1 window(nullptr, &db);
        window.setModal(true);
        window.exec();
}
void Cases::on_Edit_case2_clicked()
{
        Case2 window(nullptr, &db);
        window.setModal(true);
        window.exec();
}
void Cases::on_Edit_case3_clicked()
{
        case3 window(nullptr, &db);
        window.setModal(true);
        window.exec();
}
int i = 2;
void Cases::on_Delete_case1_clicked()
{
    i = 1;
    Delete_Row window(nullptr);
    window.setModal(true);
    window.exec();
}



void Cases::on_Delete_case2_clicked()
{
    i = 2;
    Delete_Row window(nullptr);
    window.setModal(true);
    window.exec();
}


void Cases::on_Delete_case3_clicked()
{
    i = 3;
    Delete_Row window(nullptr);
    window.setModal(true);
    window.exec();
}
void Delete_Row::on_yes_clicked()
{
    QSqlQuery q_del = QSqlQuery(db);
    q_del.prepare("DELETE FROM Murder_case WHERE CaseID =:i ");
    q_del.bindValue(":i", i);
    q_del.exec();
    q_del.prepare("DELETE FROM hurtman WHERE hurtID =:i ");
    q_del.bindValue(":i", i);
    q_del.exec();
    q_del.prepare("DELETE  FROM criminal WHERE criminalID =:i ");
    q_del.bindValue(":i", i);
    q_del.exec();
}
