#ifndef ATTRIBUERCOMMANDELIVREUR_H
#define ATTRIBUERCOMMANDELIVREUR_H

#include <QMainWindow>
#include <QNetworkReply>

namespace Ui {
class attribuercommandelivreur;
}

class AttribuerCommandeLivreur : public QMainWindow

{
    Q_OBJECT

public:
    explicit AttribuerCommandeLivreur(QWidget *parent = nullptr);
    ~AttribuerCommandeLivreur();

private slots:
    // Slot pour charger les commandes et les livreurs
    void chargerCommandesEtLivreurs();

    // Slots pour la gestion des réponses des API
    void onCommandesReceived(QNetworkReply *reply);
    void onLivreursReceived(QNetworkReply *reply);
    void onAttribuerLivreurResponse(QNetworkReply *reply);
    void on_pushButton_attribuer_clicked();

private:
    // Méthodes pour récupérer la liste des commandes et livreurs
    void obtenirListeCommandes();
    void obtenirListeLivreurs();

    // Méthode pour attribuer un livreur à une commande
    void attribuerLivreurALaCommande(const QString &commande, const QString &livreur);

    Ui::attribuercommandelivreur *ui;
};

#endif // ATTRIBUERCOMMANDELIVREUR_H
