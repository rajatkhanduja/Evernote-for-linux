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

#ifndef EVERNOTE_AUTHENTICATOR_H
#define EVERNOTE_AUTHENTICATOR_H

#include "o2/o1.h"
#include <QString>

class EvernoteAuthenticator : public O1{

public:
    EvernoteAuthenticator(const QString& host, const QString& customerKey, const QString& customerSecret, QObject *parent = 0);

private:
    static QString TEMPORARY_CREDENTIAL_REQUEST_PATH;
    static QString RESOURCE_OWNER_AUTHORIZATION_PATH;
    static QString TOKEN_REQUEST_PATH;
};

#endif // EVERNOTE_AUTHENTICATOR_H
