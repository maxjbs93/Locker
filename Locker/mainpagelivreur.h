#ifndef MAINPAGELIVREUR_H
#define MAINPAGELIVREUR_H

#include <QMainWindow>
#include "certifierreceptioncolis.h"

namespace Ui {
class mainpagelivreur;
}

class mainpagelivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpagelivreur(QWidget *parent = nullptr);
    ~mainpagelivreur();

private slots:
    void on_pushButton_certifierreceptioncolis_clicked();

private:
    Ui::mainpagelivreur *ui;
};

#endif // MAINPAGELIVREUR_H
