#ifndef AFFICHERCOMMANDE_H
#define AFFICHERCOMMANDE_H

#include <QMainWindow>

namespace Ui {
class affichercommande;
}

class affichercommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit affichercommande(QWidget *parent = nullptr);
    ~affichercommande();

private slots:
    // Fonction pour charger les commandes depuis l'API
    void chargerCommandes();

    // Fonction pour supprimer la commande
    void supprimerCommande();

private:
    Ui::affichercommande *ui;  // Interface utilisateur générée par Qt Designer
};

#endif // AFFICHERCOMMANDE_H
