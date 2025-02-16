/********************************************************************************
** Form generated from reading UI file 'affichercommande.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERCOMMANDE_H
#define UI_AFFICHERCOMMANDE_H

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

class Ui_affichercommande
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_supprimer;
    QTableWidget *tableWidget_commandes;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *affichercommande)
    {
        if (affichercommande->objectName().isEmpty())
            affichercommande->setObjectName("affichercommande");
        affichercommande->resize(800, 600);
        centralwidget = new QWidget(affichercommande);
        centralwidget->setObjectName("centralwidget");
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(360, 400, 75, 24));
        tableWidget_commandes = new QTableWidget(centralwidget);
        tableWidget_commandes->setObjectName("tableWidget_commandes");
        tableWidget_commandes->setGeometry(QRect(0, 180, 800, 200));
        affichercommande->setCentralWidget(centralwidget);
        menubar = new QMenuBar(affichercommande);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        affichercommande->setMenuBar(menubar);
        statusbar = new QStatusBar(affichercommande);
        statusbar->setObjectName("statusbar");
        affichercommande->setStatusBar(statusbar);

        retranslateUi(affichercommande);

        QMetaObject::connectSlotsByName(affichercommande);
    } // setupUi

    void retranslateUi(QMainWindow *affichercommande)
    {
        affichercommande->setWindowTitle(QCoreApplication::translate("affichercommande", "MainWindow", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("affichercommande", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class affichercommande: public Ui_affichercommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHERCOMMANDE_H
