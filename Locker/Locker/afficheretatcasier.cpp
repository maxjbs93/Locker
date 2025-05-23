#include "afficheretatcasier.h"
#include "ui_afficheretatcasier.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>  // Pour afficher des messages de débogage

afficheretatcasier::afficheretatcasier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::afficheretatcasier)
{
    ui->setupUi(this);
    setWindowTitle("Locker - Affichage de l'état des casiers");
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());


    // Ajouter les colonnes au tableWidget
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID Casier", "Taille", "Poids Max", "Etat", "Code", "ID Commande"});

    // Ajuster la taille des colonnes pour occuper toute la largeur
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Empêcher l'édition des cellules
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Sélectionner toute la ligne lorsqu'on clique sur une cellule
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Récupérer les données des casiers
    fetchCasierData();
}


afficheretatcasier::~afficheretatcasier()
{
    delete ui;
}

void afficheretatcasier::fetchCasierData()
{
    // Crée un gestionnaire de requêtes HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Connecte le signal de réponse à notre slot
    connect(manager, &QNetworkAccessManager::finished, this, &afficheretatcasier::onReplyFinished);

    // Envoie une requête GET pour récupérer les casiers
    QNetworkRequest request(QUrl("http://127.0.0.1:5000/afficher_etat_casiers"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    manager->get(request);
}

void afficheretatcasier::onReplyFinished(QNetworkReply *reply)
{
    // Vérifier les erreurs de réseau
    if (reply->error() != QNetworkReply::NoError) {
        // Affiche un message d'erreur en cas de problème de réseau
        QMessageBox::critical(this, "Erreur Réseau", reply->errorString());
        reply->deleteLater();
        return;
    }

    // Lire la réponse de l'API
    QByteArray response = reply->readAll();

    // Afficher la réponse dans la console pour déboguer
    qDebug() << "Réponse de l'API : " << response;

    // Convertir la réponse en document JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);

    // Vérifier si la réponse est un objet JSON
    if (!jsonDoc.isObject()) {
        QMessageBox::warning(this, "Erreur", "La réponse JSON n'est pas valide.");
        reply->deleteLater();
        return;
    }

    // Extraire l'objet JSON principal
    QJsonObject jsonObject = jsonDoc.object();

    // Vérifier si la clé "casiers" existe dans l'objet JSON
    if (!jsonObject.contains("casiers")) {
        QMessageBox::warning(this, "Erreur", "La clé 'casiers' est manquante dans la réponse JSON.");
        reply->deleteLater();
        return;
    }

    // Extraire le tableau des casiers
    QJsonArray casiersArray = jsonObject["casiers"].toArray();

    if (casiersArray.isEmpty()) {
        QMessageBox::information(this, "Aucun Casier", "Aucun casier trouvé.");
        reply->deleteLater();
        return;
    }

    // Affiche les casiers dans le tableau
    displayCasierData(casiersArray);
    reply->deleteLater();
}



void afficheretatcasier::displayCasierData(const QJsonArray &casiersArray)
{
    ui->tableWidget->setRowCount(casiersArray.size());

    // Affichage des données des casiers dans la console pour le débogage
    qDebug() << "Nombre de casiers : " << casiersArray.size();

    // Remplir les lignes de la table avec les données des casiers
    for (int i = 0; i < casiersArray.size(); ++i) {
        QJsonObject casier = casiersArray[i].toObject();

        qDebug() << "Casier " << i << ": " << casier;

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(casier["id_casier"].toInt())));

        // Vérification et nettoyage de la donnée 'taille'
        QString taille = casier["taille"].toString();
        taille = taille.replace("\\\"", ""); // Supprimer les guillemets échappés
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(taille));

        // Pour le poids_max, on vérifie le type de donnée et on essaie de le convertir correctement
        QVariant poidsVariant = casier["poids_max"].toVariant();
        double poidsMax = 0;

        if (poidsVariant.canConvert<double>()) {
            poidsMax = poidsVariant.toDouble();
        } else {
            // Si la conversion échoue, afficher un message pour débogage
            qDebug() << "Erreur de conversion pour poids_max, valeur : " << poidsVariant;
        }

        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(poidsMax)));

        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(casier["etat"].toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(casier["code"].toString()));

        // Si id_commande est null, afficher "Aucune"
        if (casier["id_commande"].isNull()) {
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem("Aucune"));
        } else {
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(casier["id_commande"].toInt())));
        }
    }
}

