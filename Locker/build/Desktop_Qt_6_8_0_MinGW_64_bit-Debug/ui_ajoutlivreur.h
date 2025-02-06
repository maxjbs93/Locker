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
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
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
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 180, 311, 30));
        lineEdit_3->setFont(font2);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(350, 240, 311, 30));
        lineEdit_4->setFont(font2);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(350, 300, 311, 30));
        lineEdit_5->setFont(font2);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(350, 360, 311, 30));
        lineEdit_6->setFont(font2);
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(350, 420, 311, 30));
        lineEdit_7->setFont(font2);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 480, 181, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 480, 181, 51));
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
        label_6->setText(QCoreApplication::translate("ajoutlivreur", "Nom d'utilisateur (temporaire) :", nullptr));
        label_7->setText(QCoreApplication::translate("ajoutlivreur", "Mot de passe (temporaire) :", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "Dupont", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "Jean", nullptr));
        lineEdit_5->setText(QString());
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "7 Rue des Pacotilles", nullptr));
        lineEdit_6->setText(QString());
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "jean_dupont", nullptr));
        lineEdit_7->setText(QString());
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("ajoutlivreur", "livreur1234", nullptr));
        pushButton->setText(QCoreApplication::translate("ajoutlivreur", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ajoutlivreur", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajoutlivreur: public Ui_ajoutlivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTLIVREUR_H
