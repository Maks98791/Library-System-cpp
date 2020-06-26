#ifndef LOGOWANIECZYTELNIK2_H
#define LOGOWANIECZYTELNIK2_H
#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class LogowanieCzytelnik2;
}

class LogowanieCzytelnik2 : public QDialog
{
    Q_OBJECT

public:
    explicit LogowanieCzytelnik2(QWidget *parent = 0);
    ~LogowanieCzytelnik2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LogowanieCzytelnik2 *ui;
};

#endif // LOGOWANIECZYTELNIK2_H
