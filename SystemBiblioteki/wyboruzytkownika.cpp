#include "wyboruzytkownika.h"
#include "ui_wyboruzytkownika.h"
#include "logowanieczytelnik.h"
#include "logowaniebibliotekarz.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>

//okno wyboru uzytkownika pomiedzy bibliotekarzem a czytelnikiem

WyborUzytkownika::WyborUzytkownika(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WyborUzytkownika)
{
    ui->setupUi(this);
}

WyborUzytkownika::~WyborUzytkownika()
{
    delete ui;
}

void WyborUzytkownika::on_pushButton_2_clicked()
{
    qApp->quit();
}

void WyborUzytkownika::on_pushButton_clicked()
{
    if(ui->radioButton1->isChecked())
    {
        LogowanieCzytelnik logowczyt; //wybranie czytelnika
        hide();
        logowczyt.setModal(true);
        logowczyt.exec();
    }
    else
    {
        LogowanieBibliotekarz logowbibl; //wybranie bibliotekarza
        hide();
        logowbibl.setModal((true));
        logowbibl.exec();
    }
}
