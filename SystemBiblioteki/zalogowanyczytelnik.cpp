#include "zalogowanyczytelnik.h"
#include "ui_zalogowanyczytelnik.h"
#include <fstream>

using namespace std;

zalogowanyCzytelnik::zalogowanyCzytelnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zalogowanyCzytelnik)
{
    ui->setupUi(this);

    fstream czyt;
    czyt.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\obecnyCzytelnik", ios::in);

    if(czyt.good() == false)
    {
        qApp->quit();
    }

    string im, naz, log, has;
    czyt >> im >> naz >> log >> has;

    QString qim = QString::fromStdString(im);
    QString qnaz = QString::fromStdString(naz);
    QString qlog = QString::fromStdString(log);
    QString qhas = QString::fromStdString(has);

    ui->labelImie->setText(qim);
    ui->labelNazwisko->setText(qnaz);
    ui->labelLogin->setText(qlog);
    ui->labelHaslo->setText(qhas);

    czyt.close();
}

zalogowanyCzytelnik::~zalogowanyCzytelnik()
{
    delete ui;
}

void zalogowanyCzytelnik::on_pushButton_clicked()
{
    hide();
}
