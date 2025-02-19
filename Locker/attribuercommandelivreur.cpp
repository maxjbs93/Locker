#include "attribuercommandelivreur.h"
#include "ui_attribuercommandelivreur.h"

attribuercommandelivreur::attribuercommandelivreur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::attribuercommandelivreur)
{
    ui->setupUi(this);
}

attribuercommandelivreur::~attribuercommandelivreur()
{
    delete ui;
}
