#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration_window.h"
#include "authorization.h"
#include "cases.h"

#include <QDebug>
#include <QTableView>
#include <QDate>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>

#include <string>
#include <algorithm>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_regestrationBTN_clicked()
{
    Registration_window window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_entranceBTN_clicked()
{
    authorization window;
    window.setModal(true);
    window.exec();
}



