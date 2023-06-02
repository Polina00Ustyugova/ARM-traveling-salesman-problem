#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <algorithm>
#include <cmath>
#include <QMessageBox>


int maxi=10;
float inf = 1e10;
QVector<int> path;
QVector<QVector<float>> d((1 << maxi), QVector<float>(maxi));

void findway(QVector<QVector<float> > g, int n)
{
    int k = 0;
    int mask = (1 << n) - 1;
    path.push_back(0);
    while (mask != 0)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[k][j])
                if ((mask & (1 << j)))
                    if (d[mask][k] == g[k][j] + d[mask ^ (1 << j)][j])
                    {
                        path.push_back(j);
                        k = j;
                        mask = mask ^ (1 << j);
                    }
        }
    }
}

float findcheapest(int i, int mask, QVector<QVector<float> > g, int n)
{
    if (d[mask][i] != inf)
    {
        return d[mask][i];
    }
    for (int j = 0; j < n; j++)
    {
        if (g[i][j])
            if ((mask & (1 << j)))
            {

                d[mask][i] = qMin(d[mask][i], findcheapest(j, mask - (1<<j), g,n) + g[i][j]);
            }
    }
    return d[mask][i];
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graph = new cityitem();
    connect(graph, &cityitem::firstwindow, this, &MainWindow::show);
    connect(this, SIGNAL(send_data_vert(int)), graph, SLOT(recievData(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Create_clicked()
{
    int size = ui->City->text().toInt();
    if (size > 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа равен 10!");
    else
    {
        ui->LinksTable->setRowCount(size);
        ui->LinksTable->setColumnCount(size);
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ui->LinksTable->setItem(i,j,new QTableWidgetItem(temp));
            }
        }
        n = size;
        for(int i = 0; i < size;i++)
        {
            ui->LinksTable->setColumnWidth(i,1);
            ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
            ui->LinksTable->item(i, i)->setText("0");
        }
    }
}
bool MainWindow::empty()
{
    for(int i = 0; i < n; i++)
    {
        for(int j  = 0; j < n; j++)
        {
            if(!(ui->LinksTable->item(i,j)))
            {
                QMessageBox::warning(this, "Ошибка", "Запишите информацию во все ячейки.");
                return 0;
            }
        }
    }
    return 1;
}
bool MainWindow::chain()
{
    for(int i = 0; i < n; i++)
    {
        if(ui->LinksTable->item(i,i)->text() != "0")
        {
            QMessageBox::warning(this, "Ошибка", "Не создавайте путь между одним и тем же городом.");
            return 0;
        }
    }
    return 1;
}
bool MainWindow::table()
{
    if (n > 1) return 1;
    QMessageBox::warning(this, "Ошибка", "Для использования данной функции создайте таблицу.");
    return 0;
}
void MainWindow::on_Answer_clicked()
{
    if(empty() && chain() && table())
    {
        QVector<QVector<float> > g(n, QVector<float>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                g[i][j] = ui->LinksTable->item(i,j)->text().toFloat();
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int mask = 0; mask < (1 << n); mask++)
            {
                d[mask][i] = inf;
            }
        }
        d[0][0] = 0;
        ans = findcheapest(0, (1 << n) - 1, g, n);
        findway(g, n);

        for (int i = 0; i < n; i++){
            path[i]+=1;
        }
        QString answer;
        for (int i = 0; i < n; i++)
        {
            answer = answer + QString::number(path[i]) + " -> ";
        }
        answer += '1';
        answer = answer + "   length = " + QString::number(ans);
        QMessageBox::information(this, "Решение", answer);
        path.clear();
    }
}
void MainWindow::on_Visual_clicked()
{
   if (n > 10 || n <= 1)
   {
       if (n > 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа равен 10!");
       else QMessageBox::warning(this, "Ошибка", "Размер графа не может быть равен 0!");
   }
   else
   {
       if (empty() && chain())
       {
           graph->set_size(n);
           for (int i = 0; i < n; ++i)
           {
               for (int j = 0; j < n; ++j)
               {
                   graph->temp.push_back(ui->LinksTable->item(i,j)->text().toInt());
               }
               graph->matrix_graph.push_back(graph->temp);
               graph->temp.clear();
           }
           graph->show();
           graph->receiveData(n);
       }
   }
}


void MainWindow::on_Accept_clicked()
{
    if (n == 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа был достигнут!");
    else
    {
        n += 1;
        ui->LinksTable->setRowCount(n);
        ui->LinksTable->setColumnCount(n);
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            ui->LinksTable->setRowHeight(i,1);
            ui->LinksTable->setColumnWidth(i,1);
            ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
            ui->LinksTable->item(i, i)->setText("0");
        }
        ui->City->setText(QString::number(n));
    }
}

void MainWindow::on_Accept_2_clicked()
{
    n -= 1;
    ui->LinksTable->setRowCount(n);
    ui->LinksTable->setColumnCount(n);
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        ui->LinksTable->setRowHeight(i,1);
        ui->LinksTable->setColumnWidth(i,1);
        ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
        ui->LinksTable->item(i, i)->setText("0");
    }
    ui->City->setText(QString::number(n));
}

