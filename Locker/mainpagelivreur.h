#ifndef MAINPAGELIVREUR_H
#define MAINPAGELIVREUR_H

#include <QMainWindow>

namespace Ui {
class mainpagelivreur;
}

class mainpagelivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpagelivreur(QWidget *parent = nullptr);
    ~mainpagelivreur();

private:
    Ui::mainpagelivreur *ui;
};

#endif // MAINPAGELIVREUR_H
