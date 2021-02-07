#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QString>
#include <QThread>
#include <QMessageBox>

#include "../Settings/appsetup.h"
#include "../Utils/jsonutils.h"
#include "../Dialogs/spotifyconnection.h"

class Spotify
{
public:
    Spotify();
    ~Spotify();

private:
    AppSetup *appSetup;
    JsonUtils *json;
    SpotifyConnection *spotifyConnection;
};

#endif // SPOTIFY_H
