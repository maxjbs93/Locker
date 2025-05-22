#include "certifierlivraisoncommande.h"
#include "ui_certifierlivraisoncommande.h" // Ceci est généré automatiquement par Qt

CertifierLivraisonCommande::CertifierLivraisonCommande(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CertifierLivraisonCommande)
{
    ui->setupUi(this);
}

CertifierLivraisonCommande::~CertifierLivraisonCommande()
{
    delete ui;
}

void CertifierLivraisonCommande::setLivreurId(int livreurId)
{
    m_livreurId = livreurId;
    // Assure-toi que le livreurId est bien utilisé où tu en as besoin
}
