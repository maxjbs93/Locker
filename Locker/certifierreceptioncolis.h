#ifndef CERTIFIERRECEPTIONCOLIS_H
#define CERTIFIERRECEPTIONCOLIS_H

#include <QMainWindow>

namespace Ui {
class certifierreceptioncolis;
}

class certifierreceptioncolis : public QMainWindow
{
    Q_OBJECT

public:
    explicit certifierreceptioncolis(QWidget *parent = nullptr);
    ~certifierreceptioncolis();

private:
    Ui::certifierreceptioncolis *ui;
};

#endif // CERTIFIERRECEPTIONCOLIS_H
