#ifndef NOTEFILTERFACTORY_H
#define NOTEFILTERFACTORY_H

#include <evernote/NoteStore.h>

class NoteFilterBuilder
{
public:
    NoteFilterBuilder();

    NoteFilterBuilder& noteBookGuid(const evernote::edam::Guid& guid);
    NoteFilterBuilder& tagGuids(const std::vector<evernote::edam::Guid> &tagGuids);
    NoteFilterBuilder& order(const int32_t& order);
    NoteFilterBuilder& words(const std::string& words);
    NoteFilterBuilder& timeZone(const std::string& timeZone);
    NoteFilterBuilder& emphasized(const std::string& empasized);
    NoteFilterBuilder& inactive(const bool& inactive);
    NoteFilterBuilder& ascending(const bool& ascending);

    evernote::edam::NoteFilter& build();

private:
    evernote::edam::NoteFilter noteFilter;
};

#endif // NOTEFILTERFACTORY_H
