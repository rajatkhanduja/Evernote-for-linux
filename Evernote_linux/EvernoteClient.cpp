/**
* Copyright (c) 2014 Rajat Khanduja
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "EvernoteClient.h"
#include <iostream>
#include <thrift/transport/THttpClient.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <NoteFilterBuilder.h>
#include <NotesMetadataResultSpecBuilder.h>

using apache::thrift::transport::THttpClient;
using apache::thrift::protocol::TProtocol;
using apache::thrift::protocol::TBinaryProtocol;

void EvernoteClient::link()
{
    view = new QWebView();
    connect(evernoteAuthenticator, SIGNAL(openBrowser(QUrl)), this, SLOT(onOpenBrowser(QUrl)));
    connect(evernoteAuthenticator, SIGNAL(closeBrowser()), this, SLOT(onCloseBrowser()));
    connect(evernoteAuthenticator, SIGNAL(linkingSucceeded()), this, SLOT(onLinkingSucceeded()));
    evernoteAuthenticator->link();
}

void EvernoteClient::unLink(){
    evernoteAuthenticator->unlink();
}

EvernoteClient::EvernoteClient(const QString& customerKey, const QString& customerSecret, bool sandbox, QObject *parent) : QObject(parent){
    this->sandbox = sandbox;
    evernoteAuthenticator = new EvernoteAuthenticator(getHostWithProtocol(), customerKey, customerSecret);

    userStoreClient = NULL;
    noteStoreClient = NULL;
}

QString EvernoteClient::getHostWithProtocol() const{
    return "https://" + getHost();
}

QString EvernoteClient::getHost() const{
    if(sandbox){
        return "sandbox.evernote.com";
    }
    else{
        return "www.evernote.com";
    }
}

void EvernoteClient::onLinkingSucceeded(){
    if (!evernoteAuthenticator->linked()) return;

    delete view;

    std::cerr << "Done\n";
    std::cerr << (userStoreClient == NULL) << std::endl;

    initializeStoreClients();
    std::cerr << "Emitting!";

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
    userStoreClient->getNoteStoreUrl(noteStoreUrlStr, authenticationToken());
    QUrl noteStoreUrl( (QString(noteStoreUrlStr.c_str())) );
    std::string noteStoreUrlHost = noteStoreUrl.host().toStdString();
    std::string noteStoreUrlPath = noteStoreUrl.path().toStdString();
    noteStoreClient = new evernote::edam::NoteStoreClient(getProtoObject(noteStoreUrlHost, 80, noteStoreUrlPath));
}

std::vector<evernote::edam::Notebook> EvernoteClient::listNotebooks(){
    std::vector<evernote::edam::Notebook> notebooks;
    noteStoreClient->listNotebooks(notebooks, authenticationToken());
    return notebooks;
}

std::vector<evernote::edam::Tag> EvernoteClient::listTags(){
    std::vector<evernote::edam::Tag> tags;
    noteStoreClient->listTags(tags, authenticationToken());
    return tags;
}

evernote::edam::Notebook EvernoteClient::getDefaultNotebook(){
    evernote::edam::Notebook notebook;
    noteStoreClient->getDefaultNotebook(notebook, authenticationToken());
}

evernote::edam::NotesMetadataList EvernoteClient::listNotesByFilter(const evernote::edam::NoteFilter &filter, const int &offset, const int &max, const evernote::edam::NotesMetadataResultSpec &resultSpec){
    evernote::edam::NotesMetadataList notesMetadataList;
    noteStoreClient->findNotesMetadata(notesMetadataList, authenticationToken(), filter, offset, max, resultSpec);
    return notesMetadataList;
}

evernote::edam::Note EvernoteClient::getNote(const evernote::edam::Guid &guid) {
    evernote::edam::Note note;
    noteStoreClient->getNote(note, authenticationToken(), guid, true, true, true, true);
    return note;
}

evernote::edam::Notebook EvernoteClient::getNotebook(const evernote::edam::Guid& guid){
    evernote::edam::Notebook notebook;
    noteStoreClient->getNotebook(notebook, authenticationToken(), guid);
    return notebook;
}

std::string EvernoteClient::authenticationToken() const{
    return evernoteAuthenticator->token().toStdString();
}

std::vector<evernote::edam::NoteMetadata> EvernoteClient::listAllNotesInNotebook(const evernote::edam::Guid &guid) {
    evernote::edam::NoteFilter noteFilter = NoteFilterBuilder().noteBookGuid(guid)
                                                               .order(evernote::edam::NoteSortOrder::CREATED)
                                                               .ascending(false)
                                                               .build();

    evernote::edam::NotesMetadataResultSpec resultSpec = NotesMetadataResultSpecBuilder().title()
                                                                                         .created()
                                                                                         .notebookGuid()
                                                                                         .tagGuids()
                                                                                         .build();
    evernote::edam::NotesMetadataList notesMetadataList = listNotesByFilter(noteFilter, 0, 10000, resultSpec);

    return notesMetadataList.notes;
}

std::vector<evernote::edam::NoteMetadata> EvernoteClient::listAllNotesWithTag(const evernote::edam::Guid &guid) {

    std::vector<evernote::edam::Guid> tagGuids(1, guid);
    evernote::edam::NoteFilter noteFilter = NoteFilterBuilder().tagGuids(tagGuids)
                                                               .order(evernote::edam::NoteSortOrder::CREATED)
                                                               .ascending(false)
                                                               .build();

    evernote::edam::NotesMetadataResultSpec resultSpec = NotesMetadataResultSpecBuilder().title()
                                                                                         .created()
                                                                                         .notebookGuid()
                                                                                         .tagGuids()
                                                                                         .build();

    evernote::edam::NotesMetadataList notesMetadataList = listNotesByFilter(noteFilter, 0, 10000, resultSpec);

    return notesMetadataList.notes;
}
