#ifndef PRZEGLADAJKSIAZKI_H
#define PRZEGLADAJKSIAZKI_H
#include <iostream>
#include <string>
#include <QDialog>

using namespace std;

namespace Ui {
class PrzegladajKsiazki;
}

class PrzegladajKsiazki : public QDialog
{
    Q_OBJECT

public:
    explicit PrzegladajKsiazki(QWidget *parent = 0);
    ~PrzegladajKsiazki();
    string date();
    string data_oddania();
    string data_przedluzenia();

private slots:
    void on_przyciskWyjdz_clicked();

    void on_PrzyciskRezerwuj_clicked();

    void on_przyciskWyszukaj_clicked();

private:
    Ui::PrzegladajKsiazki *ui;
};

#endif // PRZEGLADAJKSIAZKI_H
