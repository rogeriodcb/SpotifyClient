#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonObject>
#include <QStandardPaths>
#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QtDebug>
#include <QDir>
#include <QStringList>
#include <QJsonArray>

#include "../Settings/appsetup.h"

class JsonUtils
{
private:
    QString configFilePath;

public:

    JsonUtils();
    ~JsonUtils();

    bool readAppConfig(AppSetup *setup);
    void writeAppConfig(AppSetup *setup);
    QJsonDocument openJsonFile(QString filePath );
    void setConfigFilePath(QString filePath);
    QString getConfigFilePath();
    QStringList getTrackInfo(QJsonObject json);
    QStringList readPlayList();
    void savePlayList(QStringList *sList);


};

#endif // JSONUTILS_H
