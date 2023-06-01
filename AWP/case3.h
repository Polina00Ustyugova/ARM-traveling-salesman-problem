#ifndef CASE3_H
#define CASE3_H

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
#include <QFileDialog>
#include <QSqlQuery>
namespace Ui {
class case3;
}

class case3 : public QDialog
{
    Q_OBJECT

public:
    explicit case3(QWidget *parent = nullptr, QSqlDatabase *db = nullptr);
    ~case3();
    QString adress = "";

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();


    void on_download_foto_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::case3 *ui;
    QSqlTableModel* model;
    QSqlDatabase* db;
    int DelRow;
};

#endif // CASE3_H
