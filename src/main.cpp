#include "mainwindow.h"
#include "version.hpp"
#include <QApplication>
/*
TODO:
improve UI
finish the search method
implement the player
improve the playlist and its presentation
*/
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
