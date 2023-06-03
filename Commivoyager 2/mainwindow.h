#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cityitem.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct index{
    int ii;
    int jj;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    void fill_matrix();
    int n = -1;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //QVector<QVector<int>> get_matrix() {return this->matrix;};
    bool empty();
    bool chain();
    bool table();
    void find_way();

signals:
     void send_data_vert (int n);

private slots:
    void on_Create_clicked();

    void on_Answer_clicked();
    void on_Visual_clicked();
    void on_Accept_clicked();

    void on_Accept_2_clicked();

private:
    //QVector<QVector<int>> matrix
    Ui::MainWindow *ui;
    float ans;
    cityitem *graph;
    QVector<index> answer;
    QVector<QVector<int>> matrix_graph;
};
#endif // MAINWINDOW_H
