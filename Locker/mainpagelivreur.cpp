#include "mainpagelivreur.h"
#include "ui_mainpagelivreur.h"

mainpagelivreur::mainpagelivreur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainpagelivreur)
{
    ui->setupUi(this);
}

mainpagelivreur::~mainpagelivreur()
{
    delete ui;
}
