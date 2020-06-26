#ifndef LOGOWANIECZYTELNIK_H
#define LOGOWANIECZYTELNIK_H
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "czytelnik.h"

namespace Ui {
class LogowanieCzytelnik;
}

class LogowanieCzytelnik : public QDialog
{
    Q_OBJECT

public:
    explicit LogowanieCzytelnik(QWidget *parent = 0);
    ~LogowanieCzytelnik();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LogowanieCzytelnik *ui;
};

#endif // LOGOWANIECZYTELNIK_H
