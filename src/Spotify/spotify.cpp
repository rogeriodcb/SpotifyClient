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

    // verify if config file information is present
    if(!json->readAppConfig(appSetup)){
        // no config file detected. So, get the clientId and clientSecreteId from user
        spotifyConnection = new SpotifyConnection(appSetup);
        spotifyConnection->show();
        spotifyConnection->setWindowState(Qt::WindowState::WindowActive);
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

    if (spotifyConnection!=NULL)
        delete spotifyConnection;
}
