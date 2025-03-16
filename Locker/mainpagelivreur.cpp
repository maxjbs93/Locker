#include "mainpagelivreur.h"
#include "ui_mainpagelivreur.h"
#include "certifierreceptioncolis.h"

mainpagelivreur::mainpagelivreur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainpagelivreur)
{
    ui->setupUi(this);
    // Ajoute d'autres initialisations si nécessaire
}

mainpagelivreur::~mainpagelivreur()
{
    delete ui;
}

// Supposons que livreurId est déjà défini quelque part dans ton code
int livreurId = 1;  // Exemple d'ID de livreur, tu dois récupérer cet ID lors de la connexion

void mainpagelivreur::on_pushButton_certifierreceptioncolis_clicked()
{
    // Ouvre la fenêtre de certification de réception des colis
    certifierreceptioncolis *newPage = new certifierreceptioncolis(this);

    // Passe l'ID du livreur à la fenêtre de certification
    newPage->setLivreurId(livreurId);  // Passe l'ID du livreur à la fenêtre

    newPage->show();  // Affiche la fenêtre de certification
}
