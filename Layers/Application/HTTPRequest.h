#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string str, char delimiter)
{
  vector<string> internal;
  stringstream ss(str);
  string tok;

  while (getline(ss, tok, delimiter))
  {
    internal.push_back(tok);
  }

  return internal;
}

class HTTPRequest
{
private:
  string method;
  string url;
  string version;
  map<string, string> headers;
  string body;

public:
  HTTPRequest(string method, string url, string version,
              map<string, string> headers, string body)
  {
    this->method = method;
    this->url = url;
    this->version = version;
    this->headers = headers;
    this->body = body;
  }

  HTTPRequest()
  {
    this->method = "GET";
    this->url = "/";
    this->version = "HTTP/1.1";
    this->headers = map<string, string>();
    this->body = "";
  }

  // Create a HTTPRequest from a file
  HTTPRequest(string filename)
  {
    // Open the file
    ifstream file(filename);
    string line;
    // Get the method, url, and version
    getline(file, line);
    cout << line << endl;
    vector<string> requestLine = split(line, ' ');
    this->method = requestLine[0];
    this->url = requestLine[1];
    this->version = requestLine[2];
    // Get the headers
    while (getline(file, line))
    {
      if (line == "\r")
      {
        break;
      }
      vector<string> header = split(line, ':');
      this->headers[header[0]] = header[1];
    }
    // Get the body
    getline(file, line);
    this->body = line;
  }

  string getMethod() { return this->method; }

  string getUrl() { return this->url; }

  string getVersion() { return this->version; }

  map<string, string> getHeaders() { return this->headers; }

  string getBody() { return this->body; }

  void setMethod(string method) { this->method = method; }

  void setUrl(string url) { this->url = url; }

  void setVersion(string version) { this->version = version; }

  void setHeaders(map<string, string> headers) { this->headers = headers; }

  void setBody(string body) { this->body = body; }

  void print()
  {
    cout << "HTTP Request" << endl;
    cout << "Method: " << this->method << endl;
    cout << "URL: " << this->url << endl;
    cout << "Version: " << this->version << endl;
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