#ifndef PRZEGLADAJKSIAZKI2_H
#define PRZEGLADAJKSIAZKI2_H

#include <QDialog>

namespace Ui {
class przegladajKsiazki2;
}

class przegladajKsiazki2 : public QDialog
{
    Q_OBJECT

public:
    explicit przegladajKsiazki2(QWidget *parent = 0);
    ~przegladajKsiazki2();

private slots:
    void on_przyciskWyjdz_clicked();

    void on_przyciskWyszukaj_clicked();

private:
    Ui::przegladajKsiazki2 *ui;
};

#endif // PRZEGLADAJKSIAZKI2_H
