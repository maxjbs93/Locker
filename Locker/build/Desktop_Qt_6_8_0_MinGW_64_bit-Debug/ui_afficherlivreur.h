/********************************************************************************
** Form generated from reading UI file 'afficherlivreur.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERLIVREUR_H
#define UI_AFFICHERLIVREUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afficherlivreur
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_supprimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *afficherlivreur)
    {
        if (afficherlivreur->objectName().isEmpty())
            afficherlivreur->setObjectName("afficherlivreur");
        afficherlivreur->resize(800, 600);
        centralwidget = new QWidget(afficherlivreur);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 160, 801, 221));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(340, 400, 75, 24));
        afficherlivreur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(afficherlivreur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        afficherlivreur->setMenuBar(menubar);
        statusbar = new QStatusBar(afficherlivreur);
        statusbar->setObjectName("statusbar");
        afficherlivreur->setStatusBar(statusbar);

        retranslateUi(afficherlivreur);

        QMetaObject::connectSlotsByName(afficherlivreur);
    } // setupUi

    void retranslateUi(QMainWindow *afficherlivreur)
    {
        afficherlivreur->setWindowTitle(QCoreApplication::translate("afficherlivreur", "MainWindow", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("afficherlivreur", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class afficherlivreur: public Ui_afficherlivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHERLIVREUR_H
