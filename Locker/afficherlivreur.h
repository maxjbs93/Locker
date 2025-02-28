#ifndef AFFICHERLIVREUR_H
#define AFFICHERLIVREUR_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTableWidget>

namespace Ui {
class afficherlivreur;
}

class afficherlivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit afficherlivreur(QWidget *parent = nullptr);
    ~afficherlivreur();

private slots:
    void afficherLivreurs();  // Déclaration de la fonction
    void supprimerLivreur();  // Déclaration de la fonction

private:
    Ui::afficherlivreur *ui;
};

#endif // AFFICHERLIVREUR_H
