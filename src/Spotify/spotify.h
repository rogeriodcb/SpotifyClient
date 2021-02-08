#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QString>
#include <QThread>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QAbstractSocket>


#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>



#include "../Settings/appsetup.h"
#include "../Utils/jsonutils.h"
#include "../Dialogs/spotifyconnection.h"

class Spotify
{
public:
    Spotify(QWidget *parent);
    ~Spotify();

    QJsonDocument spotifySearch(QString queue, QString type);
    QStringList loadPlayList();
    void savePlayList(QStringList *sList);

private:
    AppSetup *appSetup;
    JsonUtils *json;
    SpotifyConnection *spotifyConnection;
    QWidget *parent;
};

#endif // SPOTIFY_H
