#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}


void MainPage::on_pushButton_ajout_livreur_clicked()
{
    ajoutlivreur *newPage = new ajoutlivreur(this);
    newPage->show();
}


void MainPage::on_pushButton_new_commande_clicked()
{
    ajoutcommande *newPage = new ajoutcommande(this);
    newPage->show();
}


void MainPage::on_pushButton_supp_commande_clicked()
{
    supprimercommande *newPage = new supprimercommande(this);
    newPage->show();
}


void MainPage::on_pushButton_afficher_etat_casier_clicked()
{
    afficheretatcasier *newPage = new afficheretatcasier(this);
    newPage->show();
}


void MainPage::on_pushButton_certifier_reception_clicked()
{
    certifierreceptioncolis *newPage = new certifierreceptioncolis(this);
    newPage->show();
}

