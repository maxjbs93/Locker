#include "attribuercommandelivreur.h"
#include "ui_attribuercommandelivreur.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

AttribuerCommandeLivreur::AttribuerCommandeLivreur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::attribuercommandelivreur)
{
    ui->setupUi(this);
    setWindowTitle("Locker - Attribution d'une commande à un livreur");
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());

    // Charger les commandes et livreurs dès l'initialisation
    chargerCommandesEtLivreurs();
}

AttribuerCommandeLivreur::~AttribuerCommandeLivreur()
{
    delete ui;
}

void AttribuerCommandeLivreur::chargerCommandesEtLivreurs() {
    // Charger les commandes et livreurs depuis l'API
    obtenirListeCommandes();
    obtenirListeLivreurs();
}

void AttribuerCommandeLivreur::obtenirListeCommandes() {
    // Créer la requête pour obtenir les commandes
    QNetworkRequest request(QUrl("http://localhost:5000/afficher_commandes"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &AttribuerCommandeLivreur::onCommandesReceived);
    manager->get(request);
}

void AttribuerCommandeLivreur::onCommandesReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Réponse API Commandes complète : " << responseData;

        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = doc.object();
        qDebug() << "Structure JSON : " << jsonObject;

        // Récupérer les commandes
        QJsonArray commandesArray = jsonObject.value("commandes").toArray();
        if (commandesArray.isEmpty()) {
            qDebug() << "Aucune commande trouvée dans la réponse.";
        }

        // Vider le comboBox avant d'ajouter de nouvelles commandes
        ui->comboBoxCommandes->clear();

        QStringList commandes;
        for (const QJsonValue &value : commandesArray) {
            QJsonObject commandeObject = value.toObject();
            qDebug() << "Commande : " << commandeObject;

            // Convertir l'ID en QString
            QString commandeId = QString::number(commandeObject.value("id").toInt());
            QString statutCommande = commandeObject.value("statut").toString();  // Récupérer le statut de la commande

            // Ajouter uniquement les commandes en attente
            if (statutCommande == "en attente") {
                commandes << commandeId;  // Ajouter l'ID converti à la liste
                ui->comboBoxCommandes->addItem(commandeId);  // Ajouter l'ID de la commande dans le comboBox
            }
        }

        // Afficher un message si aucune commande en attente n'a été trouvée
        if (ui->comboBoxCommandes->count() == 0) {
            qDebug() << "Aucune commande en attente trouvée.";
        }

    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des commandes.");
    }
    reply->deleteLater();
}


void AttribuerCommandeLivreur::obtenirListeLivreurs() {
    // Créer la requête pour obtenir les livreurs
    QNetworkRequest request(QUrl("http://localhost:5000/afficher_livreurs"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &AttribuerCommandeLivreur::onLivreursReceived);
    manager->get(request);
}

void AttribuerCommandeLivreur::onLivreursReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        QJsonArray livreursArray = doc.object().value("livreurs").toArray();

        // Vider le comboBox avant d'ajouter de nouveaux livreurs
        ui->comboBoxLivreurs->clear();

        // Mettre à jour le comboBox des livreurs
        QStringList livreurs;
        for (const QJsonValue &value : livreursArray) {
            QJsonObject livreurObject = value.toObject();
            QString nomLivreur = livreurObject.value("nom").toString(); // Récupérer le nom du livreur
            int livreurId = livreurObject.value("id").toInt(); // Récupérer l'ID du livreur
            QString statutLivreur = livreurObject.value("statut").toString(); // Récupérer le statut du livreur

            livreurs << nomLivreur; // Ajouter le nom du livreur dans la liste
            // Associer l'ID du livreur à l'élément
            int index = ui->comboBoxLivreurs->count(); // index de l'élément ajouté
            ui->comboBoxLivreurs->addItem(nomLivreur, livreurId); // Stocke l'ID avec le nom

            // Si le livreur est "en cours de livraison", on désactive cet élément
            if (statutLivreur == "en cours de livraison") {
                ui->comboBoxLivreurs->setItemData(index, false, Qt::ItemIsEnabled);  // Désactiver le livreur
            }
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des livreurs.");
    }
    reply->deleteLater();
}


void AttribuerCommandeLivreur::on_pushButton_attribuer_clicked() {
    // Récupérer l'ID de la commande et le nom du livreur sélectionnés dans les ComboBox
    QString commandeSelectionnee = ui->comboBoxCommandes->currentText();
    QString livreurSelectionne = ui->comboBoxLivreurs->currentText();

    // Vérifier que la commande et le livreur sont bien sélectionnés
    if (commandeSelectionnee.isEmpty() || livreurSelectionne.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une commande et un livreur.");
        return;
    }

    // Maintenant, il nous faut obtenir l'ID du livreur à partir de son nom
    // Pour ce faire, on doit récupérer la liste des livreurs et leur associer un ID à chaque nom

    QString livreurId;
    QVariant livreurIdVariant = ui->comboBoxLivreurs->itemData(ui->comboBoxLivreurs->currentIndex()); // Récupérer l'ID du livreur
    livreurId = QString::number(livreurIdVariant.toInt()); // Conversion de l'ID en QString

    // Vérifier que l'ID du livreur a bien été trouvé
    if (livreurId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Livreur introuvable.");
        return;
    }

    // Appel de la fonction pour attribuer le livreur à la commande via l'API
    attribuerLivreurALaCommande(commandeSelectionnee, livreurId);
}

void AttribuerCommandeLivreur::attribuerLivreurALaCommande(const QString &commande, const QString &livreur) {
    // Créer la requête pour attribuer le livreur à la commande
    QNetworkRequest request(QUrl("http://localhost:5000/attribuer_livreur"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObject;
    jsonObject["commande_id"] = commande;  // L'ID de la commande
    jsonObject["livreur_id"] = livreur;    // L'ID du livreur

    QJsonDocument doc(jsonObject);
    QByteArray data = doc.toJson();

    // Envoyer la requête POST à l'API
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &AttribuerCommandeLivreur::onAttribuerLivreurResponse);
    manager->post(request, data);
}

void AttribuerCommandeLivreur::onAttribuerLivreurResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Succès", "Livreur attribué à la commande !");

        // Recharger les commandes et livreurs pour mettre à jour l'affichage
        chargerCommandesEtLivreurs();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'attribution du livreur.");
    }
    reply->deleteLater();
}
