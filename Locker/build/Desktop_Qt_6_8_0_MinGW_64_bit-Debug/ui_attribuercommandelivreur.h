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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_attribuercommandelivreur
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
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
        label_2->setText(QCoreApplication::translate("attribuercommandelivreur", "Quel livreur souhaitez-vous attribuer ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class attribuercommandelivreur: public Ui_attribuercommandelivreur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRIBUERCOMMANDELIVREUR_H
