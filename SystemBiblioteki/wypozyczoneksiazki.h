#ifndef WYPOZYCZONEKSIAZKI_H
#define WYPOZYCZONEKSIAZKI_H

#include <QDialog>

namespace Ui {
class wypozyczoneKsiazki;
}

class wypozyczoneKsiazki : public QDialog
{
    Q_OBJECT

public:
    explicit wypozyczoneKsiazki(QWidget *parent = 0);
    ~wypozyczoneKsiazki();

private slots:
    void on_przyciskWyjdz_clicked();

    void on_PrzyciskPrzedluzZwrot_clicked();

    void on_pushButton_clicked();

private:
    Ui::wypozyczoneKsiazki *ui;
};

#endif // WYPOZYCZONEKSIAZKI_H
