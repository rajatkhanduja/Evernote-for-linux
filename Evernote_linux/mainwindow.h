#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <iostream>
#include "EvernoteAuthenticator.h"
#include <QWebView>
#include <QWebFrame>
#include "evernote/UserStore.h"
#include "thrift/protocol/TProtocol.h"
#include "evernote/UserStore.h"
#include "evernote/UserStore_types.h"
#include "evernote/ClientFactory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void onLinkChanged(){
        std::cerr << evernoteAuthenticator->linked() << std::endl;
    }

    void onLinkingFailed(){
        std::cerr << "Failed\n";
    }

    void onLinkingSucceeded(){
        std::cerr << "Done\n";
        if (evernoteAuthenticator->linked()) {
            try{
                UserStoreClient userStoreClient = ClientFactory::createClient();
                std::string noteStoreUrl;
                userStoreClient.getNoteStoreUrl(noteStoreUrl, evernoteAuthenticator->token().toStdString());
                std::cerr << noteStoreUrl;
            }
            catch(evernote::edam::EDAMUserException e){
                std::cerr << e.parameter << " " << e.errorCode << std::endl;
            }
        }
    }

    void onOpenBrowser(QUrl url){

        std::cerr << url.toString().toStdString() << std::endl;
        connect(view, SIGNAL(urlChanged(QUrl)), this, SLOT(urlChanged(QUrl)));
        connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loaded(bool)));
        view->load(url);
        view->show();
    }

    void urlChanged(QUrl url){
        std::cerr << url.toString().toStdString();
    }

    void loaded(bool loaded){
        if (!loaded) return;
    }

private:
    Ui::MainWindow *ui;
    EvernoteAuthenticator *evernoteAuthenticator;
    QWebView *view;
};

#endif // MAINWINDOW_H
