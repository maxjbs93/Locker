#include "ajoutcommande.h"
#include "ui_ajoutcommande.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>

ajoutcommande::ajoutcommande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ajoutcommande)
{
    ui->setupUi(this);
    setWindowTitle("Locker - Saisie d'une commande");
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());


    // Ajouter les options au ComboBox
    ui->comboBox_taille->addItem("choisissez une option");
    ui->comboBox_taille->addItem("petit");
    ui->comboBox_taille->addItem("moyen");
    ui->comboBox_taille->addItem("grand");

    // Désactiver la première option
    ui->comboBox_taille->setItemData(0, 0, Qt::UserRole - 1);

    // Empêcher la sélection de "choisissez une option"
    connect(ui->comboBox_taille, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index == 0) {
                    ui->comboBox_taille->setCurrentIndex(1); // Sélectionner "petit" par défaut
                }
            });
}

ajoutcommande::~ajoutcommande()
{
    delete ui;
}

void ajoutcommande::on_pushButton_annuler_clicked()
{
    this->close(); // Ferme la fenêtre actuelle
}

void ajoutcommande::on_pushButton_ajouter_clicked()
{
    // Vérification que tous les champs sont remplis
    if (ui->lineEdit_mail->text().isEmpty() ||
        ui->comboBox_taille->currentIndex() == 0 || // Vérifie si une taille valide est sélectionnée
        ui->lineEdit_poids->text().isEmpty() ||
        ui->lineEdit_nom->text().isEmpty() ||
        ui->lineEdit_adresse->text().isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs avant de soumettre.");
        return;
    }

    // URL de l'API Flask
    QString url = "http://127.0.0.1:5000/ajouter_commande";

    // Création du JSON
    QJsonObject json;
    json["client_email"] = ui->lineEdit_mail->text();  // Correspond à l'email du client
    json["taille_casier"] = ui->comboBox_taille->currentText();  // Taille du casier
    json["poids_colis"] = ui->lineEdit_poids->text();  // Poids du colis
    json["commercant_nom"] = ui->lineEdit_nom->text();  // Nom du commerçant
    json["commercant_adresse"] = ui->lineEdit_adresse->text();  // Adresse du commerçant

    // Préparation de la requête HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Conversion du JSON en QByteArray
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // Envoyer la requête POST
    QNetworkReply *reply = manager->post(request, data);

    // Gérer la réponse
    connect(reply, &QNetworkReply::finished, [reply, this]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument responseJson = QJsonDocument::fromJson(response_data);
            QJsonObject responseObject = responseJson.object();

            if (responseObject["status"].toString() == "success") {
                QMessageBox::information(this, "Succès", responseObject["message"].toString());
                clearFields(); // Efface les champs après succès
            } else {
                QMessageBox::warning(this, "Erreur", responseObject["message"].toString());
            }
        } else {
            QMessageBox::critical(this, "Erreur Réseau", reply->errorString());
        }
        reply->deleteLater();
    });
}

void ajoutcommande::clearFields()
{
    ui->lineEdit_mail->clear();
    ui->comboBox_taille->setCurrentIndex(1); // Sélectionne "petit" par défaut
    ui->lineEdit_poids->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
}
