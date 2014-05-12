#include "NoteFilterBuilder.h"

NoteFilterBuilder::NoteFilterBuilder(){
    noteFilter = new evernote::edam::NoteFilter();
}

NoteFilterBuilder* NoteFilterBuilder::noteBookGuid(const evernote::edam::Guid &guid){
    noteFilter->notebookGuid         = guid;
    noteFilter->__isset.notebookGuid = true;
    return this;
}

NoteFilterBuilder* NoteFilterBuilder::tagGuids(const std::vector<evernote::edam::Guid> &tagGuids){
    noteFilter->tagGuids         = tagGuids;
    noteFilter->__isset.tagGuids = true;
    return this;
}

NoteFilterBuilder *NoteFilterBuilder::order(const int32_t &order){
    noteFilter->order         = order;
    noteFilter->__isset.order = true;
    return this;
}

NoteFilterBuilder* NoteFilterBuilder::ascending(const bool &ascending){
    noteFilter->ascending         = ascending;
    noteFilter->__isset.ascending = true;
    return this;
}

NoteFilterBuilder* NoteFilterBuilder::emphasized(const std::string &empasized){
    noteFilter->emphasized         = empasized;
    noteFilter->__isset.emphasized = true;
    return this;
}

NoteFilterBuilder* NoteFilterBuilder::inactive(const bool &inactive){
    noteFilter->inactive         = inactive;
    noteFilter->__isset.inactive = true;
    return this;
}


NoteFilterBuilder* NoteFilterBuilder::timeZone(const std::string &timeZone){
    noteFilter->timeZone         = timeZone;
    noteFilter->__isset.timeZone = true;
    return this;
}

NoteFilterBuilder* NoteFilterBuilder::words(const std::string &words){
    noteFilter->words         = words;
    noteFilter->__isset.words = true;
    return this;
}

evernote::edam::NoteFilter* NoteFilterBuilder::build(){
    return noteFilter;
}
