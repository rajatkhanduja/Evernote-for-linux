#include "SidebarTreeModel.h"

SidebarTreeModel::SidebarTreeModel() {
    QStandardItem *parentItem = this->invisibleRootItem();
    parentItem->setText("Shortcuts");

    // Notebook based shortcut
    notebooksRootItem = new QStandardItem(QString("Notebooks"));
    notebooksRootItem->setEditable(false);
    parentItem->appendRow(notebooksRootItem);

    // Tags based shortcut
    tagsRootItem = new QStandardItem(QString("Tags"));
    tagsRootItem->setEditable(false);
    parentItem->appendRow(tagsRootItem);
}

void SidebarTreeModel::updateNotebooks(const std::vector<evernote::edam::Notebook> &notebooks){
    notebooksRootItem->removeRows(0, notebooksRootItem->rowCount());
    this->notebooks = notebooks;
    for(unsigned int i = 0; i < notebooks.size(); i++){
        QStandardItem *tmpNotebookItem = new EvernoteItem(QString(notebooks[i].name.c_str()), notebooks[i].guid, EvernoteItem::ItemType::Notebook);
        tmpNotebookItem->setEditable(false);
        notebooksRootItem->appendRow(tmpNotebookItem);
    }
}

void SidebarTreeModel::updateTags(const std::vector<evernote::edam::Tag> &tags){
    tagsRootItem->removeRows(0, tagsRootItem->rowCount());
    this->tags = tags;
    for(unsigned int i = 0; i < tags.size(); i++){
        QStandardItem *tmpTagItem = new EvernoteItem(QString(tags[i].name.c_str()), tags[i].guid, EvernoteItem::ItemType::Tag);
        tmpTagItem->setEditable(false);
        tagsRootItem->appendRow(tmpTagItem);
    }
}
