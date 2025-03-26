#include "certifierreceptioncolis.h"
#include "ui_certifierreceptioncolis.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTableWidgetItem>
#include <QDebug>

// Définition de la méthode pour définir l'ID du livreur
void certifierreceptioncolis::setLivreurId(int id)
{
    idLivreur = id;  // Stockage de l'ID du livreur
    qDebug() << "ID du livreur défini : " << idLivreur;  // Débogage pour vérifier l'ID
    loadAssignedOrders();  // Charger les commandes dès que l'ID est défini
}

certifierreceptioncolis::certifierreceptioncolis(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::certifierreceptioncolis)
    , networkManager(new QNetworkAccessManager(this))  // Initialisation du gestionnaire réseau
{
    ui->setupUi(this);
}

certifierreceptioncolis::~certifierreceptioncolis()
{
    delete ui;
    delete networkManager;
}

// Charger les commandes attribuées au livreur connecté
void certifierreceptioncolis::loadAssignedOrders()
{
    if (idLivreur == 0) {  // Vérifie si l'ID est défini
        QMessageBox::warning(this, "Erreur", "ID du livreur non défini.");
        return;
    }

    // URL de l'API pour récupérer les commandes attribuées au livreur spécifique
    QString apiUrl = "http://localhost:5000/livreur/commandes_attribuees/" + QString::number(idLivreur);
    QNetworkRequest request{QUrl(apiUrl)};

    // Envoi de la requête GET pour récupérer les commandes
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Si la requête réussie, parse les données JSON
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());

            // Ajout de débogage pour afficher la réponse JSON brute
            qDebug() << "Réponse de l'API : " << doc.toJson();

            QJsonArray commandes = doc.object().value("commandes").toArray();
            if (commandes.isEmpty()) {
                qDebug() << "Aucune commande trouvée pour ce livreur.";
            } else {
                qDebug() << "Commandes reçues : " << commandes.size();
            }

            updateTable(commandes);  // Met à jour le tableau avec les commandes reçues
        } else {
            // Affichage d'un message d'erreur si la requête échoue
            QMessageBox::warning(this, "Erreur", "Impossible de charger les commandes.");
        }
        reply->deleteLater();  // Libère la mémoire utilisée par la réponse
    });
}


// Met à jour le tableau avec les commandes attribuées
void certifierreceptioncolis::updateTable(const QJsonArray &commandes)
{
    if (commandes.isEmpty()) {
        qDebug() << "Aucune commande à afficher dans le tableau.";
        return;
    }

    ui->tableWidget->setRowCount(commandes.size());  // Ajuste le nombre de lignes
    ui->tableWidget->setColumnCount(4);  // Définit le nombre de colonnes (ID, Client, Taille Casier, Actions)

    // Parcours les commandes et remplit le tableau
    for (int i = 0; i < commandes.size(); ++i) {
        QJsonObject commande = commandes[i].toObject();

        int commandeId = commande["id"].toInt();
        QString clientEmail = commande["client_email"].toString();
        QString tailleCasier = commande["taille_casier"].toString();

        // Débogage pour vérifier que les données sont extraites correctement
        qDebug() << "Commande " << commandeId << " - Client: " << clientEmail << " - Taille Casier: " << tailleCasier;

        // Remplissage des cellules du tableau
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(commandeId)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(clientEmail));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tailleCasier));

        // Création des boutons Accepter / Refuser
        QPushButton *btnAccepter = new QPushButton("Accepter", this);
        QPushButton *btnRefuser = new QPushButton("Refuser", this);

        // Connexion des boutons à des slots pour répondre à la commande
        connect(btnAccepter, &QPushButton::clicked, this, [this, commandeId]() { repondreCommande(commandeId, "accepter"); });
        connect(btnRefuser, &QPushButton::clicked, this, [this, commandeId]() { repondreCommande(commandeId, "refuser"); });

        // Conteneur de boutons dans un layout horizontal
        QWidget *buttonContainer = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(buttonContainer);
        layout->addWidget(btnAccepter);
        layout->addWidget(btnRefuser);
        layout->setContentsMargins(0, 0, 0, 0);

        // Affectation du conteneur de boutons dans la cellule de la colonne "Actions"
        ui->tableWidget->setCellWidget(i, 3, buttonContainer);
    }

    ui->tableWidget->repaint();  // Forcer le rafraîchissement du tableau
}


// Méthode pour répondre à une commande (Accepter ou Refuser)
void certifierreceptioncolis::repondreCommande(int idCommande, const QString &action)
{
    // Construction de l'URL complète de l'API
    QString apiUrl = "http://localhost:5000/commande/" + action;
    QNetworkRequest request{QUrl(apiUrl)};  // URL de l'API pour accepter ou refuser la commande

    // Définition de l'en-tête de la requête
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Création de l'objet JSON avec l'ID de la commande
    QJsonObject json;
    json["id_commande"] = idCommande;

    // Envoi de la requête POST avec les données JSON
    QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());

    // Connexion du signal 'finished' pour gérer la réponse
    connect(reply, &QNetworkReply::finished, this, [this, reply, action, idCommande]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Si la requête réussie, afficher un message de succès
            QMessageBox::information(this, "Succès",
                                     action == "accepter" ?
                                         "La commande a été acceptée avec succès." :
                                         "La commande a été refusée avec succès.");

            // Rechercher et supprimer la ligne correspondant à cette commande
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                QTableWidgetItem* item = ui->tableWidget->item(row, 0); // Colonne ID
                if (item && item->text().toInt() == idCommande) {
                    ui->tableWidget->removeRow(row);
                    break;
                }
            }
        } else {
            // Si la requête échoue, afficher un message d'erreur avec plus de détails
            QMessageBox::warning(this, "Erreur",
                                 "Erreur lors de la mise à jour de la commande: " +
                                     reply->errorString());
        }
        // Libérer la mémoire utilisée par la réponse
        reply->deleteLater();
    });
}
