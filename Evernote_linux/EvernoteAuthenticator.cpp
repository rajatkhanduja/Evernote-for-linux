#include "EvernoteAuthenticator.h"
#include <iostream>

QString EvernoteAuthenticator::TEMPORARY_CREDENTIAL_REQUEST_PATH = "/oauth";
QString EvernoteAuthenticator::RESOURCE_OWNER_AUTHORIZATION_PATH = "/OAuth.action";
QString EvernoteAuthenticator::TOKEN_REQUEST_PATH                = "/oauth";

EvernoteAuthenticator::EvernoteAuthenticator(const QString& host, const QString& customerKey, const QString& customerSecret, QObject *parent) : O1(parent){
    std::cerr << host.toStdString() << " " << customerKey.toStdString() << " " << customerSecret.toStdString() << "\n";
    this->setRequestTokenUrl(QUrl(host + TOKEN_REQUEST_PATH));
    this->setAuthorizeUrl(QUrl(host + RESOURCE_OWNER_AUTHORIZATION_PATH));
    this->setAccessTokenUrl(QUrl(host + TOKEN_REQUEST_PATH));
    this->setClientId(customerKey);
    this->setClientSecret(customerSecret);
}
