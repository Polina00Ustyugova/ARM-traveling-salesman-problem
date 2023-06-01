#ifndef DELETE_ROW_H
#define DELETE_ROW_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Delete_Row;
}

class Delete_Row : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_Row(QWidget *parent = nullptr);
    ~Delete_Row();

private slots:
    void on_yes_clicked();

private:
    Ui::Delete_Row *ui;
    QSqlDatabase db;
};

#endif // DELETE_ROW_H
