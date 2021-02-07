#ifndef APPSETUP_H
#define APPSETUP_H

#include <QString>

class AppSetup
{

private:
    QString clientId;
    QString clientSecretId;
    QString clientCode;
    QString clientToken;
    QString clientRefreshToken;
public:
    AppSetup();
    QString getClientId();
    QString getClientSecretId();
    QString getClientCode();
    QString getClientToken();
    QString getClientRefreshToken();

    void setClientId(QString clientId);
    void setClientSecretId(QString clientSecretId);
    void setClientCode(QString clientCode);
    void setClientToken(QString clientToken);
    void setClientRefreshToken(QString clientRefreshToken);

    void deleteClientId();
    void deleteClientSecretId();
    void deleteClientCode();
    void deleteClientToken();
    void deleteClientRefreshToken();
    void deleteAllClientSetup();



};

#endif // APPSETUP_H
