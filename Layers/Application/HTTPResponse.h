#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class HTTPResponse{
    private:
        string version;
        string statusCode;
        string reasonPhrase;
        map<string, string> headers;
        string body;

    public:
        HTTPResponse(string version, string statusCode, string reasonPhrase, map<string, string> headers, string body) {
            this->version = version;
            this->statusCode = statusCode;
            this->reasonPhrase = reasonPhrase;
            this->headers = headers;
            this->body = body;
        }

        HTTPResponse() {
            this->version = "HTTP/1.1";
            this->statusCode = "200 OK";
            this->reasonPhrase = "";
            this->headers = map<string, string>();
            this->body = "";
        }

        ~HTTPResponse() {

        }

        string getVersion() {
            return version;
        }

        string getStatusCode() {
            return statusCode;
        }

        string getReasonPhrase() {
            return reasonPhrase;
        }

        map<string, string> getHeaders() {
            return headers;
        }

        string getBody() {
            return body;
        }

        void print() {
            cout << "HTTP Response" << endl;
            cout << "Version: " << version << endl;
            cout << "Status Code: " << statusCode << endl;
            cout << "Reason Phrase: " << reasonPhrase << endl;
            cout << "Headers: " << endl;
            for (auto const& x : headers) {
                cout << x.first << ": " << x.second << endl;
            }
            cout << "Body: " << body << endl;
        }
};

#endif