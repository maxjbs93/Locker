#include "afficherlivreur.h"
#include "ui_afficherlivreur.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>

afficherlivreur::afficherlivreur(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::afficherlivreur)
{
    ui->setupUi(this);
    setWindowTitle("Locker - Affichage des différents livreurs");
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());


    // Configuration du tableau
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Prénom", "Adresse", "Username", "Statut"});
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        if (i >= 3)  // Colonnes Adresse, Username, Statut
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        else
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

    afficherLivreurs();  // Charger la liste des livreurs au démarrage

    // Connecter le bouton de suppression
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &afficherlivreur::supprimerLivreur);
}

afficherlivreur::~afficherlivreur()
{
    delete ui;
}

// Fonction pour afficher les livreurs dans le tableau
void afficherlivreur::afficherLivreurs()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonArray livreursArray = jsonResponse.object()["livreurs"].toArray();

            ui->tableWidget->setRowCount(livreursArray.size());

            for (int i = 0; i < livreursArray.size(); ++i) {
                QJsonObject livreur = livreursArray[i].toObject();

                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(livreur["id"].toInt())));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(livreur["nom"].toString()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem(livreur["prenom"].toString()));
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem(livreur["adresse"].toString()));
                ui->tableWidget->setItem(i, 4, new QTableWidgetItem(livreur["username"].toString()));
                ui->tableWidget->setItem(i, 5, new QTableWidgetItem(livreur["statut"].toString()));
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger les livreurs.");
        }
        reply->deleteLater();
    });

    manager->get(QNetworkRequest(QUrl("http://localhost:5000/afficher_livreurs")));  // URL de ton API Flask
}

// Fonction pour supprimer un livreur sélectionné
void afficherlivreur::supprimerLivreur()
{
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un livreur à supprimer.");
        return;
    }

    QString idLivreur = ui->tableWidget->item(row, 0)->text();  // Récupérer l'ID

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://localhost:5000/supprimer_livreur"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["id"] = idLivreur.toInt();

    QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(this, "Succès", "Livreur supprimé avec succès.");
            afficherLivreurs();  // Rafraîchir la liste
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
        reply->deleteLater();
    });
}
