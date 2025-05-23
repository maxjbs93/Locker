#include "ajoutlivreur.h"
#include "ui_ajoutlivreur.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDebug>

ajoutlivreur::ajoutlivreur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ajoutlivreur)
{
    ui->setupUi(this);
    setWindowTitle("Locker - Ajout d'un livreur");
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());

}

ajoutlivreur::~ajoutlivreur()
{
    delete ui;
}

void ajoutlivreur::on_pushButton_annuler_clicked()
{
    this->close(); // Ferme la fenêtre actuelle
}

void ajoutlivreur::on_pushButton_ajouter_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Vérifie que tous les champs sont remplis
    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Création de la requête HTTP pour envoyer les données
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("http://127.0.0.1:5000/ajouter_livreur");  // Modifie l'URL selon ta route dans l'API
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Création du JSON avec les informations du livreur
    QJsonObject json;
    json["nom"] = nom;
    json["prenom"] = prenom;
    json["adresse"] = adresse;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    qDebug() << "Envoi de la requête POST vers" << url.toString();
    qDebug() << "Données envoyées :" << data;

    // Envoi de la requête POST
    QNetworkReply *reply = manager->post(request, data);

    // Gérer la réponse de l'API
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Erreur réseau :" << reply->errorString();
            QMessageBox::warning(this, "Erreur Réseau", reply->errorString());
            reply->deleteLater();
            return;
        }

        QByteArray response_data = reply->readAll();
        qDebug() << "Réponse reçue de l'API :" << response_data;

        QJsonDocument response_json = QJsonDocument::fromJson(response_data);
        QJsonObject response_obj = response_json.object();

        if (response_obj["status"].toString() == "success") {
            QMessageBox::information(this, "Succès", "Livreur ajouté avec succès !");
            this->close();  // Ferme la fenêtre d'ajout après succès
        } else {
            QMessageBox::warning(this, "Erreur", response_obj["message"].toString());
        }

        reply->deleteLater();
    });
}
