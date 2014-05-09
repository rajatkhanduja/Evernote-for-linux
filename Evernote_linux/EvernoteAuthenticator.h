#ifndef EVERNOTE_AUTHENTICATOR_H
#define EVERNOTE_AUTHENTICATOR_H

#include "o2/o1.h"
#include <QString>

class EvernoteAuthenticator : public O1{

public:
    EvernoteAuthenticator(QObject *parent = 0);

private:
    static QString TEMPORARY_CREDENTIAL_REQUEST_PATH;
    static QString RESOURCE_OWNER_AUTHORIZATION_PATH;
    static QString TOKEN_REQUEST_PATH;

    static QString CLIENT_ID;
    static QString CLIENT_SECRET;

    static QString getEvernoteHost(){
        return QString("https://sandbox.evernote.com");     // Modify this to use a global flag to get environment information
    }
};

#endif // EVERNOTE_AUTHENTICATOR_H
