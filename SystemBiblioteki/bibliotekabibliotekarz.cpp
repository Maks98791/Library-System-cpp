#include "bibliotekabibliotekarz.h"
#include "ui_bibliotekabibliotekarz.h"
#include "wyboruzytkownika.h"
#include "obecniczytelnicy.h"
#include "przegladajksiazki2.h"
#include <QMessageBox>

BibliotekaBibliotekarz::BibliotekaBibliotekarz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BibliotekaBibliotekarz)
{
    ui->setupUi(this);
}

BibliotekaBibliotekarz::~BibliotekaBibliotekarz()
{
    delete ui;
}

void BibliotekaBibliotekarz::on_actionWyloguj_triggered()
{
    qApp->quit();
}

void BibliotekaBibliotekarz::on_actionPrzegl_daj_czytelnik_w_triggered()
{
    ObecniCzytelnicy wszyscyCzytelnicy;
    wszyscyCzytelnicy.setModal(true); //wlaczenie okna przegladania
    wszyscyCzytelnicy.exec();         //wszystkich zarejestrowanych uzytkownikow (czytelnikow)
}

void BibliotekaBibliotekarz::on_actionPrzegl_daj_ksi_ki_2_triggered()
{
    przegladajKsiazki2 przegladanieKsiazek;
    przegladanieKsiazek.setModal(true); //wlaczenie okna przegladania dostepnych ksiazek
    przegladanieKsiazek.exec();
}

void BibliotekaBibliotekarz::on_actionO_programie_triggered()
{
    QMessageBox::information(this, "O programie", "System Biblioteki v1.0\n Autor: Maksim Birszel");
}
