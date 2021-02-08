#include "jsonutils.h"

/********************************
* JsonUtils
*********************************
* Constructor of the class
*********************************/
JsonUtils::JsonUtils()
{
    configFilePath =QString("%1")
            .arg(QStandardPaths::writableLocation (QStandardPaths::AppConfigLocation));

    // verify if the path exists and creates if not
    QDir dir;

    // We create the directory if needed
    if (!dir.exists(configFilePath))
        dir.mkpath(configFilePath);

}

/********************************
* ~JsonUtils
*********************************
* Destructor of the class
*********************************/
JsonUtils::~JsonUtils()
{
    //TODO: destructor
}

/********************************
* setConfigFilePath
*********************************
* Used to set the private var
* configFilePath
*********************************/
void JsonUtils::setConfigFilePath(QString filePath)
{
    configFilePath = filePath;
}

/********************************
* getConfigFilePath
*********************************
* Used to get the private var
* configFilePath
*********************************/
QString JsonUtils::getConfigFilePath()
{
    return configFilePath;
}

/********************************
* openJsonFile
*********************************
* Open file specified and return
* QJsonDocument
*********************************/
QJsonDocument JsonUtils::openJsonFile(QString filePath )
{
    // read text data
    try{
        QFile inFile(filePath);
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = inFile.readAll();
        inFile.close();
        // convert
        QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);

        // verify if file is empty
        if (doc.isNull()) {
            qDebug() << "Parse failed";
            return QJsonDocument::fromJson("");
        }
        else
            return doc;
    }catch (...) {
        qDebug() << "Error while openning application configuration file.";
        qDebug() << "File not found or corrupted.";
        qDebug() << "Path: " << filePath;
        return QJsonDocument::fromJson("");
}



}

/********************************
* readAppConfig
*********************************
* Read app configuration file and
* set each variable of AppSetup
* class.
*********************************/
bool JsonUtils::readAppConfig(AppSetup *setup)
{
    QJsonObject json = (openJsonFile(QString("%1/%2")
        .arg(configFilePath)
        .arg("SpotifyClientConfig.json")))
        .object();

    if (json.isEmpty())
            return false;

    // load Spotify Client configuration
    if (json.contains("clientId") && json["clientId"].isString())
        setup->setClientId(json["clientId"].toString());

    if (json.contains("clientSecreteId") && json["clientSecreteId"].isString())
        setup->setClientSecretId(json["clientSecreteId"].toString());

    return true;
}

/********************************
* writeAppConfig
*********************************
* Write app configuration file data
* from each variable of AppSetup
* class.
*********************************/
void JsonUtils::writeAppConfig(AppSetup *setup)
{
    QJsonObject json;

    json["clientId"] = setup->getClientId();
    json["clientSecreteId"] = setup->getClientSecretId();

    QByteArray outJsonData = QJsonDocument(json).toJson();
    QString fo = QString("%1/%2").arg(configFilePath).arg("SpotifyClientConfig.json");
    QFile fout(fo);
    try{
        fout.open(QIODevice::WriteOnly);
        fout.write(outJsonData);
    }catch (...) {
        qDebug() << "Error writing application config file " << endl << fo << "." << endl;
    }

}

/********************************
* getTrackInfo
*********************************
* Get JsonObject information about
* the track.
*********************************/
QStringList JsonUtils::getTrackInfo(QJsonObject json)
{
    //TODO: loop in json spotify track info to get all necessary information
    if (json.isEmpty())
            return QStringList();

    // Search Tracks
    foreach(const QString& key, json.keys()) {
            QJsonValue value = json.value(key);
            qDebug() << "Key = " << key << ", Value = " << value.toString();
        }
    /*
    if (json.contains("name") && json["name"].isString())
        qDebug()<<(json["name"].toString());
    */
    return QStringList();

}


/********************************
* readPlayList
*********************************
* Read offline Playlist.
*********************************/
QStringList JsonUtils::readPlayList()
{
    // TODO: keep the tracks into a "track config" class to improve the data consume
    QStringList sList;
    QJsonObject json = (openJsonFile(QString("%1/%2")
        .arg(configFilePath)
        .arg("SpotifyClientPlaylist.json")))
        .object();

    if (json.isEmpty())
            return QStringList();

    // load Playlist
    QJsonValue value = json.value("tracks");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array)
        sList.append(QString("%1   %2   %3")
                     .arg(v.toObject().value("artistName").toString())
                     .arg(v.toObject().value("musicName").toString())
                     .arg(v.toObject().value("href").toString())
                          );

    return sList;
}

/********************************
* savePlayList
*********************************
* Save offline Playlist.
*********************************/
void JsonUtils::savePlayList(QStringList *sList)
{
 // TODO: get values from class attributes and save to the disk.

}
