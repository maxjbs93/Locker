QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afficheretatcasier.cpp \
    ajoutcommande.cpp \
    ajoutlivreur.cpp \
    certifierreceptioncolis.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    supprimercommande.cpp

HEADERS += \
    afficheretatcasier.h \
    ajoutcommande.h \
    ajoutlivreur.h \
    certifierreceptioncolis.h \
    mainpage.h \
    mainwindow.h \
    supprimercommande.h

FORMS += \
    afficheretatcasier.ui \
    ajoutcommande.ui \
    ajoutlivreur.ui \
    certifierreceptioncolis.ui \
    mainpage.ui \
    mainwindow.ui \
    supprimercommande.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
