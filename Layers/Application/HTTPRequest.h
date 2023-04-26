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

        HTTPRequest() {
            this->method = "GET";
            this->url = "/";
            this->version = "HTTP/1.1";
            this->headers = map<string, string>();
            this->body = "";
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

        void setMethod(string method) {
            this->method = method;
        }

        void setUrl(string url) {
            this->url = url;
        }

        void setVersion(string version) {
            this->version = version;
        }

        void setHeaders(map<string, string> headers) {
            this->headers = headers;
        }

        void setBody(string body) {
            this->body = body;
        }

        void print() {
            cout << "HTTP Request" << endl;
            cout << "Method: " << method << endl;
            cout << "URL: " << url << endl;
            cout << "Version: " << version << endl;
            cout << "Headers: " << endl;
            for (auto const& x : headers) {
                cout << x.first << ": " << x.second << endl;
            }
            cout << "Body: " << body << endl;
        }
}