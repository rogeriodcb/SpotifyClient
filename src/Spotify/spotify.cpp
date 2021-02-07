#include "spotify.h"

/********************************
* Spotify
*********************************
* Constructor of class
*********************************/
Spotify::Spotify()
{
    // create dynimic variables
    appSetup = new AppSetup();
    json = new JsonUtils();
    spotifyConnection = new SpotifyConnection(appSetup);

    // verify if config file information is present
    if(!json->readAppConfig(appSetup)){
        // no config file detected. So, get the clientId and clientSecreteId from user
        spotifyConnection->show();

    }
    else
        qDebug() << "Configuration loaded successfully.";

}

/********************************
* ~Spotify
*********************************
* Destructor of class
*********************************/
Spotify::~Spotify(){
    delete appSetup;
    delete json;
    delete spotifyConnection;
}

