#ifndef CLIENTFACTORY_H
#define CLIENTFACTORY_H

#include "evernote/UserStore.h";
#include "evernote/NoteStore.h";
#include "EvernoteAuthenticator.h"
#include "thrift/protocol/TProtocol.h"
#include "thrift/protocol/TBinaryProtocol.h";
#include "thrift/transport/THttpClient.h"
#include <QtDebug>

using ::apache::thrift::transport::THttpClient;
using ::apache::thrift::protocol::TProtocol;
using ::apache::thrift::protocol::TBinaryProtocol;
using evernote::edam::UserStoreClient;

class ClientFactory{
public:
    static UserStoreClient createClient(){

        boost::shared_ptr<THttpClient> trans(new THttpClient("sandbox.evernote.com", 80,"/edam/user"));
        trans->open();
        boost::shared_ptr<TProtocol> proto(new TBinaryProtocol(trans));
        return UserStoreClient(proto);
    }
};
#endif // CLIENTFACTORY_H
