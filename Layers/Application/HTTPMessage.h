#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include <iostream>
#include "HTTPRequest.h"
#include "HTTPResponse.h"
using namespace std;

class HTTPMessage {
    private:
        bool _isRequest;
        HTTPRequest* request;
        HTTPResponse* response;

    public:
        HTTPMessage(HTTPRequest* _request) {
            this->_isRequest = true;
            this->request = _request;
        }

        HTTPMessage(HTTPResponse* _response) {
            this->_isRequest = false;
            this->response = _response;
        }

        void print() {
            if (this->_isRequest) {
                this->request->print();
            } else {
                this->response->print();
            }
        }

        bool isRequest() {
            return this->_isRequest;
        }
};

#endif