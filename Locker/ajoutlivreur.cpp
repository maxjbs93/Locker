#include "ajoutlivreur.h"
#include "ui_ajoutlivreur.h"

ajoutlivreur::ajoutlivreur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ajoutlivreur)
{
    ui->setupUi(this);
}

ajoutlivreur::~ajoutlivreur()
{
    delete ui;
}
