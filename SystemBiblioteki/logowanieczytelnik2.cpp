#include "czytelnik.h"
#include "ui_logowanieczytelnik2.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "logowanieczytelnik2.h"
#include "wyboruzytkownika.h"
#include "logowanieczytelnik.h"
#include "czytelnik.h"
#include "obslugapliku.h"

using namespace std;

//okno logowania dla czytelnika NIE posiadajacego konta

LogowanieCzytelnik2::LogowanieCzytelnik2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogowanieCzytelnik2)
{
    ui->setupUi(this);
}

LogowanieCzytelnik2::~LogowanieCzytelnik2()
{
    delete ui;
}

void LogowanieCzytelnik2::on_pushButton_clicked()
{
    Czytelnik kolejny;
    fstream baza;
    vector <Czytelnik> lista;
    baza.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\baza.txt", ios::app);

    if(baza.good() == false)
    {
        qApp->quit();
    }

    kolejny.imie = ui->podajImie->text().toStdString();
    kolejny.nazwisko = ui->podajNazwisko->text().toStdString();
    kolejny.login = ui->podajLogin->text().toStdString();
    kolejny.haslo = ui->podajHaslo->text().toStdString();

    baza << endl << kolejny.imie << " " << kolejny.nazwisko << " " << kolejny.login << " " << kolejny.haslo;

    lista.push_back(kolejny);

    baza.close();

    QMessageBox::information(this, "Poprawna rejestracja", "Rejestracja przebiegła pomyślnie, zaloguj się do systemu");

    LogowanieCzytelnik logowCzyt;
    hide();
    logowCzyt.setModal(true); //ponowne otworzenie konta po poprawnej rejestracji
    logowCzyt.exec();

}

void LogowanieCzytelnik2::on_pushButton_2_clicked()
{
    qApp->quit();
}
