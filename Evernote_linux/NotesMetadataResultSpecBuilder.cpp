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
