#include "mainwindow.h"
#include "version.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Set application details
    QCoreApplication::setOrganizationName("rcbrito");
    QCoreApplication::setApplicationName("SpotifyClient");
    QCoreApplication::setApplicationVersion(APP_VERSION);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
