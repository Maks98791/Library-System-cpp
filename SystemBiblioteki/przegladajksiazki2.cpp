#include "przegladajksiazki2.h"
#include "ui_przegladajksiazki2.h"
#include "ksiazka.h"
#include "bazaksiazek.h"
#include <QListWidget>
#include <fstream>
#include "bibliotekaczytelnik.h"

przegladajKsiazki2::przegladajKsiazki2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::przegladajKsiazki2)
{
    ui->setupUi(this);

    vector <Ksiazka> ksiazka;
    fstream plik;

    plik.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\plikKsiazki");

    if(plik.good() == false)
    {
        qApp->quit();
    }

    while(!plik.eof())
    {
        Ksiazka nowa;

        getline(plik, nowa.tytul);
        getline(plik, nowa.autor);
        getline(plik, nowa.data_wyp);
        getline(plik, nowa.data_zwrotu);

        ksiazka.push_back(nowa);
    }

    int elementy = ksiazka.size();

    plik.close();

    for(int i = 0; i < elementy; i++)
    {
        if(ksiazka[i].data_wyp == "na stanie")
        {
            string tytul = ksiazka[i].tytul;
            string autor = ksiazka[i].autor;
            QString qtytul = QString::fromStdString(tytul);
            QString qautor = QString::fromStdString(autor);
            ui->listaDostepnychKsiazek2->addItem(qtytul + " - " + qautor);
        }
    }
}

przegladajKsiazki2::~przegladajKsiazki2()
{
    delete ui;
}

void przegladajKsiazki2::on_przyciskWyjdz_clicked()
{
    hide();
}

void przegladajKsiazki2::on_przyciskWyszukaj_clicked()
{
    QString wyszukajTekst = ui->lineWyszukaj->text();
    int rozmiarListy = ui->listaDostepnychKsiazek2->count();

    for (int k = 0; k < rozmiarListy; k++)
    {
        if (ui->listaDostepnychKsiazek2->item(k)->text().startsWith(wyszukajTekst))
        {
             ui->listaDostepnychKsiazek2->item(k)->setHidden(false);
        }
        else
        {
             ui->listaDostepnychKsiazek2->item(k)->setHidden(true);
        }
    }
}
