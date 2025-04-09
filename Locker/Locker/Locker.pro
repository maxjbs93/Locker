QT += core gui network

QT += network  # Assurez-vous d'avoir ce module pour les fonctionnalités réseau

RESOURCES += \
    resources.qrc \
    resources.qrc

# Créez un fichier resources.qrc contenant :
# <RCC>
#     <qresource prefix="/">
#         <file>images/locker_logo.png</file>
#         <file>images/loading.gif</file>
#     </qresource>
# </RCC>

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
    certifierreceptioncolis.cpp \
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
    certifierreceptioncolis.h \
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
    certifierreceptioncolis.ui \
    mainpage.ui \
    mainpagelivreur.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    style.qss
