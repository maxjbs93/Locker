#ifndef CERTIFIERRECEPTIONCOLIS_H
#define CERTIFIERRECEPTIONCOLIS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QJsonArray>

namespace Ui {
class certifierreceptioncolis;
}

class certifierreceptioncolis : public QMainWindow
{
    Q_OBJECT

public:
    explicit certifierreceptioncolis(QWidget *parent = nullptr);
    ~certifierreceptioncolis();

    void setLivreurId(int id); // Permet de définir l'ID du livreur connecté

private:
    Ui::certifierreceptioncolis *ui;
    QNetworkAccessManager *networkManager;

    int idLivreur = 0; // ID du livreur connecté (0 par défaut)

    void loadAssignedOrders(); // Charger les commandes du livreur
    void updateTable(const QJsonArray &commandes); // Met à jour la table des commandes
    void repondreCommande(int idCommande, const QString &action); // Répondre à une commande
};

#endif // CERTIFIERRECEPTIONCOLIS_H
