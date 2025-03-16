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

certifierreceptioncolis::certifierreceptioncolis(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::certifierreceptioncolis)
    , networkManager(new QNetworkAccessManager(this))  // Initialisation du gestionnaire réseau
{
    ui->setupUi(this);
    loadAssignedOrders(); // Charger les commandes attribuées au livreur
}

certifierreceptioncolis::~certifierreceptioncolis()
{
    delete ui;
    delete networkManager;
}

// Charger les commandes attribuées au livreur connecté
void certifierreceptioncolis::loadAssignedOrders()
{
    QString apiUrl = "http://localhost:5000/livreur/commandes_attribuees";  // Endpoint pour récupérer les commandes
    QNetworkRequest request{QUrl(apiUrl)};  // Utilisation des accolades ici, pas de parenthèses

    QNetworkReply *reply = networkManager->get(request);  // Utilisation correcte de `get`
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonArray commandes = doc.object().value("commandes").toArray();
            updateTable(commandes);
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger les commandes.");
        }
        reply->deleteLater();
    });
}


// Met à jour le tableau avec les commandes attribuées
void certifierreceptioncolis::updateTable(const QJsonArray &commandes)
{
    ui->tableWidget->setRowCount(commandes.size());
    ui->tableWidget->setColumnCount(4); // ID, Client, Taille Casier, Actions

    for (int i = 0; i < commandes.size(); ++i) {
        QJsonObject commande = commandes[i].toObject();

        int commandeId = commande["id"].toInt();
        QString clientEmail = commande["client_email"].toString();
        QString tailleCasier = commande["taille_casier"].toString();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(commandeId)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(clientEmail));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tailleCasier));

        // Boutons Accepter / Refuser
        QPushButton *btnAccepter = new QPushButton("Accepter", this);
        QPushButton *btnRefuser = new QPushButton("Refuser", this);

        connect(btnAccepter, &QPushButton::clicked, this, [this, commandeId]() { repondreCommande(commandeId, "accepter"); });
        connect(btnRefuser, &QPushButton::clicked, this, [this, commandeId]() { repondreCommande(commandeId, "refuser"); });

        QWidget *buttonContainer = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(buttonContainer);
        layout->addWidget(btnAccepter);
        layout->addWidget(btnRefuser);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(i, 3, buttonContainer);
    }
}

void certifierreceptioncolis::repondreCommande(int idCommande, const QString &apiUrl)
{
    // Utiliser des accolades pour déclarer l'objet request de manière explicite
    QNetworkRequest request{QUrl(apiUrl)};  // Crée un objet QNetworkRequest à partir de l'URL

    // Définir l'en-tête du type de contenu
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Création d'un objet JSON pour la commande
    QJsonObject json;
    json["id_commande"] = idCommande;

    // Envoi de la requête POST avec les données JSON
    QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());

    // Connexion du signal 'finished' pour gérer la réponse
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Si la requête réussie, afficher un message de succès
            QMessageBox::information(this, "Succès", "La commande a été mise à jour avec succès.");
        } else {
            // Si la requête échoue, afficher un message d'erreur
            QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la commande.");
        }
        // Supprimer l'objet reply après son utilisation
        reply->deleteLater();
    });
}

