#include "affichercommande.h"
#include "ui_affichercommande.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

affichercommande::affichercommande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::affichercommande)
{
    ui->setupUi(this);

    // Charger les commandes à l'initialisation
    chargerCommandes();

    // Connecter le bouton "Supprimer" pour supprimer la commande
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &affichercommande::supprimerCommande);
}

affichercommande::~affichercommande()
{
    delete ui;
}

// Fonction pour charger les commandes depuis l'API
void affichercommande::chargerCommandes()
{
    QString url = "http://127.0.0.1:5000/afficher_commandes";
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [reply, this]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument responseJson = QJsonDocument::fromJson(response_data);
            QJsonObject responseObject = responseJson.object();

            qDebug() << "Réponse API:" << responseObject;

            if (responseObject["status"].toString() == "success") {
                QJsonArray commandes = responseObject["commandes"].toArray();
                qDebug() << "Commandes reçues:" << commandes;

                // Mise à jour du nombre de colonnes pour inclure le statut
                ui->tableWidget_commandes->setRowCount(commandes.size());
                ui->tableWidget_commandes->setColumnCount(8);  // Ajout de la colonne statut
                ui->tableWidget_commandes->setHorizontalHeaderLabels(
                    {"ID", "Email Client", "Taille Casier", "Poids Colis",
                     "Nom Commerçant", "Adresse Commerçant", "Date Création", "Statut"}
                    );

                // Ajustement de la taille des colonnes
                ui->tableWidget_commandes->setColumnWidth(0, 50);   // ID
                ui->tableWidget_commandes->setColumnWidth(1, 150);  // Email Client
                ui->tableWidget_commandes->setColumnWidth(2, 75);   // Taille Casier
                ui->tableWidget_commandes->setColumnWidth(3, 75);   // Poids Colis
                ui->tableWidget_commandes->setColumnWidth(4, 150);  // Nom Commerçant
                ui->tableWidget_commandes->setColumnWidth(5, 150);  // Adresse Commerçant
                ui->tableWidget_commandes->setColumnWidth(6, 125);  // Date Création
                ui->tableWidget_commandes->setColumnWidth(7, 100);  // Statut
                ui->tableWidget_commandes->horizontalHeader()->setStretchLastSection(true);

                // Ajout des commandes au tableau
                for (int i = 0; i < commandes.size(); ++i) {
                    QJsonObject commande = commandes[i].toObject();
                    ui->tableWidget_commandes->setItem(i, 0, new QTableWidgetItem(QString::number(commande["id"].toInt())));
                    ui->tableWidget_commandes->setItem(i, 1, new QTableWidgetItem(commande["client_email"].toString()));
                    ui->tableWidget_commandes->setItem(i, 2, new QTableWidgetItem(commande["taille_casier"].toString()));
                    ui->tableWidget_commandes->setItem(i, 3, new QTableWidgetItem(commande["poids_colis"].toString()));
                    ui->tableWidget_commandes->setItem(i, 4, new QTableWidgetItem(commande["commercant_nom"].toString()));
                    ui->tableWidget_commandes->setItem(i, 5, new QTableWidgetItem(commande["commercant_adresse"].toString()));
                    ui->tableWidget_commandes->setItem(i, 6, new QTableWidgetItem(commande["date_creation"].toString()));
                    ui->tableWidget_commandes->setItem(i, 7, new QTableWidgetItem(commande["statut"].toString()));
                }
            } else {
                QMessageBox::warning(this, "Erreur", responseObject["message"].toString());
            }
        } else {
            QMessageBox::critical(this, "Erreur Réseau", reply->errorString());
        }
        reply->deleteLater();
    });
}

// Fonction pour supprimer une commande
void affichercommande::supprimerCommande()
{
    int row = ui->tableWidget_commandes->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une commande à supprimer.");
        return;
    }

    int commandeId = ui->tableWidget_commandes->item(row, 0)->text().toInt();
    QString url = "http://127.0.0.1:5000/supprimer_commande";
    QJsonObject json;
    json["commande_id"] = commandeId;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = manager->sendCustomRequest(request, "DELETE", data);

    connect(reply, &QNetworkReply::finished, [reply, this]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument responseJson = QJsonDocument::fromJson(response_data);
            QJsonObject responseObject = responseJson.object();

            if (responseObject["status"].toString() == "success") {
                QMessageBox::information(this, "Succès", responseObject["message"].toString());
                chargerCommandes();
            } else {
                QMessageBox::warning(this, "Erreur", responseObject["message"].toString());
            }
        } else {
            QMessageBox::critical(this, "Erreur Réseau", reply->errorString());
        }
        reply->deleteLater();
    });
}
