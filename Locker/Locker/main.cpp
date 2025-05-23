#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Définir le nom de l'application
    QApplication::setApplicationName("Locker");

    // Charger la feuille de style
    QFile styleFile(":/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        app.setStyleSheet(styleSheet);
        styleFile.close();
    }

    MainWindow w;
    w.setWindowTitle("Locker");  // Titre de la fenêtre principale

    // Forcer le titre après toute initialisation potentielle
    w.show();
    w.setWindowTitle("Locker");

    return app.exec();
}
