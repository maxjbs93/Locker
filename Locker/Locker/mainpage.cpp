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

void MainPage::on_pushButton_afficher_commande_clicked()
{
    affichercommande *newPage = new affichercommande(this);
    newPage->show();
}


void MainPage::on_pushButton_afficher_etat_casier_clicked()
{
    afficheretatcasier *newPage = new afficheretatcasier(this);
    newPage->show();
}


void MainPage::on_pushButton_attribuer_commande_livreur_clicked()
{
    AttribuerCommandeLivreur *newPage = new AttribuerCommandeLivreur(this);
    newPage->show();
}



void MainPage::on_pushButton_afficher_livreur_clicked()
{
    afficherlivreur *newPage = new afficherlivreur(this);
    newPage->show();
}

void MainPage::on_pushButton_deconnexion_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

