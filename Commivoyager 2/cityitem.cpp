#include "cityitem.h"
#include "ui_cityitem.h"
#include <QtMath>
#include "mainwindow.h"

cityitem::cityitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cityitem)
{
    ui->setupUi(this);
}

void cityitem::set_size(int new_size)
{
    this -> n = new_size;
}

cityitem::~cityitem()
{
    delete ui;
}
// Отрисовка графа
void cityitem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

        int y, x = -150;
        int r = 150;
        int len = 300/(n/2);
        int **citycoords = new int*[n];
        for(int i = 0; i < n; i++)
        {
            citycoords[i] = new int[2];
        }
        int k = 0;
        for(int i = 0; i < n/2; i++)
        {
            y = qSqrt(r*r - x*x);
            citycoords[k][0] = 200 - x;
            citycoords[k][1] = 200 - y;
            k++;
            x += len;
        }
        x = 150;
        if(n%2 == 0)
        {
            for(int i = 0; i < n/2; i++)
            {
                y = qSqrt(r*r - x*x)*(-1);
                citycoords[k][0] = 200 - x;
                citycoords[k][1] = 200 - y;
                k++;
                x -= len;
            }
        }
        else
        {
            len = 300/(n/2 + 1);
            for(int i  =0; i < n/2 + 1; i++)
            {
                y = qSqrt(r*r - x*x)*(-1);
                citycoords[k][0] = 200 - x;
                citycoords[k][1] = 200 - y;
                k++;
                x -= len;
            }
        }
        //int kk = 0;
        //int count = 0;
        // Отрисовка рёбер
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < n ;j++)
           {
               if(matrix_graph[i][j] != "0" && matrix_graph[j][i] != "0")
               {
                   QPen pen(Qt::black, 2, Qt::SolidLine);
                   painter.setPen(pen);
                   painter.drawLine(citycoords[i][0]+25, citycoords[i][1]+25, citycoords[j][0]+25, citycoords[j][1]+25);
                   //count += 1;
                   //QString name = matrix_graph[j][i] + " -> " + count;
                   //painter.drawText(citycoords[i][0]+15, citycoords[i][1]+60, name);
                   //painter.drawText(citycoords[i][0]+15, citycoords[i][1]+70, matrix_graph[j][i]);
                   //int centerX1 = (citycoords[j][0]+25 - citycoords[i][0]+25)/2 + 190;
                   //int centerY1 = (citycoords[j][1]+25 - citycoords[i][1]+25)/2 + 550;
                   //sourcePoint.setX(centerX1); sourcePoint.setY(centerY1);
                   //double cos1 = (citycoords[j][1]+25 - citycoords[i][1]+25 + 190)/(citycoords[j][0]+25 - citycoords[i][0]+25 + 550);
                   //QPointF first;
                   //first.setX(centerX1); first.setY(centerY1);
                   //painter.drawText(centerX1*cos1, centerY1*cos1, matrix_graph[i][j]);
                   //int centerX2 = (citycoords[j][0]+25 - citycoords[i][0]+25)/2 + 290;
                   //int centerY2 = (citycoords[j][1]+25 - citycoords[i][1]+25)/2 + 550;
                   //destPoint.setX(centerX2); destPoint.setY(centerY2);
                  // QLineF line(sourcePoint, destPoint);
                   //painter.drawLine(line);
                   //painter.drawText((sourcePoint*0.8+destPoint)/2, matrix_graph[j][i]);
                   //double cos2 = (citycoords[j][1]+25 - citycoords[i][1]+25)/(citycoords[j][0]+25 - citycoords[i][0]+25);
                   //QPointF second;
                   //second.setX(centerX2); first.setY(centerY2);
                   //painter.drawText((first*0.8 + second)/2, matrix_graph[j][i]);
                   //painter.drawText(centerX2*cos1, centerY2*cos1, matrix_graph[j][i]);
                   //kk++;
               }
           }
        }

        for(int i = 0; i < n ; i++)
        {
            // Контур вершин
            QPen pen1(Qt::black, 2, Qt::SolidLine);
            painter.setPen(pen1);
            // Вершины
            painter.setBrush(QBrush(QColor(159,186,199,255), Qt::SolidPattern));
            painter.drawEllipse(citycoords[i][0], citycoords[i][1], 50, 50);
            painter.setFont(QFont(QString::number(i+1),14));
            // Текст внутри вершин графа
            QPen pen2(QColor(138,69,153,255), 2, Qt::SolidLine);
            painter.setPen(pen2);
            painter.drawText(citycoords[i][0]+15, citycoords[i][1]+30, name_list[i]);
        }
}


void cityitem::receiveData(int x)
{
    n = x;
}
void cityitem::on_back_clicked()
{
    this->close();
    this->matrix_graph.clear();
    emit firstwindow();
}


