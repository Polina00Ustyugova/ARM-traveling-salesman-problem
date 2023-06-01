#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Registration_window;
}

class Registration_window : public QDialog
{
    Q_OBJECT

public:
    explicit Registration_window(QWidget *parent = nullptr);
    ~Registration_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registration_window *ui;
    QSqlDatabase db;

};

#endif // REGISTRATION_WINDOW_H
