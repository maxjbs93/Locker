/********************************************************************************
** Form generated from reading UI file 'attribuercommandelivreur.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTRIBUERCOMMANDELIVREUR_H
#define UI_ATTRIBUERCOMMANDELIVREUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_attribuercommandelivreur
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxCommandes;
    QComboBox *comboBoxLivreurs;
    QLabel *label_3;
    QPushButton *pushButton_attribuer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *attribuercommandelivreur)
    {
        if (attribuercommandelivreur->objectName().isEmpty())
            attribuercommandelivreur->setObjectName("attribuercommandelivreur");
        attribuercommandelivreur->resize(800, 600);
        centralwidget = new QWidget(attribuercommandelivreur);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 781, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 781, 51));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBoxCommandes = new QComboBox(centralwidget);
        comboBoxCommandes->setObjectName("comboBoxCommandes");
        comboBoxCommandes->setGeometry(QRect(360, 150, 69, 22));
        comboBoxLivreurs = new QComboBox(centralwidget);
        comboBoxLivreurs->setObjectName("comboBoxLivreurs");
        comboBoxLivreurs->setGeometry(QRect(360, 330, 69, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 230, 781, 51));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_attribuer = new QPushButton(centralwidget);
        pushButton_attribuer->setObjectName("pushButton_attribuer");
        pushButton_attribuer->setGeometry(QRect(280, 440, 181, 41));
        attribuercommandelivreur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(attribuercommandelivreur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        attribuercommandelivreur->setMenuBar(menubar);
        statusbar = new QStatusBar(attribuercommandelivreur);
        statusbar->setObjectName("statusbar");
        attribuercommandelivreur->setStatusBar(statusbar);

        retranslateUi(attribuercommandelivreur);

        QMetaObject::connectSlotsByName(attribuercommandelivreur);
    } // setupUi

    void retranslateUi(QMainWindow *attribuercommandelivreur)
    {
        attribuercommandelivreur->setWindowTitle(QCoreApplication::translate("attribuercommandelivreur", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("attribuercommandelivreur", "Attribution d'un livreur \303\240 un colis", nullptr));
        label_2->setText(QCoreApplication::translate("attribuercommandelivreur", "S\303\251lectionnez une commande : ", nullptr));
        label_3->setText(QCoreApplication::translate("attribuercommandelivreur", "A quel livreur souhaitez-vous l'attribuer ?", nullptr));
        pushButton_attribuer->setText(QCoreApplication::translate("attribuercommandelivreur", "Attribuer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class attribuercommandelivreur: public Ui_attribuercommandelivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRIBUERCOMMANDELIVREUR_H
