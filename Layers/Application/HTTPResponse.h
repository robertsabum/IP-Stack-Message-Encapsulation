#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class HTTPResponse
{
private:
    string version;
    string statusCode;
    string reasonPhrase;
    map<string, string> headers;
    string body;

public:
    HTTPResponse(string version, string statusCode, string reasonPhrase, map<string, string> headers, string body)
    {
        this->version = version;
        this->statusCode = statusCode;
        this->reasonPhrase = reasonPhrase;
        this->headers = headers;
        this->body = body;
    }

    HTTPResponse()
    {
        this->version = "HTTP/1.1";
        this->statusCode = "200";
        this->reasonPhrase = "OK";
        this->headers = map<string, string>();
        this->body = "<html><body><h1>It works!</h1></body></html>";
    }

    ~HTTPResponse()
    {
    }

    string getVersion()
    {
        return this->version;
    }

    string getStatusCode()
    {
        return this->statusCode;
    }

    string getReasonPhrase()
    {
        return this->reasonPhrase;
    }

    map<string, string> getHeaders()
    {
        return this->headers;
    }

    string getBody()
    {
        return this->body;
    }

    void setVersion(string version)
    {
        this->version = version;
    }

    void setStatusCode(string statusCode)
    {
        this->statusCode = statusCode;
    }

    void setReasonPhrase(string reasonPhrase)
    {
        this->reasonPhrase = reasonPhrase;
    }

    void setHeaders(map<string, string> headers)
    {
        this->headers = headers;
    }

    void setBody(string body)
    {
        this->body = body;
    }

    void print()
    {
        cout << "HTTP Response" << endl;
        cout << "Version: " << this->version << endl;
        cout << "Status Code: " << this->statusCode << endl;
        cout << "Reason Phrase: " << this->reasonPhrase << endl;
        cout << "Headers: " << endl;
        for (auto const &x : this->headers)
        {
            cout << x.first << ": " << x.second << endl;
        }
        cout << "Body: " << this->body << endl;
        cout << endl;
    }
};

#endif