#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <evernote/NoteStore.h>
#include <vector>
#include <SidebarTreeModel.h>

using evernote::edam::Notebook;
using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sidebarTreeModel = new SidebarTreeModel();
    ui->sidebar->setModel(sidebarTreeModel);

    connect(ui->sidebar, SIGNAL(clicked(QModelIndex)), this, SLOT(onSidebarElementClicked(QModelIndex)));

    connect(evernoteClient, SIGNAL(linkingSucceeded()), this, SLOT(updateNotebooks()));
    connect(evernoteClient, SIGNAL(linkingSucceeded()), this, SLOT(updateTags()));
    evernoteClient->link();

    connect(ui->actionSign_out, SIGNAL(triggered()), this, SLOT(signOut()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateNotebooks(){
    std::cerr << "Updating Notebooks\n";
    vector<Notebook> notebooks = evernoteClient->listNotebooks();
    Notebook defaultNotebook;
    std::cerr << "Number of notebooks : " << notebooks.size() << std::endl;
    for (vector<Notebook>::iterator itr = notebooks.begin(); itr != notebooks.end(); ++itr){
        if (itr->defaultNotebook){
            defaultNotebook = *itr;
            break;
        }
    }
    std::cerr << "Default notebook : " << defaultNotebook.name << std::endl;
    sidebarTreeModel->updateNotebooks(notebooks);
    ui->sidebar->setModel(sidebarTreeModel);
}

void MainWindow::updateTags(){
    vector<evernote::edam::Tag> tags = evernoteClient->listTags();
    sidebarTreeModel->updateTags(tags);
}

void MainWindow::signOut(){
    evernoteClient->unLink();
}

void MainWindow::onSidebarElementClicked(QModelIndex index){
    EvernoteItem *data = dynamic_cast<EvernoteItem*>((dynamic_cast<QStandardItemModel*>(ui->sidebar->model()))->itemFromIndex(index));

    if (data == NULL){
        // Test to handle dynamic_cast's failure
        // Happens when a normal QStandardItem is clicked.
        return;
    }

    std::vector<evernote::edam::NoteMetadata> notes;
    if (data->getItemType() == EvernoteItem::ItemType::Tag){
        notes = evernoteClient->listAllNotesWithTag(data->getGuid());
    }
    else{
        notes = evernoteClient->listAllNotesInNotebook(data->getGuid());
    }

    for(int i = 0; i < notes.size(); i++){
        std::cerr << notes[i].title << " " << notes[i].guid << " ; " << notes[i].created <<  std::endl;
    }
}
