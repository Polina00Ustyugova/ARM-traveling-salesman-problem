#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_regestrationBTN_clicked();

    void on_entranceBTN_clicked();

    void on_CasesBTN_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
