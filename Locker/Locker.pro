QT += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichercommande.cpp \
    afficheretatcasier.cpp \
    afficherlivreur.cpp \
    ajoutcommande.cpp \
    ajoutlivreur.cpp \
    attribuercommandelivreur.cpp \
    main.cpp \
    mainpage.cpp \
    mainpagelivreur.cpp \
    mainwindow.cpp

HEADERS += \
    affichercommande.h \
    afficheretatcasier.h \
    afficherlivreur.h \
    ajoutcommande.h \
    ajoutlivreur.h \
    attribuercommandelivreur.h \
    mainpage.h \
    mainpagelivreur.h \
    mainwindow.h

FORMS += \
    affichercommande.ui \
    afficheretatcasier.ui \
    afficherlivreur.ui \
    ajoutcommande.ui \
    ajoutlivreur.ui \
    attribuercommandelivreur.ui \
    mainpage.ui \
    mainpagelivreur.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
