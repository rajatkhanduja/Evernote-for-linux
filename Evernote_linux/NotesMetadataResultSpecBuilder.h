#ifndef NOTESMETADATARESULTSPECFACTORY_H
#define NOTESMETADATARESULTSPECFACTORY_H

#include <evernote/NoteStore.h>

class NotesMetadataResultSpecBuilder
{
public:
    NotesMetadataResultSpecBuilder();

    NotesMetadataResultSpecBuilder* title();
    NotesMetadataResultSpecBuilder* contentLength();
    NotesMetadataResultSpecBuilder* created();
    NotesMetadataResultSpecBuilder* updated();
    NotesMetadataResultSpecBuilder* deleted();
    NotesMetadataResultSpecBuilder* updateSequenceNum();
    NotesMetadataResultSpecBuilder* notebookGuid();
    NotesMetadataResultSpecBuilder* tagGuids();
    NotesMetadataResultSpecBuilder* attributes();
    NotesMetadataResultSpecBuilder* largestResourceMime();
    NotesMetadataResultSpecBuilder* largestResourceSize();

    evernote::edam::NotesMetadataResultSpec* build();

private:
    evernote::edam::NotesMetadataResultSpec *notesMetadataResultSpec;
};

#endif // NOTESMETADATARESULTSPECFACTORY_H
