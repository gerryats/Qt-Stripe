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

#import "stripetoken.h"
#import "include/Qt-lib/STPAPIClient.h"
#import "include/Qt-lib/STPCard.h"
#import "include/Qt-lib/Stripe.h"
#import "include/Qt-lib/STPToken.h"

StripeToken::StripeToken() {

}

QString StripeToken::GetToken() {

    // TODO: Replace with your own test publishable key
    // TODO: DEBUG ONLY! Remove / conditionalize before launch

    // TODO: Replace with your own test publishable key
    // TODO: DEBUG ONLY! Remove / conditionalize before launch
    [Stripe setDefaultPublishableKey:@"publishablekey"];

    //STPCardParams* cardParams =  ;//[self.paymentTextField cardParams];

    STPCardParams *cardParams = [[STPCardParams alloc] init];
    cardParams.number = @"4242424242424242";
    cardParams.expMonth = 10;
    cardParams.expYear = 2018;
    cardParams.cvc = @"123";
    // To use dispatch_semaphore_t. i need to run it from other than main thread
    // dispatch_semaphore_t sem = dispatch_semaphore_create(0);
    [[STPAPIClient sharedClient] createTokenWithCard:cardParams completion:^(STPToken *token, NSError *error) {
        NSString *nsstr;
        if (token != nil) {
            nsstr = token.tokenId;
            NSLog(@"%@",nsstr);
            NSRange range;
            range.location = 0;
            range.length = [nsstr length];
            QString result(range.length, QChar(0));
            unichar *chars = new unichar[range.length];
            [nsstr getCharacters:chars range:range];
            result = QString::fromUtf16(chars, range.length);
            delete[] chars;
          //  dispatch_semaphore_signal(sem);
            return;
        }
    }];
   // dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
}

