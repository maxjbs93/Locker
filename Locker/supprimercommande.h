#ifndef SUPPRIMERCOMMANDE_H
#define SUPPRIMERCOMMANDE_H

#include <QMainWindow>

namespace Ui {
class supprimercommande;
}

class supprimercommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit supprimercommande(QWidget *parent = nullptr);
    ~supprimercommande();

private:
    Ui::supprimercommande *ui;
};

#endif // SUPPRIMERCOMMANDE_H
