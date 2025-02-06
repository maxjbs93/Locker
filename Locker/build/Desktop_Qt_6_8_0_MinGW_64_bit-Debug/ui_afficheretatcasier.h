/********************************************************************************
** Form generated from reading UI file 'afficheretatcasier.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERETATCASIER_H
#define UI_AFFICHERETATCASIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afficheretatcasier
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *afficheretatcasier)
    {
        if (afficheretatcasier->objectName().isEmpty())
            afficheretatcasier->setObjectName("afficheretatcasier");
        afficheretatcasier->resize(800, 600);
        centralwidget = new QWidget(afficheretatcasier);
        centralwidget->setObjectName("centralwidget");
        afficheretatcasier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(afficheretatcasier);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        afficheretatcasier->setMenuBar(menubar);
        statusbar = new QStatusBar(afficheretatcasier);
        statusbar->setObjectName("statusbar");
        afficheretatcasier->setStatusBar(statusbar);

        retranslateUi(afficheretatcasier);

        QMetaObject::connectSlotsByName(afficheretatcasier);
    } // setupUi

    void retranslateUi(QMainWindow *afficheretatcasier)
    {
        afficheretatcasier->setWindowTitle(QCoreApplication::translate("afficheretatcasier", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class afficheretatcasier: public Ui_afficheretatcasier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHERETATCASIER_H
