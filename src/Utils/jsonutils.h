#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonObject>
#include <QStandardPaths>
#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QtDebug>
#include <QDir>

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


};

#endif // JSONUTILS_H
