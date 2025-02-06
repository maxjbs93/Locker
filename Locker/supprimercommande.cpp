#include "supprimercommande.h"
#include "ui_supprimercommande.h"

supprimercommande::supprimercommande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::supprimercommande)
{
    ui->setupUi(this);
}

supprimercommande::~supprimercommande()
{
    delete ui;
}
