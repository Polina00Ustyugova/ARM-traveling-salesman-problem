#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>

namespace Ui {
class authorization;
}
class authorization : public QDialog
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();
private slots:
    void on_pushButton_clicked();

private:
    Ui::authorization *ui;
    QSqlDatabase db;

};
#endif // AUTHORIZATION_H
