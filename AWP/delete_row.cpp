#include "delete_row.h"
#include "ui_delete_row.h"
#include <QSqlQuery>
#include <QDebug>

Delete_Row::Delete_Row(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_Row)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\Case_victim");
    if (db.open()) {
        qDebug() << "Success";
    }
    else { qDebug() << "not success"; }
}

Delete_Row::~Delete_Row()
{
    delete ui;
}


