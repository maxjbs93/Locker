#include "afficheretatcasier.h"
#include "ui_afficheretatcasier.h"

afficheretatcasier::afficheretatcasier(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::afficheretatcasier)
{
    ui->setupUi(this);
}

afficheretatcasier::~afficheretatcasier()
{
    delete ui;
}
