#ifndef MAINPAGELIVREUR_H
#define MAINPAGELIVREUR_H

#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class mainpagelivreur;
}

class mainpagelivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpagelivreur(int livreurId, QWidget *parent = nullptr);  // Constructeur prenant un ID
    ~mainpagelivreur();

private slots:
    void on_pushButton_certifierreceptioncolis_clicked();  // Fonction pour ouvrir la fenêtre de certification
    void on_pushButton_deconnexion_clicked();  // Fonction pour déconnecter

private:
    Ui::mainpagelivreur *ui;
    int m_livreurId;  // Stocke l'ID du livreur

    void loadAssignedOrders();  // Charger les commandes assignées
};

#endif // MAINPAGELIVREUR_H
