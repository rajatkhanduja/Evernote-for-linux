#include "EvernoteClient.h"
#include <iostream>
#include <thrift/transport/THttpClient.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <boost/shared_ptr.hpp>

using apache::thrift::transport::THttpClient;
using apache::thrift::protocol::TProtocol;
using apache::thrift::protocol::TBinaryProtocol;

EvernoteClient::EvernoteClient(const QString& customerKey, const QString& customerSecret, bool sandbox, QObject *parent) : QObject(parent){
    this->sandbox = sandbox;
    evernoteAuthenticator = new EvernoteAuthenticator(getHost(), customerKey, customerSecret);
    std::cerr << evernoteAuthenticator->linked() << std::endl;
    view = new QWebView();
    connect(evernoteAuthenticator, SIGNAL(openBrowser(QUrl)), this, SLOT(onOpenBrowser(QUrl)));
    connect(evernoteAuthenticator, SIGNAL(closeBrowser()), this, SLOT(onCloseBrowser()));

    userStoreClient = NULL;
    noteStoreClient = NULL;

    evernoteAuthenticator->link();
}

QString EvernoteClient::getHost() const{
    if(sandbox){
        return "https://sandbox.evernote.com";
    }
    else{
        return "https://www.evernote.com";
    }
}

void EvernoteClient::onLinkingSucceeded(){
    std::cerr << "Done\n";

    initializeStoreClients();

    emit linkingSucceeded();
}

void EvernoteClient::onOpenBrowser(QUrl url){
    std::cerr << "Opening browser " << url.toString().toStdString() << std::endl;
    view->load(url);
    view->show();
}

void EvernoteClient::onCloseBrowser(){
    view->close();
}

void EvernoteClient::onLinkingFailed(){
    std::cerr << "Linking failed. Handle this error\n";
}

boost::shared_ptr<TProtocol> getProtoObject(std::string host, int port, std::string path){
    boost::shared_ptr<THttpClient> trans(new THttpClient(host, port, path));
    trans->open();
    boost::shared_ptr<TProtocol> proto(new TBinaryProtocol(trans));
    return proto;
}

void EvernoteClient::initializeStoreClients(){
    userStoreClient = new evernote::edam::UserStoreClient(getProtoObject(getHost().toStdString(), 80, "/edam/user"));

    std::string noteStoreUrlStr;
    userStoreClient->getNoteStoreUrl(noteStoreUrlStr, evernoteAuthenticator->token().toStdString());
    QUrl noteStoreUrl( (QString(noteStoreUrlStr.c_str())) );
    std::string noteStoreUrlHost = noteStoreUrl.host().toStdString();
    std::string noteStoreUrlPath = noteStoreUrl.path().toStdString();
    noteStoreClient = new evernote::edam::NoteStoreClient(getProtoObject(noteStoreUrlHost, 80, noteStoreUrlPath));
}

evernote::edam::NoteStoreClient* EvernoteClient::getNoteStoreClient(){
    return noteStoreClient;
}

evernote::edam::UserStoreClient* EvernoteClient::getUserStoreClient(){
    return userStoreClient;
}
