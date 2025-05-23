#include "mainpagelivreur.h"
#include "ui_mainpagelivreur.h"
#include "certifierreceptioncolis.h"

mainpagelivreur::mainpagelivreur(int livreurId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainpagelivreur)
    , m_livreurId(livreurId)  // Initialiser l'ID du livreur
{
    ui->setupUi(this);
    setWindowTitle("Locker - Menu principal côté livreur");
    if (livreurId == 0) {
        QMessageBox::warning(this, "Erreur", "ID du livreur non défini.");
    } else {
        // Ici, tu peux charger les informations du livreur et les commandes attribuées
        loadAssignedOrders();  // Appelle une méthode pour charger les commandes
    }
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(size());

}

mainpagelivreur::~mainpagelivreur()
{
    delete ui;
}

void mainpagelivreur::loadAssignedOrders()
{
    // Assure-toi que cette méthode utilise correctement l'ID du livreur
    if (m_livreurId == 0) {
        QMessageBox::warning(this, "Erreur", "ID du livreur non défini.");
        return;
    }

    // Charger les commandes attribuées au livreur en utilisant l'ID
    // Par exemple, utiliser l'ID pour appeler une API ou une base de données
}

void mainpagelivreur::on_pushButton_certifierreceptioncolis_clicked()
{
    // Ouvre la fenêtre de certification de réception des colis
    certifierreceptioncolis *newPage = new certifierreceptioncolis(this);

    // Passe l'ID du livreur à la fenêtre de certification
    newPage->setLivreurId(m_livreurId);  // Utilise m_livreurId

    newPage->show();  // Affiche la fenêtre de certification
}

void mainpagelivreur::on_pushButton_deconnexion_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}
