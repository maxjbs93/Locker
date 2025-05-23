/********************************************************************************
** Form generated from reading UI file 'afficheretatcasier.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERETATCASIER_H
#define UI_AFFICHERETATCASIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afficheretatcasier
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *afficheretatcasier)
    {
        if (afficheretatcasier->objectName().isEmpty())
            afficheretatcasier->setObjectName("afficheretatcasier");
        afficheretatcasier->resize(1000, 600);
        centralwidget = new QWidget(afficheretatcasier);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 150, 1000, 300));
        afficheretatcasier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(afficheretatcasier);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
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
