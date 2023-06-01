#ifndef CASE1_H
#define CASE1_H

#include <QDialog>
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
namespace Ui {
class Case1;
}

class Case1 : public QDialog
{
    Q_OBJECT

public:
    explicit Case1(QWidget *parent = nullptr, QSqlDatabase *db = nullptr);
    ~Case1();
    QString adress = "";

private slots:
    void on_Show_hurtman_clicked();

    void on_Show_criminal_clicked();

    void on_Show_case_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_download_foto_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Case1 *ui;
    QSqlTableModel* model;
    QSqlDatabase* db;
    int DelRow;
};

#endif // CASE1_H
