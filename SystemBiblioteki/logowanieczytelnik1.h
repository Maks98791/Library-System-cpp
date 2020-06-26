#ifndef LOGOWANIECZYTELNIK1_H
#define LOGOWANIECZYTELNIK1_H
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "czytelnik.h"


namespace Ui {
class LogowanieCzytelnik1;
}

class LogowanieCzytelnik1 : public QDialog
{
    Q_OBJECT

public:
    explicit LogowanieCzytelnik1(QWidget *parent = 0);
    ~LogowanieCzytelnik1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LogowanieCzytelnik1 *ui;
};

#endif // LOGOWANIECZYTELNIK1_H
