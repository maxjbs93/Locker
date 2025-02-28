/********************************************************************************
** Form generated from reading UI file 'mainpagelivreur.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGELIVREUR_H
#define UI_MAINPAGELIVREUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpagelivreur
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainpagelivreur)
    {
        if (mainpagelivreur->objectName().isEmpty())
            mainpagelivreur->setObjectName("mainpagelivreur");
        mainpagelivreur->resize(800, 600);
        centralwidget = new QWidget(mainpagelivreur);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 50, 49, 16));
        mainpagelivreur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainpagelivreur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        mainpagelivreur->setMenuBar(menubar);
        statusbar = new QStatusBar(mainpagelivreur);
        statusbar->setObjectName("statusbar");
        mainpagelivreur->setStatusBar(statusbar);

        retranslateUi(mainpagelivreur);

        QMetaObject::connectSlotsByName(mainpagelivreur);
    } // setupUi

    void retranslateUi(QMainWindow *mainpagelivreur)
    {
        mainpagelivreur->setWindowTitle(QCoreApplication::translate("mainpagelivreur", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("mainpagelivreur", "coucou", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpagelivreur: public Ui_mainpagelivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGELIVREUR_H
