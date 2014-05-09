#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <iostream>
#include "EvernoteAuthenticator.h"
#include <QWebView>
#include <QWebFrame>

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
