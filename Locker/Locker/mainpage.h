#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "ajoutlivreur.h"
#include "ajoutcommande.h"
#include "afficheretatcasier.h"
#include "attribuercommandelivreur.h"
#include "affichercommande.h"
#include "afficherlivreur.h"
#include "mainwindow.h"
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

    void on_pushButton_afficher_etat_casier_clicked();

    void on_pushButton_afficher_commande_clicked();

    void on_pushButton_attribuer_commande_livreur_clicked();

    void on_pushButton_afficher_livreur_clicked();

    void on_pushButton_deconnexion_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
