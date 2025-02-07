#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    login(); // Appelle la fonction login()
}

void MainWindow::on_pushButton_cancel_clicked()
{
    this->close(); // Ferme la fenêtre de connexion
}

void MainWindow::login()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Création de la requête HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("http://127.0.0.1:5000/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Création du JSON avec les identifiants
    QJsonObject json;
    json["pseudo"] = username; // Utilise 'pseudo' ici au lieu de 'username'
    json["mdp"] = password;    // Utilise 'mdp' ici au lieu de 'password'
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
            QMessageBox::information(this, "Connexion réussie", "Bienvenue !");
            MainPage *mainPage = new MainPage();
            mainPage->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Erreur", response_obj["message"].toString());
        }

        reply->deleteLater();
    });
}
