#include "EvernoteAuthenticator.h"

QString EvernoteAuthenticator::TEMPORARY_CREDENTIAL_REQUEST_PATH = "/oauth";
QString EvernoteAuthenticator::RESOURCE_OWNER_AUTHORIZATION_PATH = "/OAuth.action";
QString EvernoteAuthenticator::TOKEN_REQUEST_PATH                = "/oauth";

QString EvernoteAuthenticator::CLIENT_ID     = "CLIENT_ID";
QString EvernoteAuthenticator::CLIENT_SECRET = "CLIENT_SECRET";

EvernoteAuthenticator::EvernoteAuthenticator(QObject *parent) : O1(parent){
    this->setRequestTokenUrl(QUrl(getEvernoteHost() + TOKEN_REQUEST_PATH));
    this->setAuthorizeUrl(QUrl(getEvernoteHost() + RESOURCE_OWNER_AUTHORIZATION_PATH));
    this->setAccessTokenUrl(QUrl(getEvernoteHost() + TOKEN_REQUEST_PATH));
    this->setClientId(CLIENT_ID);
    this->setClientSecret(CLIENT_SECRET);
}
