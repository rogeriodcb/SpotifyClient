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
* getClientSecretId
*********************************
* Get the private variable
* clientSecretId
*********************************/
QString AppSetup::getClientSecretId(){
    return clientSecretId;
}

/********************************
* getClientCode
*********************************
* Get the private variable
* clientCode
*********************************/
QString AppSetup::getClientCode(){
    return clientCode;
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
* setClientSecretId
*********************************
* Set the private variable
* clientSecretId
*********************************/
void AppSetup::setClientSecretId(QString clientSecretId){
    this->clientSecretId = clientSecretId;
}

/********************************
* setClientCode
*********************************
* Set the private variable
* clientCode
*********************************/
void AppSetup::setClientCode(QString clientCode){
    this->clientCode = clientCode;
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
* deleteClientSecretId
*********************************
* Delete the value from private
* variable clientSecretId
*********************************/
void AppSetup::deleteClientSecretId(){
    clientSecretId = "";
}

/********************************
* deleteClientCode
*********************************
* Delete the value from private
* variable clientCode
*********************************/
void AppSetup::deleteClientCode(){
    clientCode = "";
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
    clientSecretId="";
    clientCode="";
    clientToken = "";
    clientRefreshToken="";
}
