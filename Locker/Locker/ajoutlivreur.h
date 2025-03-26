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

private slots:
    void on_pushButton_annuler_clicked();

    void on_pushButton_ajouter_clicked();

private:
    Ui::ajoutlivreur *ui;
};

#endif // AJOUTLIVREUR_H
