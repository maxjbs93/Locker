#ifndef ATTRIBUERCOMMANDELIVREUR_H
#define ATTRIBUERCOMMANDELIVREUR_H

#include <QMainWindow>

namespace Ui {
class attribuercommandelivreur;
}

class attribuercommandelivreur : public QMainWindow
{
    Q_OBJECT

public:
    explicit attribuercommandelivreur(QWidget *parent = nullptr);
    ~attribuercommandelivreur();

private:
    Ui::attribuercommandelivreur *ui;
};

#endif // ATTRIBUERCOMMANDELIVREUR_H
