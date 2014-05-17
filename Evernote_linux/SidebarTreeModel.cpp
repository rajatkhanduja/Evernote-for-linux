/**
* Copyright (c) 2014 Rajat Khanduja
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

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
