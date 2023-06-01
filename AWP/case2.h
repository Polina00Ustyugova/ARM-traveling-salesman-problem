#ifndef CASE2_H
#define CASE2_H

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
class Case2;
}

class Case2 : public QDialog
{
    Q_OBJECT

public:
    explicit Case2(QWidget *parent = nullptr, QSqlDatabase *db = nullptr);
    ~Case2();
    QString adress = "";

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_Insert_Row_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Del_Row_clicked();

    void on_download_foto_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Case2 *ui;
    QSqlTableModel* model;
    QSqlDatabase* db;
    int DelRow;
};

#endif // CASE2_H
