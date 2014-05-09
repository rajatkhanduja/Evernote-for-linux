#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evernote/NoteStore.h"
#include <QWebView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    evernoteAuthenticator = new EvernoteAuthenticator();

    this->view = new QWebView();

    // Create all the required connections to handle authentication.
    connect(evernoteAuthenticator, SIGNAL(linkedChanged()), this, SLOT(onLinkChanged()));
    connect(evernoteAuthenticator, SIGNAL(linkingFailed()), this, SLOT(onLinkingFailed()));
    connect(evernoteAuthenticator, SIGNAL(linkingSucceeded()), this, SLOT(onLinkingSucceeded()));
    connect(evernoteAuthenticator, SIGNAL(openBrowser(QUrl)), this, SLOT(onOpenBrowser(QUrl)));
    connect(evernoteAuthenticator, SIGNAL(closeBrowser()), view, SLOT(close()));

    evernoteAuthenticator->link();

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

