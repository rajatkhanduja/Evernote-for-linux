#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    evernoteClient = new EvernoteClient("CONSUMER_KEY", "CONSUMER_SECRET");
    connect(evernoteClient, SIGNAL(linkingSucceeded()), this, SLOT(updateNotebooks()));
    connect(evernoteClient, SIGNAL(linkingSucceeded()), this, SLOT(updateTags()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateNotebooks(){
}

void MainWindow::updateTags(){

}
