#include "EvernoteItem.h"
#include <iostream>

EvernoteItem::EvernoteItem(const QString &text, const evernote::edam::Guid guid, const ItemType::type& itemType) : QStandardItem(text)
{
    this->guid = guid;
    this->itemType = itemType;
    std::cerr << guid << std::endl;
}

evernote::edam::Guid EvernoteItem::getGuid(){
    return this->guid;
}

EvernoteItem::ItemType::type EvernoteItem::getItemType(){
    return this->itemType;
}
