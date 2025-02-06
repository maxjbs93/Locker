/********************************************************************************
** Form generated from reading UI file 'supprimercommande.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERCOMMANDE_H
#define UI_SUPPRIMERCOMMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_supprimercommande
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *supprimercommande)
    {
        if (supprimercommande->objectName().isEmpty())
            supprimercommande->setObjectName("supprimercommande");
        supprimercommande->resize(800, 600);
        centralwidget = new QWidget(supprimercommande);
        centralwidget->setObjectName("centralwidget");
        supprimercommande->setCentralWidget(centralwidget);
        menubar = new QMenuBar(supprimercommande);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        supprimercommande->setMenuBar(menubar);
        statusbar = new QStatusBar(supprimercommande);
        statusbar->setObjectName("statusbar");
        supprimercommande->setStatusBar(statusbar);

        retranslateUi(supprimercommande);

        QMetaObject::connectSlotsByName(supprimercommande);
    } // setupUi

    void retranslateUi(QMainWindow *supprimercommande)
    {
        supprimercommande->setWindowTitle(QCoreApplication::translate("supprimercommande", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class supprimercommande: public Ui_supprimercommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERCOMMANDE_H
