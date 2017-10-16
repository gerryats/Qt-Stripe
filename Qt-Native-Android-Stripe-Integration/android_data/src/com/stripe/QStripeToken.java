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

package com.stripe;

import org.qtproject.qt5.android.QtNative;

import android.content.Context;
import android.os.AsyncTask;
import android.os.Build;

import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
//import android.support.annotation.Size;
//import android.support.annotation.VisibleForTesting;

import java.util.List;
import java.util.Map;
import java.util.concurrent.Executor;

//import com.stripe.android.exception.APIConnectionException;
//import com.stripe.android.exception.APIException;
//import com.stripe.android.exception.AuthenticationException;

//import com.stripe.android.exception.InvalidRequestException;
//import com.stripe.android.exception.StripeException;
//import com.stripe.android.model.BankAccount;
import com.stripe.android.model.Card;
///import com.stripe.android.model.Source;
import com.stripe.android.Stripe;
import com.stripe.android.TokenCallback;
import com.stripe.android.model.Token;
import com.stripe.android.exception.StripeException;
import java.lang.String;
import java.util.HashMap;
import android.util.Log;


public class QStripeToken
{
    private static Token chargetoken = null;
    protected QStripeToken()
    {

       //Log.d("lasconic", "QStripeToken()");
    }


    public static Token GetToken(String category, String action, String label)
    {
        Log.i("qwerty","Gettoken");
        // Token chargetoken = null;
        Card card = new Card("4242424242424242", 12, 2024, "123");
        if (QtNative.activity() != null)
        {

            Log.i("QtNative.activity","Gettoken");
            //return null;
            Stripe stripe = new Stripe(QtNative.activity(), "publishablekey");

            try {
                    Token token = stripe.createTokenSynchronous(card, "pk_test_ps0Z3x93g6ZTumYo5yF0nwuD");
                    chargetoken = token;
                    Log.i(token.toString(),"token");
                    Log.i(token.getId(),"token");
                } catch (StripeException stripeEx) {
                Log.i("error","token");

                }

            /*stripe.createToken(
                card,
                new TokenCallback() {
                    //Log.i("TokenCallback","Gettoken");
                    public void onSuccess(Token token) {
                        chargetoken = token;
                        Log.i(token.toString(),"token");
                        //return null;
                        // Send token to your own web service
                        //MyServer.chargeToken(token);
                    }
                    public void onError(Exception error) {
                        Log.i("onError","token");
                        Log.i(error.getMessage(),"token");
                        //Toast.makeText(getContext(),
                          //  error.getLocalizedMessage(),
                           // Toast.LENGTH_LONG).show();
                    }
                }
            );*/
        }
    return chargetoken;
    }

}
