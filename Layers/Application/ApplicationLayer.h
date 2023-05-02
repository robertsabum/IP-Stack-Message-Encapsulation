#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "../Transport/TransportLayer.h"
#include "HTTPMessage.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include <iostream>
using namespace std;

class ApplicationLayer
{

public:
  ApplicationLayer() {}

  HTTPMessage *send(HTTPMessage *message)
  {
    if (message->isRequest())
    {
      cout << "\nSent a Request to the Transport Layer" << endl;
    }
    else
    {
      cout << "\nSent a Response to the Transport Layer" << endl;
    }
    return message;
  }

  void recieve(HTTPMessage *message)
  {
    cout << "\nRecieved an HTTPMessage from the Transport Layer" << endl;
    message->print();
  }
};

#endif

// write the documentation for this class in markdown format
//
// ## HTTPRequest
//
// This class represents an HTTP Request. It has the following properties:
//
// - method: string
// - url: string
// - version: string
// - headers: map<string, string>
// - body: string
//
// It has the following methods:
// - HTTPRequest(string method, string url, string version, map<string, string> headers, string body)
// - HTTPRequest()
// - HTTPRequest(string filename)
// - void print()
// - bool isRequest()
// - string getMethod()
// - string getURL()
// - string getVersion()
// - map<string, string> getHeaders()
// - string getBody()
// - void setMethod(string method)
// - void setURL(string url)
// - void setVersion(string version)
// - void setHeaders(map<string, string> headers)
// - void setBody(string body)
//
// ### HTTPRequest(string method, string url, string version, map<string, string> headers, string body)
//
// This is the constructor for the HTTPRequest class. It takes in the following parameters:
//
// - method: string
// - url: string
// - version: string
// - headers: map<string, string>
// - body: string
//
// ### HTTPRequest()
//
// This is the default constructor for the HTTPRequest class. It sets the following properties:
//
// - method: "GET"
// - url: "/"
// - version: "HTTP/1.1"
// - headers: map<string, string>()
// - body: ""
//
// ### HTTPRequest(string filename)
//
// This is the constructor for the HTTPRequest class. It takes in the following parameters:
//
// - filename: string
//
// It opens the file with the given filename and parses the HTTP Request from the file.
//
// ### void print()
//
// This method prints the HTTP Request to the console.
//
// ### bool isRequest()
//
// This method returns true if the HTTP Message is a request and false if it is a response.
//
// ### string getMethod()
//
// This method returns the method of the HTTP Request.
//
// ### string getURL()
//
// This method returns the url of the HTTP Request.
//
// ### string getVersion()
//
// This method returns the version of the HTTP Request.
//
// ### map<string, string> getHeaders()
//
// This method returns the headers of the HTTP Request.
//
// ### string getBody()
//
// This method returns the body of the HTTP Request.
//
// ### void setMethod(string method)
//
// This method sets the method of the HTTP Request.
//
// ### void setURL(string url)
//
// This method sets the url of the HTTP Request.
//
// ### void setVersion(string version)
//
// This method sets the version of the HTTP Request.
//
// ### void setHeaders(map<string, string> headers)
//
// This method sets the headers of the HTTP Request.
//
// ### void setBody(string body)
//
// This method sets the body of the HTTP Request.
//
// ## HTTPResponse
//
// This class represents an HTTP Response. It has the following properties:
//
// - version: string
