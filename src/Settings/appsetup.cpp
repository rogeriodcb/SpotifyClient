#include "appsetup.h"

/********************************
* AppSetup
*********************************
* Constructor of class
*********************************/
AppSetup::AppSetup()
{
    deleteAllClientSetup();
}

/********************************
* getClientId
*********************************
* Get the private variable
* clientId
*********************************/
QString AppSetup::getClientId()
{
    return clientId;
}

/********************************
* getClientSecreteId
*********************************
* Get the private variable
* clientSecreteId
*********************************/
QString AppSetup::getClientSecreteId(){
    return clientSecreteId;
}

/********************************
* getClientToken
*********************************
* Get the private variable
* clientToken
*********************************/
QString AppSetup::getClientToken(){
    return clientToken;
}

/********************************
* getClientRefreshToken
*********************************
* Get the private variable
* clientRefreshToken
*********************************/
QString AppSetup::getClientRefreshToken(){
    return clientRefreshToken;
}

/********************************
* setClientId
*********************************
* Set the private variable
* clientId
*********************************/
void AppSetup::setClientId(QString clientId){
    this->clientId = clientId;
}

/********************************
* setClientSecreteId
*********************************
* Set the private variable
* clientSecreteId
*********************************/
void AppSetup::setClientSecreteId(QString clientSecreteId){
    this->clientSecreteId = clientSecreteId;
}

/********************************
* setClientToken
*********************************
* Set the private variable
* clientToken
*********************************/
void AppSetup::setClientToken(QString clientToken){
    this->clientToken = clientToken;
}

/********************************
* setClientRefreshToken
*********************************
* Set the private variable
* clientRefreshToken
*********************************/
void AppSetup::setClientRefreshToken(QString clientRefreshToken){
    this->clientRefreshToken = clientRefreshToken;
}

/********************************
* deleteClientId
*********************************
* Delete the value from private
* variable clientId
*********************************/
void AppSetup::deleteClientId(){
    clientId = "";
}

/********************************
* deleteClientSecreteId
*********************************
* Delete the value from private
* variable clientSecreteId
*********************************/
void AppSetup::deleteClientSecreteId(){
    clientSecreteId = "";
}

/********************************
* deleteClientToken
*********************************
* Delete the value from private
* variable clientToken
*********************************/
void AppSetup::deleteClientToken(){
    clientToken = "";
}

/********************************
* deleteClientRefreshToken
*********************************
* Delete the value from private
* variable clientRefreshToken
*********************************/
void AppSetup::deleteClientRefreshToken(){
    clientRefreshToken = "";
}

/********************************
* deleteAllClientSetup
*********************************
* Delete all private variables
* from private AppSetup
*********************************/
void AppSetup::deleteAllClientSetup(){
    clientId = "";
    clientSecreteId="";
    clientToken = "";
    clientRefreshToken="";
}
