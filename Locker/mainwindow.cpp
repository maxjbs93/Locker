#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDebug>

#include "mainpage.h"  // Fichier pour l'interface commerçant
#include "mainpagelivreur.h"    // Fichier pour l'interface livreur
#include "certifierreceptioncolis.h"  // Importation de la classe certifierreceptioncolis

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
    login();
}

void MainWindow::on_pushButton_cancel_clicked()
{
    this->close();
}

void MainWindow::login()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("http://127.0.0.1:5000/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = manager->post(request, data);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            QMessageBox::warning(this, "Erreur Réseau", reply->errorString());
            reply->deleteLater();
            return;
        }

        QByteArray response_data = reply->readAll();
        QJsonDocument response_json = QJsonDocument::fromJson(response_data);
        QJsonObject response_obj = response_json.object();

        if (response_obj["status"].toString() == "success") {
            QJsonObject user = response_obj["user"].toObject();
            QString role = user["role"].toString();
            QString username = user["username"].toString();  // Récupérer le username

            if (role == "commercant") {
                QMessageBox::information(this, "Connexion réussie", "Bienvenue, " + username + " !");
                MainPage *mainPage = new MainPage();
                mainPage->show();
            } else if (role == "livreur") {
                QMessageBox::information(this, "Connexion réussie", "Bienvenue, " + username + " !");

                // Récupère l'ID du livreur depuis la réponse du backend
                int livreurId = user["id"].toInt();  // Récupérer l'ID du livreur

                qDebug() << "ID du livreur transmis : " << livreurId;

                // Ouvre la fenêtre principale du livreur
                mainpagelivreur *newPage = new mainpagelivreur(livreurId);  // Passe l'ID du livreur
                newPage->show();
            }

            // Ferme la fenêtre de login après l'ouverture de la page correspondante
            this->close();
        } else {
            QMessageBox::warning(this, "Erreur", response_obj["message"].toString());
        }

        reply->deleteLater();
    });
}
