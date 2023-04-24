#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <iostream>
#include <map>
using namespace std;

class HTTPRequest{
    private:
        string method;
        string url;
        string version;
        map<string, string> headers;
        string body;

    public:
        HTTPRequest(string method, string url, string version, map<string, string> headers, string body) {
            this->method = method;
            this->url = url;
            this->version = version;
            this->headers = headers;
            this->body = body;
        }

        ~HTTPRequest() {

        }

        string getMethod() {
            return method;
        }

        string getUrl() {
            return url;
        }

        string getVersion() {
            return version;
        }

        map<string, string> getHeaders() {
            return headers;
        }

        string getBody() {
            return body;
        }
}