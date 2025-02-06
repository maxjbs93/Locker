#ifndef AJOUTLIVREUR_H
#define AJOUTLIVREUR_H

#include <QMainWindow>

namespace Ui {
class ajoutlivreur;
}

class ajoutlivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit ajoutlivreur(QWidget *parent = nullptr);
    ~ajoutlivreur();

private:
    Ui::ajoutlivreur *ui;
};

#endif // AJOUTLIVREUR_H
