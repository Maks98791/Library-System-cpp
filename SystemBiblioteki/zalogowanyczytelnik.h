#ifndef ZALOGOWANYCZYTELNIK_H
#define ZALOGOWANYCZYTELNIK_H

#include <QDialog>

namespace Ui {
class zalogowanyCzytelnik;
}

class zalogowanyCzytelnik : public QDialog
{
    Q_OBJECT

public:
    explicit zalogowanyCzytelnik(QWidget *parent = 0);
    ~zalogowanyCzytelnik();

private slots:
    void on_pushButton_clicked();

private:
    Ui::zalogowanyCzytelnik *ui;
};

#endif // ZALOGOWANYCZYTELNIK_H
