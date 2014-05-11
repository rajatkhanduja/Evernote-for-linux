#ifndef STRINGGUIDITEM_H
#define STRINGGUIDITEM_H

#include <QStandardItem>
#include <evernote/Types_types.h>

class EvernoteItem : public QStandardItem
{

public:
    struct ItemType{
        enum type{
            Tag,
            Note,
            Notebook
        } ;
    };

    explicit EvernoteItem(const QString& data, const evernote::edam::Guid guid, const ItemType::type& itemType);
    evernote::edam::Guid getGuid();
    ItemType::type getItemType();

signals:
    
public slots:

private:
    evernote::edam::Guid guid;
    ItemType::type itemType;
};

#endif // STRINGGUIDITEM_H
