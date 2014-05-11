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
    for(unsigned int i = 0; i < notebooks.size(); i++){
        QStandardItem *tmpNotebookItem = new QStandardItem(QString(notebooks[i].name.c_str()));
        tmpNotebookItem->setEditable(false);
        notebooksRootItem->appendRow(tmpNotebookItem);
    }
}

void SidebarTreeModel::updateTags(const std::vector<evernote::edam::Tag> &tags){
    tagsRootItem->removeRows(0, tagsRootItem->rowCount());
    for(unsigned int i = 0; i < tags.size(); i++){
        QStandardItem *tmpTagItem = new QStandardItem(QString(tags[i].name.c_str()));
        tmpTagItem->setEditable(false);
        tagsRootItem->appendRow(tmpTagItem);
    }
}
