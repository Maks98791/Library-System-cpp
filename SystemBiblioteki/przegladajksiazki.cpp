#include "przegladajksiazki.h"
#include "ui_przegladajksiazki.h"
#include "ksiazka.h"
#include "bazaksiazek.h"
#include <QListWidget>
#include <fstream>
#include "bibliotekaczytelnik.h"
#include <windows.h>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

string PrzegladajKsiazki::date()
{
    SYSTEMTIME stime;
    GetLocalTime(&stime);

    char buf[40] = {0};

    sprintf(buf,"%02d/%02d/%04d", stime.wDay, stime.wMonth, stime.wYear);

    string dt = buf;

    return dt;
}

string PrzegladajKsiazki::data_oddania()
{
    SYSTEMTIME stime;
    GetLocalTime(&stime);

    char buff[40] = {0};

    sprintf(buff,"%02d/%02d/%04d", stime.wDay, stime.wMonth+1, stime.wYear);

    string oddanie = buff;

    return oddanie;
}

string PrzegladajKsiazki::data_przedluzenia()
{
    SYSTEMTIME stime;
    GetLocalTime(&stime);

    char buff[40] = {0};

    sprintf(buff,"%02d/%02d/%04d", stime.wDay+5, stime.wMonth+3, stime.wYear);

    string oddanie = buff;

    return oddanie;
}

PrzegladajKsiazki::PrzegladajKsiazki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrzegladajKsiazki)
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

    for(int i = 0; i < elementy; i++)
    {
        if(ksiazka[i].data_wyp == "na stanie")
        {
            string tytul = ksiazka[i].tytul;
            string autor = ksiazka[i].autor;
            QString qtytul = QString::fromStdString(tytul);
            QString qautor = QString::fromStdString(autor);
            ui->listaDostepnychKsiazek->addItem(qtytul + " - " + qautor);
        }
    }
    plik.close();
}

PrzegladajKsiazki::~PrzegladajKsiazki()
{
    delete ui;
}

void PrzegladajKsiazki::on_przyciskWyjdz_clicked()
{
    hide();
}

void PrzegladajKsiazki::on_PrzyciskRezerwuj_clicked() //zarezerwowanie wybranej książki
{
    fstream ksiazki;
    fstream obecnaOsoba;
    fstream wypozyczone;

    obecnaOsoba.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\obecnyCzytelnik", ios::in);

    if(obecnaOsoba.good() == false)
    {
        qApp->quit();
    }

    string imie, nazwisko;
    QString wybrane;

    obecnaOsoba >> imie >> nazwisko;

    wypozyczone.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\"
                     + imie + nazwisko + ".txt", fstream::app);

    if(wypozyczone.good() == false)
    {
        qApp->quit();
    }

    foreach(QListWidgetItem *ksiazka, ui->listaDostepnychKsiazek->selectedItems())
        wybrane = ksiazka->text();

    string wypozyczonaKsiazka;
    string dataWypozyczenia = date();
    string dataOddania = data_oddania();

    wypozyczonaKsiazka = wybrane.toStdString();

    ksiazki.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\plikKsiazki", ios::in);

    if(ksiazki.good() == false)
    {
        qApp->quit();
    }

    int i = 0;

    while(!ksiazki.eof())
    {
        string a, b;
        getline(ksiazki, a);
        getline(ksiazki, b);
        i+=2;
        string calosc = a + " - " + b;

        if(strcmp(calosc.c_str(), wypozyczonaKsiazka.c_str()) == 0)
        {
            fstream temp;
            temp.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\temp", ios::app);
            if(temp.good() == false)
            {
                qApp->quit();
            }

            ksiazki.seekg(0, ios_base::beg);

            for(int j=1; j <= i; j++)
            {
                string wiersz;
                getline(ksiazki, wiersz);
                temp.write(&wiersz[0], wiersz.length());
                temp.write("\n", 1);
            }

            string temp1, temp2;
            temp.write(&dataWypozyczenia[0], dataWypozyczenia.length());
            temp.write("\n", 1);
            getline(ksiazki, temp1);
            temp.write(&dataOddania[0], dataOddania.length());
            getline(ksiazki, temp2);
            temp.write("\n", 1);

            while(!ksiazki.eof())
            {
                string wiersz;
                getline(ksiazki, wiersz);
                temp.write(&wiersz[0], wiersz.length());
                temp.write("\n", 1);
            }
            temp.close();
            break;
        }
    }

    ksiazki.close();

    remove("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\plikKsiazki");

    rename("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\temp", "E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\plikKsiazki");

    wypozyczone << wypozyczonaKsiazka << endl << dataWypozyczenia << endl << dataOddania << endl;

    qDeleteAll(ui->listaDostepnychKsiazek->selectedItems());

    obecnaOsoba.close();
    wypozyczone.close();

    //QMessageBox::information(this, "Status", "Udało się wypożyczyć książkę");
    //hide();
}

void PrzegladajKsiazki::on_przyciskWyszukaj_clicked()
{
    QString wyszukajTekst = ui->lineWyszukaj->text();
    int rozmiarListy = ui->listaDostepnychKsiazek->count();

    for (int k = 0; k < rozmiarListy; k++)
    {
        if (ui->listaDostepnychKsiazek->item(k)->text().startsWith(wyszukajTekst))
        {
             ui->listaDostepnychKsiazek->item(k)->setHidden(false);
        }
        else
        {
             ui->listaDostepnychKsiazek->item(k)->setHidden(true);
        }
    }
}
