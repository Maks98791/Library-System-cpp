#-------------------------------------------------
#
# Project created by QtCreator 2018-03-23T18:59:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SystemBiblioteki
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        wyboruzytkownika.cpp \
    logowanieczytelnik.cpp \
    logowaniebibliotekarz.cpp \
    logowanieczytelnik1.cpp \
    logowanieczytelnik2.cpp \
    bibliotekaczytelnik.cpp \
    bibliotekabibliotekarz.cpp \
    obslugapliku.cpp \
    bazaksiazek.cpp \
    przegladajksiazki.cpp \
    obecniczytelnicy.cpp \
    aktualnyczytelnik.cpp \
    zalogowanyczytelnik.cpp \
    przegladajksiazki2.cpp \
    wypozyczoneksiazki.cpp

HEADERS += \
        wyboruzytkownika.h \
    logowanieczytelnik.h \
    logowaniebibliotekarz.h \
    logowanieczytelnik1.h \
    logowanieczytelnik2.h \
    bibliotekaczytelnik.h \
    bibliotekabibliotekarz.h \
    czytelnik.h \
    uzytkownik.h \
    obslugapliku.h \
    ksiazka.h \
    bazaksiazek.h \
    przegladajksiazki.h \
    obecniczytelnicy.h \
    aktualnyczytelnik.h \
    zalogowanyczytelnik.h \
    przegladajksiazki2.h \
    wypozyczoneksiazki.h

FORMS += \
        wyboruzytkownika.ui \
    logowanieczytelnik.ui \
    logowaniebibliotekarz.ui \
    logowanieczytelnik1.ui \
    logowanieczytelnik2.ui \
    bibliotekaczytelnik.ui \
    bibliotekabibliotekarz.ui \
    przegladajksiazki.ui \
    obecniczytelnicy.ui \
    zalogowanyczytelnik.ui \
    przegladajksiazki2.ui \
    wypozyczoneksiazki.ui

DISTFILES += \
    ../build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/baza.txt \
    ../build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/plikKsiazki \
    ../build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/obecnyCzytelnik

RESOURCES +=
