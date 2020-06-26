#include "aktualnyczytelnik.h"
#include <iostream>
#include <fstream>
#include <QtCore>
#include <QMessageBox>

using namespace std;

AktualnyCzytelnik::AktualnyCzytelnik(string im, string naz, string log, string has)
    : imie(im), nazwisko(naz), login(log), haslo(has)
{
    ofstream obecnaOsoba("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\obecnyCzytelnik");

    if(obecnaOsoba.good() == false)
    {
        qApp->quit();
    }

    obecnaOsoba << imie << " " << nazwisko << " " << login << " " << haslo;

    obecnaOsoba.close();
}
