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
    evernote::edam::NoteStoreClient* getNoteStoreClient();
    evernote::edam::UserStoreClient* getUserStoreClient();
    ~EvernoteClient(){}

Q_SIGNALS:
    void linkingSucceeded();

public Q_SLOTS:
    void onLinkingFailed();
    void onLinkingSucceeded();
    void onOpenBrowser(QUrl url);
    void onCloseBrowser();

protected:
    QString getHost() const;
    void initializeStoreClients();

private:
    bool sandbox;
    EvernoteAuthenticator *evernoteAuthenticator;
    QWebView *view;
    evernote::edam::NoteStoreClient *noteStoreClient;
    evernote::edam::UserStoreClient *userStoreClient;
};

#endif // EVERNOTECLIENT_H
