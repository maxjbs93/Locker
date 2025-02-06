#ifndef AFFICHERETATCASIER_H
#define AFFICHERETATCASIER_H

#include <QMainWindow>

namespace Ui {
class afficheretatcasier;
}

class afficheretatcasier : public QMainWindow
{
    Q_OBJECT

public:
    explicit afficheretatcasier(QWidget *parent = nullptr);
    ~afficheretatcasier();

private:
    Ui::afficheretatcasier *ui;
};

#endif // AFFICHERETATCASIER_H
