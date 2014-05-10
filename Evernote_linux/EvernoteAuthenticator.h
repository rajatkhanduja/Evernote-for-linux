#ifndef EVERNOTE_AUTHENTICATOR_H
#define EVERNOTE_AUTHENTICATOR_H

#include "o2/o1.h"
#include <QString>

class EvernoteAuthenticator : public O1{

public:
    EvernoteAuthenticator(const QString& host, const QString& customerKey, const QString& customerSecret, QObject *parent = 0);

private:
    static QString TEMPORARY_CREDENTIAL_REQUEST_PATH;
    static QString RESOURCE_OWNER_AUTHORIZATION_PATH;
    static QString TOKEN_REQUEST_PATH;
};

#endif // EVERNOTE_AUTHENTICATOR_H
