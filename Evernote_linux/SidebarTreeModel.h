#ifndef SIDEBARTREEMODEL_H
#define SIDEBARTREEMODEL_H

#include <QStandardItemModel>
#include <evernote/NoteStore.h>
#include <vector>

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
    QStandardItem *notes;
};

#endif // SIDEBARTREEMODEL_H
