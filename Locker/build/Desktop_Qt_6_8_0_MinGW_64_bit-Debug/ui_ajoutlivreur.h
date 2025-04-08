/********************************************************************************
** Form generated from reading UI file 'ajoutlivreur.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTLIVREUR_H
#define UI_AJOUTLIVREUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ajoutlivreur
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_annuler;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ajoutlivreur)
    {
        if (ajoutlivreur->objectName().isEmpty())
            ajoutlivreur->setObjectName("ajoutlivreur");
        ajoutlivreur->resize(800, 600);
        centralwidget = new QWidget(ajoutlivreur);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 781, 61));
        QFont font;
        font.setPointSize(35);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 781, 61));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 180, 81, 30));
        QFont font2;
        font2.setPointSize(15);
        label_3->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 240, 81, 30));
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 300, 81, 30));
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 360, 281, 30));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 420, 251, 30));
        label_7->setFont(font2);
        lineEdit_nom = new QLineEdit(centralwidget);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(350, 180, 311, 30));
        lineEdit_nom->setFont(font2);
        lineEdit_prenom = new QLineEdit(centralwidget);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(350, 240, 311, 30));
        lineEdit_prenom->setFont(font2);
        lineEdit_adresse = new QLineEdit(centralwidget);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(350, 300, 311, 30));
        lineEdit_adresse->setFont(font2);
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(350, 360, 311, 30));
        lineEdit_username->setFont(font2);
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(350, 420, 311, 30));
        lineEdit_password->setFont(font2);
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(160, 480, 181, 51));
        pushButton_annuler = new QPushButton(centralwidget);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(400, 480, 181, 51));
        ajoutlivreur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ajoutlivreur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ajoutlivreur->setMenuBar(menubar);
        statusbar = new QStatusBar(ajoutlivreur);
        statusbar->setObjectName("statusbar");
        ajoutlivreur->setStatusBar(statusbar);

        retranslateUi(ajoutlivreur);

        QMetaObject::connectSlotsByName(ajoutlivreur);
    } // setupUi

    void retranslateUi(QMainWindow *ajoutlivreur)
    {
        ajoutlivreur->setWindowTitle(QCoreApplication::translate("ajoutlivreur", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ajoutlivreur", "Ajout d'un livreur ", nullptr));
        label_2->setText(QCoreApplication::translate("ajoutlivreur", "Veuillez remplir les champs suivants :", nullptr));
        label_3->setText(QCoreApplication::translate("ajoutlivreur", "Nom :", nullptr));
        label_4->setText(QCoreApplication::translate("ajoutlivreur", "Pr\303\251nom : ", nullptr));
        label_5->setText(QCoreApplication::translate("ajoutlivreur", "Adresse :", nullptr));
        label_6->setText(QCoreApplication::translate("ajoutlivreur", "Nom d'utilisateur :", nullptr));
        label_7->setText(QCoreApplication::translate("ajoutlivreur", "Mot de passe :", nullptr));
        lineEdit_nom->setText(QString());
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "Dupont", nullptr));
        lineEdit_prenom->setText(QString());
        lineEdit_prenom->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "Jean", nullptr));
        lineEdit_adresse->setText(QString());
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "7 Rue des Pacotilles", nullptr));
        lineEdit_username->setText(QString());
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "jean_dupont", nullptr));
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "livreur1234", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("ajoutlivreur", "Ajouter", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("ajoutlivreur", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajoutlivreur: public Ui_ajoutlivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTLIVREUR_H
