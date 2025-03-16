#ifndef CERTIFIERRECEPTIONCOLIS_H
#define CERTIFIERRECEPTIONCOLIS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QString>

namespace Ui {
class certifierreceptioncolis;
}

class certifierreceptioncolis : public QMainWindow
{
    Q_OBJECT

public:
    explicit certifierreceptioncolis(QWidget *parent = nullptr);
    ~certifierreceptioncolis();
    void setLivreurId(int id) {
        livreurId = id;
    }

private:
    Ui::certifierreceptioncolis *ui;
    QNetworkAccessManager *networkManager;
    int livreurId; // Identifiant du livreur connecté, à initialiser avec la valeur appropriée

    void loadAssignedOrders(); // Charger les commandes attribuées
    void updateTable(const QJsonArray &commandes); // Mettre à jour le tableau des commandes
    void repondreCommande(int commandeId, const QString &reponse); // Accepter ou refuser la commande
};

#endif // CERTIFIERRECEPTIONCOLIS_H
