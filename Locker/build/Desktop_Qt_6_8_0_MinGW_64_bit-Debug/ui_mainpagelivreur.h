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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpagelivreur
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_certifierreceptioncolis;
    QPushButton *pushButton_certifierlivraisoncommande;
    QPushButton *pushButton_deconnexion;
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
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 30, 801, 41));
        QFont font;
        font.setPointSize(25);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_certifierreceptioncolis = new QPushButton(centralwidget);
        pushButton_certifierreceptioncolis->setObjectName("pushButton_certifierreceptioncolis");
        pushButton_certifierreceptioncolis->setGeometry(QRect(200, 140, 391, 81));
        QFont font1;
        font1.setPointSize(14);
        pushButton_certifierreceptioncolis->setFont(font1);
        pushButton_certifierlivraisoncommande = new QPushButton(centralwidget);
        pushButton_certifierlivraisoncommande->setObjectName("pushButton_certifierlivraisoncommande");
        pushButton_certifierlivraisoncommande->setGeometry(QRect(200, 280, 391, 81));
        pushButton_certifierlivraisoncommande->setFont(font1);
        pushButton_deconnexion = new QPushButton(centralwidget);
        pushButton_deconnexion->setObjectName("pushButton_deconnexion");
        pushButton_deconnexion->setGeometry(QRect(280, 490, 91, 24));
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
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("mainpagelivreur", "Que souhaitez - vous faire ?", nullptr));
        pushButton_certifierreceptioncolis->setText(QCoreApplication::translate("mainpagelivreur", "Certifier la r\303\251ception d'un colis", nullptr));
        pushButton_certifierlivraisoncommande->setText(QCoreApplication::translate("mainpagelivreur", "Certifier la livraison d'une commande", nullptr));
        pushButton_deconnexion->setText(QCoreApplication::translate("mainpagelivreur", "Se d\303\251connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpagelivreur: public Ui_mainpagelivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGELIVREUR_H
