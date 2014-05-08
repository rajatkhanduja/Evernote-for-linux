#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evernote/NoteStore.h"
#include <QWebView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    QWebView *view = new QWebView(parent);
    view->load(QUrl("http://www.evernote.com"));
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
