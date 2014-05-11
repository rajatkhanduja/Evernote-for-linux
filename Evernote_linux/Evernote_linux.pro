#-------------------------------------------------
#
# Project created by QtCreator 2014-05-06T22:47:42
#
#-------------------------------------------------

QT       += script core gui network webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Evernote_linux
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    evernote/UserStore_types.cpp \
    evernote/UserStore_constants.cpp \
    evernote/UserStore.cpp \
    evernote/Types_types.cpp \
    evernote/Types_constants.cpp \
    evernote/NoteStore_types.cpp \
    evernote/NoteStore_constants.cpp \
    evernote/NoteStore.cpp \
    evernote/Limits_types.cpp \
    evernote/Limits_constants.cpp \
    evernote/Errors_types.cpp \
    evernote/Errors_constants.cpp \
    o2/simplecrypt.cpp \
    o2/o2settingsstore.cpp \
    o2/o2requestor.cpp \
    o2/o2replyserver.cpp \
    o2/o2reply.cpp \
    o2/o2gft.cpp \
    o2/o2.cpp \
    o2/o1requestor.cpp \
    o2/o1.cpp \
    EvernoteAuthenticator.cpp \
    EvernoteClient.cpp \
    SidebarTreeModel.cpp

HEADERS  += mainwindow.h \
    evernote/UserStore_types.h \
    evernote/UserStore_constants.h \
    evernote/UserStore.h \
    evernote/Types_types.h \
    evernote/Types_constants.h \
    evernote/NoteStore_types.h \
    evernote/NoteStore_constants.h \
    evernote/NoteStore.h \
    evernote/Limits_types.h \
    evernote/Limits_constants.h \
    evernote/Errors_types.h \
    evernote/Errors_constants.h \
    o2/simplecrypt.h \
    o2/o2settingsstore.h \
    o2/o2requestor.h \
    o2/o2replyserver.h \
    o2/o2reply.h \
    o2/o2globals.h \
    o2/o2gft.h \
    o2/o2abstractstore.h \
    o2/o2.h \
    o2/o1requestor.h \
    o2/o1.h \
    EvernoteAuthenticator.h \
    EvernoteClient.h \
    SidebarTreeModel.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    o2/src.pri

unix:!macx: LIBS += -lthrift
