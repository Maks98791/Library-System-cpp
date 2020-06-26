#include "bibliotekaczytelnik.h"
#include "ui_bibliotekaczytelnik.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "przegladajksiazki.h"
#include "logowanieczytelnik1.h"
#include "aktualnyczytelnik.h"
#include "zalogowanyczytelnik.h"
#include "wypozyczoneksiazki.h"

BibliotekaCzytelnik::BibliotekaCzytelnik(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BibliotekaCzytelnik)
{
    ui->setupUi(this);
}

BibliotekaCzytelnik::~BibliotekaCzytelnik()
{
    delete ui;
}

void BibliotekaCzytelnik::on_actionPrzegl_daj_ksi_ki_triggered()
{
    PrzegladajKsiazki przegladanie;
    przegladanie.setModal(true); //wlaczenie okna przegladania dostepnych ksiazek
    przegladanie.exec();
}

void BibliotekaCzytelnik::on_actionWyloguj_2_triggered()
{
    qApp->quit();
}

void BibliotekaCzytelnik::on_actionDane_czytelnika_triggered()
{
    zalogowanyCzytelnik zalogowany;
    zalogowany.setModal(true);
    zalogowany.exec(); //wlaczenie okna z danymi obecnie zalogowanego czytelnika
}

void BibliotekaCzytelnik::on_actionWypo_yczone_ksi_ki_triggered()
{
    wypozyczoneKsiazki wypozyczone;
    wypozyczone.setModal(true); //wlaczenie okna z wypozyczonymi
    wypozyczone.exec();         //ksiazkami zalogowanego uzytkownika
}

void BibliotekaCzytelnik::on_actionO_programie_triggered()
{
    QMessageBox::information(this, "O programie", "System Biblioteki v1.0\n Autor: Maksim Birszel");
}
