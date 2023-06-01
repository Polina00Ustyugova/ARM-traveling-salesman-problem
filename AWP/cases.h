#ifndef CASES_H
#define CASES_H

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
class Cases;
}

class Cases : public QDialog
{
    Q_OBJECT

public:
    explicit Cases(QWidget *parent = nullptr);
    ~Cases();

private slots:

    void on_Edit_case1_clicked();

    void on_Edit_case2_clicked();

    void on_Edit_case3_clicked();

    void on_Delete_case1_clicked();

    void on_Delete_case2_clicked();

    void on_Delete_case3_clicked();

private:
    Ui::Cases *ui;
    QSqlDatabase db;

};

#endif // CASES_H
