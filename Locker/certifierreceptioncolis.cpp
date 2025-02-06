#include "certifierreceptioncolis.h"
#include "ui_certifierreceptioncolis.h"

certifierreceptioncolis::certifierreceptioncolis(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::certifierreceptioncolis)
{
    ui->setupUi(this);
}

certifierreceptioncolis::~certifierreceptioncolis()
{
    delete ui;
}
