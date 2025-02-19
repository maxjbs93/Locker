#ifndef AFFICHERETATCASIER_H
#define AFFICHERETATCASIER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>

namespace Ui {
class afficheretatcasier;
}

class afficheretatcasier : public QMainWindow
{
    Q_OBJECT

public:
    explicit afficheretatcasier(QWidget *parent = nullptr);
    ~afficheretatcasier();

private slots:
    void fetchCasierData();  // Récupérer les casiers depuis l'API
    void onReplyFinished(QNetworkReply *reply);  // Gestion de la réponse API
    void displayCasierData(const QJsonArray &casiersArray);  // Affichage des casiers dans la table

private:
    Ui::afficheretatcasier *ui;
    QNetworkAccessManager *networkManager;  // Gestionnaire de requêtes HTTP
};

#endif // AFFICHERETATCASIER_H
