#include "registration_window.h"
#include "ui_registration_window.h"
#include <QString>
#include <QDebug>

Registration_window::Registration_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration_window)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\Case_victim");
    if (db.open()) {
        qDebug() << "Success";
    }
    else { qDebug() << "not success"; }
}

Registration_window::~Registration_window()
{
    delete ui;
}

