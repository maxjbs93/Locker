#include "ajoutcommande.h"
#include "ui_ajoutcommande.h"

ajoutcommande::ajoutcommande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ajoutcommande)
{
    ui->setupUi(this);
}

ajoutcommande::~ajoutcommande()
{
    delete ui;
}
