#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include <iostream>
#include "HTTPRequest.h"
#include "HTTPResponse.h"
using namespace std;

class HTTPMessage {
    private:
        bool isRequest;
        union {
            HTTPRequest request;
            HTTPResponse response;
        } message;

    public:
        HTTPMessage(HTTPRequest request) {
            isRequest = true;
            message.request = request;
        }

        HTTPMessage(HTTPResponse response) {
            isRequest = false;
            message.response = response;
        }

        void print() {
            if (isRequest) {
                message.request.print();
            } else {
                message.response.print();
            }
        }

        bool isRequest() {
            return isRequest;
        }

        bool isResponse() {
            return !isRequest;
        }
};