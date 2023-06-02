#ifndef CITYITEM_H
#define CITYITEM_H

#include <QWidget>
#include <QPainter>
#include <QDebug>



namespace Ui {
class cityitem;
}

class cityitem : public QWidget
{
    Q_OBJECT

public:
    explicit cityitem(QWidget *parent = 0);
    ~cityitem();

    QVector<int> temp;
    QVector<QVector<int>> matrix_graph;

    void set_matrix(QVector<QVector<int>> matrix) { this->matrix_graph = matrix; }
    void set_size(int);
    void fill_matrix(int);
protected:

    void paintEvent(QPaintEvent *event);

public slots:

    void receiveData (int x);

signals:

    void firstwindow();

private slots:

    void on_back_clicked();

private:
    QVector<QString> name_list = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    int n;
    Ui::cityitem *ui;
};

#endif // CITYITEM_H
