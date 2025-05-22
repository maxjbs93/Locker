/********************************************************************************
** Form generated from reading UI file 'certifierlivraisoncommande.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CERTIFIERLIVRAISONCOMMANDE_H
#define UI_CERTIFIERLIVRAISONCOMMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_certifierlivraisoncommande
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditCommandeId;
    QLineEdit *lineEditLivreurId;
    QPushButton *btnCertifier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *certifierlivraisoncommande)
    {
        if (certifierlivraisoncommande->objectName().isEmpty())
            certifierlivraisoncommande->setObjectName("certifierlivraisoncommande");
        certifierlivraisoncommande->resize(800, 600);
        centralwidget = new QWidget(certifierlivraisoncommande);
        centralwidget->setObjectName("centralwidget");
        lineEditCommandeId = new QLineEdit(centralwidget);
        lineEditCommandeId->setObjectName("lineEditCommandeId");
        lineEditCommandeId->setGeometry(QRect(310, 110, 113, 22));
        lineEditLivreurId = new QLineEdit(centralwidget);
        lineEditLivreurId->setObjectName("lineEditLivreurId");
        lineEditLivreurId->setGeometry(QRect(310, 180, 113, 22));
        btnCertifier = new QPushButton(centralwidget);
        btnCertifier->setObjectName("btnCertifier");
        btnCertifier->setGeometry(QRect(330, 260, 75, 24));
        certifierlivraisoncommande->setCentralWidget(centralwidget);
        menubar = new QMenuBar(certifierlivraisoncommande);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        certifierlivraisoncommande->setMenuBar(menubar);
        statusbar = new QStatusBar(certifierlivraisoncommande);
        statusbar->setObjectName("statusbar");
        certifierlivraisoncommande->setStatusBar(statusbar);

        retranslateUi(certifierlivraisoncommande);

        QMetaObject::connectSlotsByName(certifierlivraisoncommande);
    } // setupUi

    void retranslateUi(QMainWindow *certifierlivraisoncommande)
    {
        certifierlivraisoncommande->setWindowTitle(QCoreApplication::translate("certifierlivraisoncommande", "MainWindow", nullptr));
        btnCertifier->setText(QCoreApplication::translate("certifierlivraisoncommande", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class certifierlivraisoncommande: public Ui_certifierlivraisoncommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CERTIFIERLIVRAISONCOMMANDE_H
