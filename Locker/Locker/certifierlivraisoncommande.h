#ifndef CERTIFIERLIVRAISSONCOMMANDE_H
#define CERTIFIERLIVRAISSONCOMMANDE_H

#include <QWidget>

namespace Ui {
class CertifierLivraisonCommande;
}

class CertifierLivraisonCommande : public QWidget
{
    Q_OBJECT

public:
    explicit CertifierLivraisonCommande(QWidget *parent = nullptr);
    ~CertifierLivraisonCommande();

    void setLivreurId(int livreurId); // Méthode pour définir l'ID du livreur

private:
    Ui::CertifierLivraisonCommande *ui;
    int m_livreurId;
};

#endif // CERTIFIERLIVRAISSONCOMMANDE_H
