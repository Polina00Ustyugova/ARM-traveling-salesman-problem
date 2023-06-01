#include "authorization.h"
#include "ui_authorization.h"
#include "registration_window.h"
#include "ui_registration_window.h"
#include "mainwindow.h"
#include "cases.h"
#include <QMessageBox>
#include <iostream>
#include <QVector>
#include <QSqlQuery>
#include <QDebug>
bool founded = 0;
struct Users
{
    QString name;
    QString pass;
};
authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\Case_victim");
    if (db.open()) {
        qDebug() << "Success";
    }
    else { qDebug() << "not success"; }
}

authorization::~authorization()
{
    delete ui;

}
QVector <Users> list;
void authorization::on_pushButton_clicked()
{
    QString login = ui->Name->text();
    QString parol = ui->Parol->text();
    QSqlQuery query1 = QSqlQuery(db);
    QString check = QString("SELECT Login, Password, Right FROM Users "
                            "WHERE Login = '%1' AND "
                            "Password = '%2' AND "
                            "Right = 'true'" ).arg(login, parol);
    if(query1.exec(check)&& query1.next()) founded = 1;
    // СООБЩЕНИЕ ПРИ УСПЕШНОЙ АВТОРИЗАЦИИ
    if (founded)
        QMessageBox::information(this, "Вход", "Вы успешно зашли");
    else
    {
        check = QString("SELECT Login, Password, Right FROM Users "
                                "WHERE Login = '%1' AND "
                                "Password = '%2'").arg(login, parol);
        // СООБЩЕНИЕ ПРИ ОТКАЗАННОМ ДОСТУПЕ
        if(query1.exec(check) && query1.next())
            QMessageBox::warning(this, "Ошибка", "Простите, вам отказано в доступе!");
        // СООБЩЕНИЕ ПРИ ОТСУТСТВИИ У ПОЛЬЗОВАТЕЛЯ АККАУНТА
        else
            QMessageBox::warning(this, "Ошибка", "Такой пользователь не был найден!");
    }
}
void Registration_window::on_pushButton_clicked()
{
    QString login = ui->new_name->text();
    QString parol = ui->new_parol->text();
    if (login == "" || parol == "")
    {
        QMessageBox::warning(this, "Ошибка", "Ваши логин или пароль не могут быть пустыми!");
    }
    else
    {
        QSqlQuery q = QSqlQuery(db);
        q.exec("INSERT INTO Users (Login, Password, Right) "
                "VALUES (?, ?, ?)");
        q.addBindValue(login);
        q.addBindValue(parol);
        q.addBindValue("false");
        q.exec();
        QMessageBox::information(this, "Заявка принята", "Заявляние на регистрацию принято, ожидайте ответа.");
    }
}
void MainWindow::on_CasesBTN_clicked()
{
    //founded = 1; // ПОТОМ УБРАТЬ
    if(founded)
    {
        Cases window;
        window.setModal(true);
        window.exec();
    }
    else
        QMessageBox::warning(this, "Ошибка", "Не авторизированным пользователям данная функция недоступна!");
}


