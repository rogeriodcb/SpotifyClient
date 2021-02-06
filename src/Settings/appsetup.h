#ifndef APPSETUP_H
#define APPSETUP_H

#include <QString>

class AppSetup
{

private:
    QString clientId;
    QString clientSecreteId;
    QString clientToken;
    QString clientRefreshToken;
public:
    AppSetup();
    QString getClientId();
    QString getClientSecreteId();
    QString getClientToken();
    QString getClientRefreshToken();

    void setClientId(QString clientId);
    void setClientSecreteId(QString clientSecreteId);
    void setClientToken(QString clientToken);
    void setClientRefreshToken(QString clientRefreshToken);

    void deleteClientId();
    void deleteClientSecreteId();
    void deleteClientToken();
    void deleteClientRefreshToken();
    void deleteAllClientSetup();

};

#endif // APPSETUP_H
