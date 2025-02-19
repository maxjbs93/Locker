#ifndef AFFICHERCOMMANDE_H
#define AFFICHERCOMMANDE_H

#include <QMainWindow>

namespace Ui {
class affichercommande;
}

class affichercommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit affichercommande(QWidget *parent = nullptr);
    ~affichercommande();

private slots:
    void chargerCommandes();
    void supprimerCommande();  // Assure-toi que cette ligne est bien présente !

private:
    Ui::affichercommande *ui;
};

#endif // AFFICHERCOMMANDE_H
