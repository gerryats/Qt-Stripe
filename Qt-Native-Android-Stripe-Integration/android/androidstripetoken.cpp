//=============================================================================
// Copyright (c) 2014 Nicolas Froment

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//=============================================================================

#include "androidstripetoken.h"

#include <QtAndroidExtras/QAndroidJniObject>
#include "qdebug.h"
#include <QtAndroidExtras/QAndroidJniEnvironment>

AndroidStripeToken::AndroidStripeToken()
{

}

void AndroidStripeToken::FetchToken()
{
    //QPlatformNativeInterface *interface = QApplication::platformNativeInterface();
    //jobject activity = (jobject)interface->nativeResourceForIntegration("QtActivity");
    QAndroidJniObject jsCard = QAndroidJniObject::fromString("4242424242424242");
    QAndroidJniObject jsExpdate = QAndroidJniObject::fromString("12");
    QAndroidJniObject jsCvv = QAndroidJniObject::fromString("123");
    QAndroidJniObject obj = QAndroidJniObject::callStaticObjectMethod("com/stripe/QStripeToken",
                                       "GetToken",
                                       "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lcom/stripe/android/model/Token;",
                                       jsCard.object<jstring>(), jsExpdate.object<jstring>(), jsCvv.object<jstring>());
   // Q_ASSERT_X(obj.isValid(), "token", "Null QAndroidJniObject!");
    const jobject objectArray = obj.object<jobject>();
    //QAndroidJniObject myJavaString = QAndroidJniObject::fromString("Hello, Java");
   //QAndroidJniObject mySubstring = myJavaString.callObjectMethod("substring", "(II)Ljava/lang/String;", 7, 10);
           QAndroidJniObject str = obj.callObjectMethod<jstring>("getId");
            jstring jstdfdring = str.object<jstring>();

            QString qstdfring = str.toString();
            QString qstdfrmodeing;

            if (QAndroidJniObject::isClassAvailable("com/stripe/android/model/Token")) {

                QAndroidJniObject str1 = obj.callObjectMethod<jstring>("getTokenString");
                jstring jstdfdfgring = str1.object<jstring>();

                qstdfrmodeing = str1.toString();

                qDebug() << qstdfrmodeing;
            }
}
