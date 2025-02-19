/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_title;
    QLabel *label_title_2;
    QPushButton *pushButton_ajout_livreur;
    QPushButton *pushButton_new_commande;
    QPushButton *pushButton_afficher_etat_casier;
    QPushButton *pushButton_attribuer_commande_livreur;
    QPushButton *pushButton_afficher_commande;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(640, 480);
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 640, 480));
        label_title = new QLabel(groupBox);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(170, 0, 271, 71));
        QFont font;
        font.setPointSize(35);
        font.setBold(true);
        label_title->setFont(font);
        label_title->setStyleSheet(QString::fromUtf8(""));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_title_2 = new QLabel(groupBox);
        label_title_2->setObjectName("label_title_2");
        label_title_2->setGeometry(QRect(120, 80, 361, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_title_2->setFont(font1);
        label_title_2->setStyleSheet(QString::fromUtf8(""));
        label_title_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_ajout_livreur = new QPushButton(groupBox);
        pushButton_ajout_livreur->setObjectName("pushButton_ajout_livreur");
        pushButton_ajout_livreur->setGeometry(QRect(120, 160, 361, 41));
        QFont font2;
        font2.setPointSize(10);
        pushButton_ajout_livreur->setFont(font2);
        pushButton_new_commande = new QPushButton(groupBox);
        pushButton_new_commande->setObjectName("pushButton_new_commande");
        pushButton_new_commande->setGeometry(QRect(120, 220, 361, 41));
        pushButton_new_commande->setFont(font2);
        pushButton_afficher_etat_casier = new QPushButton(groupBox);
        pushButton_afficher_etat_casier->setObjectName("pushButton_afficher_etat_casier");
        pushButton_afficher_etat_casier->setGeometry(QRect(120, 340, 361, 41));
        pushButton_afficher_etat_casier->setFont(font2);
        pushButton_attribuer_commande_livreur = new QPushButton(groupBox);
        pushButton_attribuer_commande_livreur->setObjectName("pushButton_attribuer_commande_livreur");
        pushButton_attribuer_commande_livreur->setGeometry(QRect(120, 400, 361, 41));
        pushButton_attribuer_commande_livreur->setFont(font2);
        pushButton_afficher_commande = new QPushButton(groupBox);
        pushButton_afficher_commande->setObjectName("pushButton_afficher_commande");
        pushButton_afficher_commande->setGeometry(QRect(120, 280, 361, 41));
        pushButton_afficher_commande->setFont(font2);
        MainPage->setCentralWidget(centralwidget);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QMainWindow *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_title->setText(QCoreApplication::translate("MainPage", "Bienvenue ! ", nullptr));
        label_title_2->setText(QCoreApplication::translate("MainPage", "Que souhaitez-vous faire ?", nullptr));
        pushButton_ajout_livreur->setText(QCoreApplication::translate("MainPage", "Ajouter un nouveau livreur", nullptr));
        pushButton_new_commande->setText(QCoreApplication::translate("MainPage", "Saisir une nouvelle commande ", nullptr));
        pushButton_afficher_etat_casier->setText(QCoreApplication::translate("MainPage", "Afficher l'\303\251tat des casiers", nullptr));
        pushButton_attribuer_commande_livreur->setText(QCoreApplication::translate("MainPage", "Attribuer une commande \303\240 un livreur", nullptr));
        pushButton_afficher_commande->setText(QCoreApplication::translate("MainPage", "Afficher les commandes existantes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
