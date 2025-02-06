/********************************************************************************
** Form generated from reading UI file 'certifierreceptioncolis.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CERTIFIERRECEPTIONCOLIS_H
#define UI_CERTIFIERRECEPTIONCOLIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_certifierreceptioncolis
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *certifierreceptioncolis)
    {
        if (certifierreceptioncolis->objectName().isEmpty())
            certifierreceptioncolis->setObjectName("certifierreceptioncolis");
        certifierreceptioncolis->resize(800, 600);
        centralwidget = new QWidget(certifierreceptioncolis);
        centralwidget->setObjectName("centralwidget");
        certifierreceptioncolis->setCentralWidget(centralwidget);
        menubar = new QMenuBar(certifierreceptioncolis);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        certifierreceptioncolis->setMenuBar(menubar);
        statusbar = new QStatusBar(certifierreceptioncolis);
        statusbar->setObjectName("statusbar");
        certifierreceptioncolis->setStatusBar(statusbar);

        retranslateUi(certifierreceptioncolis);

        QMetaObject::connectSlotsByName(certifierreceptioncolis);
    } // setupUi

    void retranslateUi(QMainWindow *certifierreceptioncolis)
    {
        certifierreceptioncolis->setWindowTitle(QCoreApplication::translate("certifierreceptioncolis", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class certifierreceptioncolis: public Ui_certifierreceptioncolis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CERTIFIERRECEPTIONCOLIS_H
