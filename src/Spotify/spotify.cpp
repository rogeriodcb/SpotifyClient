#include "spotify.h"

/********************************
* Spotify
*********************************
* Constructor of class
*********************************/
Spotify::Spotify(QWidget *parent)
{
    // create dynimic variables
    appSetup = new AppSetup();
    json = new JsonUtils();
    spotifyConnection = new SpotifyConnection(appSetup);
    QString s;

    // verify if config file information is present
    if(!json->readAppConfig(appSetup)){
        // no config file detected. So, get the clientId and clientSecreteId from user
        spotifyConnection->show();

    }
    else
    {
        qDebug() << "Configuration loaded successfully. Authorizing...";
        if ((s=spotifyConnection->getSpotifyConnectionCode(appSetup->getClientId(),
                                appSetup->getClientSecretId())).isEmpty())
            qDebug()<<"Authorization concluded.";
        else
        {
            qDebug() <<"Authorization failed. Error: "<<s;
            spotifyConnection->show();

        }



    }

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

/********************************
* spotifySearch
*********************************
* Executes search by using Spotify
* API
*********************************/
QJsonDocument Spotify::spotifySearch(QString queue, QString type)
{
    QJsonParseError jsonParseError{};
    QNetworkAccessManager  *networkManager = new QNetworkAccessManager();

    QNetworkRequest request(QString("https://api.spotify.com/v1/search?q=%1&type=%2&limit=5")
                            .arg(queue.replace(" ","%20"))
                            .arg(type)
                            );

    request.setRawHeader("Authorization",
            QString("Bearer %1")
            .arg(QString::fromStdString(appSetup->getClientToken().toStdString())).toUtf8());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto reply = networkManager->get(request);
    // Wait for request to finish
    while (!reply->isFinished())
        QCoreApplication::processEvents();

    // get the reply
    auto replyBody = reply->readAll();
    reply->deleteLater();

    // verify if file is empty
    if (replyBody.isNull()) {
        qDebug() << "Parse failed";
        return QJsonDocument::fromJson("");
    }

    auto json = QJsonDocument::fromJson(replyBody, &jsonParseError);
    // verify if file is empty
    if (json.isNull()) {
        qDebug() << "Parse failed";
        return QJsonDocument::fromJson("");
    }
    return json;
}

/********************************
* loadPlayList
*********************************
* Loads the offline playlist
*********************************/
QStringList Spotify::loadPlayList()
{
   return json->readPlayList();
}

/********************************
* loadPlayList
*********************************
* Loads the offline playlist
*********************************/
void Spotify::savePlayList(QStringList *sList)
{
   json->savePlayList(sList);
}




