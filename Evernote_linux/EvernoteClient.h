#ifndef EVERNOTECLIENT_H
#define EVERNOTECLIENT_H

/**
 * @brief Class to initialize connection with Evernote. This class
 * is responsible for OAuth and yielding UserStore and NoteStore.
 */

#include <EvernoteAuthenticator.h>
#include <QWebView>
#include <QObject>
#include <evernote/NoteStore.h>
#include <evernote/UserStore.h>

class EvernoteClient : public QObject
{
    Q_OBJECT

public:
    explicit EvernoteClient(const QString& customerKey, const QString& customerSecret, bool sandbox = true, QObject *parent = 0);
    ~EvernoteClient(){}

    void link();
    void unLink();

    // Methods to get notes and notebooks.
    std::vector<evernote::edam::Notebook> listNotebooks();
    std::vector<evernote::edam::Tag> listTags();
    evernote::edam::Notebook getNotebook(const evernote::edam::Guid& guid);
    std::vector<evernote::edam::NoteMetadata> listAllNotesInNotebook(const evernote::edam::Guid& guid);
    std::vector<evernote::edam::NoteMetadata> listAllNotesWithTag(const evernote::edam::Guid& guid);
    evernote::edam::Notebook getDefaultNotebook();
    evernote::edam::NotesMetadataList listNotesByFilter(const evernote::edam::NoteFilter& filter, const int& offset,
                                                        const int& max, const evernote::edam::NotesMetadataResultSpec& resultSpec);
    evernote::edam::Note getNote(const evernote::edam::Guid& guid);

Q_SIGNALS:
    void linkingSucceeded();

public Q_SLOTS:
    void onLinkingFailed();
    void onLinkingSucceeded();
    void onOpenBrowser(QUrl url);
    void onCloseBrowser();

protected:
    QString getHost() const;
    QString getHostWithProtocol() const;
    std::string authenticationToken() const;
    void initializeStoreClients();

private:
    bool sandbox;
    EvernoteAuthenticator *evernoteAuthenticator;
    QWebView *view;
    evernote::edam::NoteStoreClient *noteStoreClient;
    evernote::edam::UserStoreClient *userStoreClient;
};

#endif // EVERNOTECLIENT_H
