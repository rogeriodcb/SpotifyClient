#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QString>


class Spotify
{
public:
    Spotify();

private:
    // Spotify variables
    QString clientId;
    QString clientSecretId;
    QString clientToken;
    QString clientRefreshToken;
};

#endif // SPOTIFY_H
