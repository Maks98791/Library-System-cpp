#ifndef CZYTELNIK_H
#define CZYTELNIK_H
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "uzytkownik.h"
#include <string>

using namespace std;

class Czytelnik : public Uzytkownik
{

public:
     string imie;
     string nazwisko;
     int przedluzenie;
};

#endif // CZYTELNIK_H
