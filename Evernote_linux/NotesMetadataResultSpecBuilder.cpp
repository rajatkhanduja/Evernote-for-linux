#include "NotesMetadataResultSpecBuilder.h"

NotesMetadataResultSpecBuilder::NotesMetadataResultSpecBuilder(){
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::title(){
    notesMetadataResultSpec.includeTitle         = true;
    notesMetadataResultSpec.__isset.includeTitle = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::contentLength(){
    notesMetadataResultSpec.includeContentLength         = true;
    notesMetadataResultSpec.__isset.includeContentLength = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::created() {
    notesMetadataResultSpec.includeCreated         = true;
    notesMetadataResultSpec.__isset.includeCreated = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::updated() {
    notesMetadataResultSpec.includeUpdated         = true;
    notesMetadataResultSpec.__isset.includeUpdated = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::deleted() {
    notesMetadataResultSpec.includeDeleted         = true;
    notesMetadataResultSpec.__isset.includeDeleted = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::updateSequenceNum() {
    notesMetadataResultSpec.includeUpdateSequenceNum         = true;
    notesMetadataResultSpec.__isset.includeUpdateSequenceNum = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::notebookGuid() {
    notesMetadataResultSpec.includeNotebookGuid         = true;
    notesMetadataResultSpec.__isset.includeNotebookGuid = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::tagGuids() {
    notesMetadataResultSpec.includeTagGuids         = true;
    notesMetadataResultSpec.__isset.includeTagGuids = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::attributes() {
    notesMetadataResultSpec.includeAttributes        = true;
    notesMetadataResultSpec.__isset.includeAttributes = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::largestResourceMime() {
    notesMetadataResultSpec.includeLargestResourceMime         = true;
    notesMetadataResultSpec.__isset.includeLargestResourceMime = true;
    return *this;
}

NotesMetadataResultSpecBuilder& NotesMetadataResultSpecBuilder::largestResourceSize() {
    notesMetadataResultSpec.includeLargestResourceSize         = true;
    notesMetadataResultSpec.__isset.includeLargestResourceSize = true;
    return *this;
}

evernote::edam::NotesMetadataResultSpec &NotesMetadataResultSpecBuilder::build() {
    return this->notesMetadataResultSpec;
}
