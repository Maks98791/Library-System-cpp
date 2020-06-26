#ifndef OBECNICZYTELNICY_H
#define OBECNICZYTELNICY_H

#include <QDialog>

namespace Ui {
class ObecniCzytelnicy;
}

class ObecniCzytelnicy : public QDialog
{
    Q_OBJECT

public:
    explicit ObecniCzytelnicy(QWidget *parent = 0);
    ~ObecniCzytelnicy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObecniCzytelnicy *ui;
};

#endif // OBECNICZYTELNICY_H
