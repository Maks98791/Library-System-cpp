#include "wypozyczoneksiazki.h"
#include "ui_wypozyczoneksiazki.h"
#include <fstream>
#include <iostream>
#include "przegladajksiazki.h"
#include <windows.h>
#include <string>
#include <sstream>
#include <QListWidget>
#include <cstring>
#include <stdio.h>
#include <QMessageBox>

using namespace std;

wypozyczoneKsiazki::wypozyczoneKsiazki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wypozyczoneKsiazki)
{
    ui->setupUi(this);

    fstream czytelnik;
    fstream wypozyczone;

    czytelnik.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\obecnyCzytelnik", ios::in);

    if(czytelnik.good() == false)
    {
        qApp->quit();
    }

    string nazwa, imie, nazwisko;

    czytelnik >> imie >> nazwisko;

    czytelnik.close();

    nazwa = imie + nazwisko;

    wypozyczone.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\" + nazwa + ".txt", ios::in);

    string tytul, data_wyp, data_odd, a, c;

    wypozyczone.seekg(-2, ios_base::end);
    streampos poz = wypozyczone.tellg();
    wypozyczone.seekg(0, ios_base::beg);

    while(wypozyczone.tellg() < poz)
    {
        getline(wypozyczone, tytul);
        getline(wypozyczone, data_wyp);
        getline(wypozyczone, data_odd);
        QString qtytul = QString::fromStdString(tytul);
        QString qdata_wyp = QString::fromStdString(data_wyp);
        QString qdata_odd = QString::fromStdString(data_odd);
        ui->listaWypozyczonychKsiazek->addItem(qtytul + " Od: " + qdata_wyp + " Do: " + qdata_odd);
    }
    wypozyczone.close();
}

wypozyczoneKsiazki::~wypozyczoneKsiazki()
{
    delete ui;
}

void wypozyczoneKsiazki::on_przyciskWyjdz_clicked()
{
    hide();
}

void wypozyczoneKsiazki::on_PrzyciskPrzedluzZwrot_clicked()
{
    fstream czytelnik;
    fstream wypozyczone;

    czytelnik.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\obecnyCzytelnik", ios::in);

    if(czytelnik.good() == false)
    {
        qApp->quit();
    }

    string nazwa, imie, nazwisko;
    czytelnik >> imie >> nazwisko;
    czytelnik.close();

    nazwa = imie + nazwisko;

    wypozyczone.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\" + nazwa + ".txt", ios::in);

    QString wybrana;

    foreach(QListWidgetItem *ksiazka, ui->listaWypozyczonychKsiazek->selectedItems())
        wybrana = ksiazka->text(); //wybrana ksiazka do przedluzenia przez uzytkownika

    string wybranaKsiazka = wybrana.toStdString(); //np. Jane Austin - Gabriel Szmit Od: 03/04/2018 Do: 03/05/2018

    /*int numLines = 0;
    ifstream in("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\" + nazwa + ".txt");
    std::string unused;
    while (getline(in, unused))
       ++numLines; */   //liczba linii razem ZE ZNAKIEM NOWEJ LINII na koncu w pliku np kacpermichalczyk.txt

    int i = 0; //liczba wierszy do znalezionej ksiazki (sam tytul, bez dat)

    while(!wypozyczone.eof())
    {
        string test1, test2, data1, data2;

        wypozyczone >> test1; //pierwsza czesc tytulu
        getline(wypozyczone, test2); i++; //pelna linia z tytulem
        getline(wypozyczone, data1);  //linia z data wypozyczenia
        getline(wypozyczone, data2);  //linia z data oddania

        unsigned int pozycja = wybranaKsiazka.find(test1);

        if(pozycja !=string::npos) //jesli znaleziono wybrana przez uzytkownika ksiazke w pliku
        {
                fstream temp2;
                temp2.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\temp2", ios::app);
                if(temp2.good() == false)
                {
                    qApp->quit();
                }

                wypozyczone.seekg(0, ios_base::beg);

                for(int j=0; j < i; j++) //petla kopiujaca elementy pliku do momentu wystapienia daty wybraje ksiazki
                {
                    string wiersz;
                    getline(wypozyczone, wiersz);
                    temp2.write(&wiersz[0], wiersz.length());
                    temp2.write("\n", 1);
                }

                PrzegladajKsiazki data;
                temp2.write(&data1[0], data1.length()); //dopisanie do pliku starej daty wypozyczenia
                temp2.write("\n", 1);
                string przedluzonaData = data.PrzegladajKsiazki::data_przedluzenia();
                temp2.write(&przedluzonaData[0], przedluzonaData.length()); //dopisanie do pliku nowej daty wypozyczenia
                temp2.write("\n", 1);

                string line;
                getline(wypozyczone, line); //przesuniecie wskaznika o dwie pomijane daty
                getline(wypozyczone, line);

                while(!wypozyczone.eof())
                {
                    string wiersz;
                    getline(wypozyczone, wiersz);
                    temp2.write(&wiersz[0], wiersz.length());
                    temp2.write("\n", 1);
                }

                string sciezka = "E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\" + nazwa + ".txt";

                temp2.close();
                wypozyczone.close();

                remove(sciezka.c_str());
                rename("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\wypozyczenia\\temp2", sciezka.c_str());

                QMessageBox::information(this, "Status", "Pomyślnie przedłużono wypożyczenie książki, bądź wybrana książka jest już przedłużona maksymalnie.");
                hide();
        }
        else
            i += 2;
    }
    wypozyczone.close();
}
