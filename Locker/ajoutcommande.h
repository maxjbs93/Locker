#ifndef AJOUTCOMMANDE_H
#define AJOUTCOMMANDE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class ajoutcommande;
}

class ajoutcommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit ajoutcommande(QWidget *parent = nullptr);
    ~ajoutcommande();

private slots:
    void on_pushButton_annuler_clicked();
    void on_pushButton_ajouter_clicked();
    void clearFields(); // Ajout pour réinitialiser les champs après succès

private:
    Ui::ajoutcommande *ui;
    QNetworkAccessManager *networkManager; // Gère les requêtes HTTP
};

#endif // AJOUTCOMMANDE_H
