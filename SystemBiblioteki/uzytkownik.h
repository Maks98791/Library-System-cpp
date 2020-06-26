#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "uzytkownik.h"
#include <string>

using namespace std;

class Uzytkownik
{
public:
    string login;
    string haslo;
    void Wybor_Uzytkownika();
    void Wyloguj();
};

#endif // UZYTKOWNIK_H
