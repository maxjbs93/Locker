/********************************************************************************
** Form generated from reading UI file 'ajoutcommande.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCOMMANDE_H
#define UI_AJOUTCOMMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ajoutcommande
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ajoutcommande)
    {
        if (ajoutcommande->objectName().isEmpty())
            ajoutcommande->setObjectName("ajoutcommande");
        ajoutcommande->resize(800, 600);
        centralwidget = new QWidget(ajoutcommande);
        centralwidget->setObjectName("centralwidget");
        ajoutcommande->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ajoutcommande);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ajoutcommande->setMenuBar(menubar);
        statusbar = new QStatusBar(ajoutcommande);
        statusbar->setObjectName("statusbar");
        ajoutcommande->setStatusBar(statusbar);

        retranslateUi(ajoutcommande);

        QMetaObject::connectSlotsByName(ajoutcommande);
    } // setupUi

    void retranslateUi(QMainWindow *ajoutcommande)
    {
        ajoutcommande->setWindowTitle(QCoreApplication::translate("ajoutcommande", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajoutcommande: public Ui_ajoutcommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCOMMANDE_H
