/********************************************************************************
** Form generated from reading UI file 'ajoutcommande.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCOMMANDE_H
#define UI_AJOUTCOMMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ajoutcommande
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
    QLineEdit *lineEdit_mail;
    QLineEdit *lineEdit_poids;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_adresse;
    QComboBox *comboBox_taille;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_annuler;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ajoutcommande)
    {
        if (ajoutcommande->objectName().isEmpty())
            ajoutcommande->setObjectName("ajoutcommande");
        ajoutcommande->resize(800, 600);
        centralwidget = new QWidget(ajoutcommande);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 781, 51));
        QFont font;
        font.setPointSize(35);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 781, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 150, 291, 41));
        QFont font2;
        font2.setPointSize(15);
        label_3->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 210, 291, 41));
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 270, 291, 41));
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 330, 291, 41));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 390, 291, 41));
        label_7->setFont(font2);
        lineEdit_mail = new QLineEdit(centralwidget);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(340, 140, 431, 41));
        lineEdit_mail->setFont(font2);
        lineEdit_poids = new QLineEdit(centralwidget);
        lineEdit_poids->setObjectName("lineEdit_poids");
        lineEdit_poids->setGeometry(QRect(340, 260, 431, 41));
        lineEdit_poids->setFont(font2);
        lineEdit_nom = new QLineEdit(centralwidget);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(340, 320, 431, 41));
        lineEdit_nom->setFont(font2);
        lineEdit_adresse = new QLineEdit(centralwidget);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(340, 380, 431, 41));
        lineEdit_adresse->setFont(font2);
        comboBox_taille = new QComboBox(centralwidget);
        comboBox_taille->setObjectName("comboBox_taille");
        comboBox_taille->setEnabled(true);
        comboBox_taille->setGeometry(QRect(340, 210, 431, 41));
        comboBox_taille->setFont(font2);
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(160, 480, 181, 51));
        pushButton_annuler = new QPushButton(centralwidget);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(400, 480, 181, 51));
        ajoutcommande->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ajoutcommande);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ajoutcommande->setMenuBar(menubar);
        statusbar = new QStatusBar(ajoutcommande);
        statusbar->setObjectName("statusbar");
        ajoutcommande->setStatusBar(statusbar);

        retranslateUi(ajoutcommande);

        comboBox_taille->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ajoutcommande);
    } // setupUi

    void retranslateUi(QMainWindow *ajoutcommande)
    {
        ajoutcommande->setWindowTitle(QCoreApplication::translate("ajoutcommande", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ajoutcommande", "Ajouter une nouvelle commande", nullptr));
        label_2->setText(QCoreApplication::translate("ajoutcommande", "Veuillez remplir les champs suivants :", nullptr));
        label_3->setText(QCoreApplication::translate("ajoutcommande", "Mail du client :", nullptr));
        label_4->setText(QCoreApplication::translate("ajoutcommande", "Taille de casier n\303\251cessaire : ", nullptr));
        label_5->setText(QCoreApplication::translate("ajoutcommande", "Poids du colis (kg) :", nullptr));
        label_6->setText(QCoreApplication::translate("ajoutcommande", "Nom du commer\303\247ant :", nullptr));
        label_7->setText(QCoreApplication::translate("ajoutcommande", "Adresse du commer\303\247ant :", nullptr));
        lineEdit_mail->setPlaceholderText(QCoreApplication::translate("ajoutcommande", "ishakabdoul@gmail.com", nullptr));
        comboBox_taille->setCurrentText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("ajoutcommande", "Ajouter", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("ajoutcommande", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajoutcommande: public Ui_ajoutcommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCOMMANDE_H
