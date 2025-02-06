#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString UserName = ui->lineEdit_username->text();
    QString Password = ui->lineEdit_password->text();
    if (UserName == "maxime" && Password == "1234")
    {
        QMessageBox::information(this,"maxime","Connexion réussie !");
        this->hide();
        MainPage *mainpage = new MainPage();
        mainpage->show();
    }
    else
    {
        QMessageBox::warning(this,"maxime", "Identifiants ou mots de passe inccorects.");
    }
}


void MainWindow::on_pushButton_cancel_clicked()
{
    QApplication::quit();
}

