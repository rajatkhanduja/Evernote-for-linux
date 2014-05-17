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

#include "NoteFilterBuilder.h"

NoteFilterBuilder::NoteFilterBuilder(){
}

NoteFilterBuilder& NoteFilterBuilder::noteBookGuid(const evernote::edam::Guid &guid){
    noteFilter.notebookGuid         = guid;
    noteFilter.__isset.notebookGuid = true;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::tagGuids(const std::vector<evernote::edam::Guid> &tagGuids){
    noteFilter.tagGuids         = tagGuids;
    noteFilter.__isset.tagGuids = true;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::order(const int32_t &order){
    noteFilter.order         = order;
    noteFilter.__isset.order = true;
    std::cerr << "pointing to : " << this;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::ascending(const bool &ascending){
    noteFilter.ascending         = ascending;
    noteFilter.__isset.ascending = true;
    std::cerr << "pointing to : " << this;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::emphasized(const std::string &empasized){
    noteFilter.emphasized         = empasized;
    noteFilter.__isset.emphasized = true;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::inactive(const bool &inactive){
    noteFilter.inactive         = inactive;
    noteFilter.__isset.inactive = true;
    return *this;
}


NoteFilterBuilder& NoteFilterBuilder::timeZone(const std::string &timeZone){
    noteFilter.timeZone         = timeZone;
    noteFilter.__isset.timeZone = true;
    return *this;
}

NoteFilterBuilder& NoteFilterBuilder::words(const std::string &words){
    noteFilter.words         = words;
    noteFilter.__isset.words = true;
    return *this;
}

evernote::edam::NoteFilter& NoteFilterBuilder::build(){
    return noteFilter;
}
