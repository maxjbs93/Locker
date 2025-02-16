#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "ajoutlivreur.h"
#include "ajoutcommande.h"
#include "afficheretatcasier.h"
#include "certifierreceptioncolis.h"
#include "affichercommande.h"
namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_pushButton_ajout_livreur_clicked();

    void on_pushButton_new_commande_clicked();

    void on_pushButton_supp_commande_clicked();

    void on_pushButton_afficher_etat_casier_clicked();

    void on_pushButton_certifier_reception_clicked();

    void on_pushButton_afficher_commande_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
