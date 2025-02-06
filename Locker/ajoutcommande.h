#ifndef AJOUTCOMMANDE_H
#define AJOUTCOMMANDE_H

#include <QMainWindow>

namespace Ui {
class ajoutcommande;
}

class ajoutcommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit ajoutcommande(QWidget *parent = nullptr);
    ~ajoutcommande();

private:
    Ui::ajoutcommande *ui;
};

#endif // AJOUTCOMMANDE_H
