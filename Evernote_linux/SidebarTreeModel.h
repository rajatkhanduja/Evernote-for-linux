#ifndef SIDEBARTREEMODEL_H
#define SIDEBARTREEMODEL_H

#include <QStandardItemModel>
#include <evernote/NoteStore.h>
#include <vector>
#include <EvernoteItem.h>

class SidebarTreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    SidebarTreeModel();    
    void updateNotebooks(const std::vector<evernote::edam::Notebook>& notebooks);
    void updateTags(const std::vector<evernote::edam::Tag>& tags);

private:
    QStandardItem *notebooksRootItem;
    QStandardItem *tagsRootItem;
    QStandardItem *notesItem;
    std::vector<evernote::edam::Tag> tags;
    std::vector<evernote::edam::Notebook> notebooks;
};

#endif // SIDEBARTREEMODEL_H
