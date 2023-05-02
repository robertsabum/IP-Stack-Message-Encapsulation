code
```cpp
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

```
# Application Layer
This folder contains the code for the Application Layer of the TCP Stack. It contains the following classes:
- [HTTPRequest](#HTTPRequest) 
- [HTTPResponse](#HTTPResponse)
- [HTTPMessage](#HTTPMessage)
- [ApplicationLayer](#ApplicationLayer)

## HTTPRequest

This class represents an HTTP Request. It has the following properties:

- `method` : string
- `url` : string
- `version` : string
- `headers` : map<string, string>
- `body` : string


It has the following methods:
- [HTTPRequest(string method, string url, string version, map<string, string> headers, string body)](#HTTPRequeststring-method-string-url-string-version-mapstring-string-headers-string-body)
- [HTTPRequest()](#HTTPRequest)
- [HTTPRequest(string filename)](#HTTPRequeststring-filename)
- [print()](#void-print)
- [isRequest()](#bool-isRequest)
- [getMethod()](#string-getMethod)
- [getURL()](#string-getURL)
- [getVersion()](#string-getVersion)
- [getHeaders()](#mapstring-string-getHeaders)
- [getBody()](#string-getBody)
- [setMethod(string method)](#void-setMethodstring-method)
- [setURL(string url)](#void-setURLstring-url)
- [setVersion(string version)](#void-setVersionstring-version)
- [setHeaders(map<string, string> headers)](#void-setHeadersmapstring-string-headers)
- [setBody(string body)](#void-setBodystring-body)

## Constructors

### HTTPRequest(string method, string url, string version, map<string, string> headers, string body)
This is a constructor for the HTTPRequest class.

Example usage:
```cpp
    map<string, string> headers;
    headers["Host"] = "localhost:8080";
    headers["User-Agent"] = "curl/7.64.1";
    headers["Accept"] = "*/*";
    headers["Content-Length"] = "0";
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    HTTPRequest* request = new HTTPRequest("POST", "/login", "HTTP/1.1",    headers, "");
```


### HTTPRequest()

This is the default constructor for the HTTPRequest class. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest();
```

### HTTPRequest(string filename)

This is the constructor for the HTTPRequest class. It takes in the following parameters:

- filename: string

It opens the file with the given filename and parses the HTTP Request from the file. 
 
Example file:
```
    POST /login HTTP/1.1
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    username=hello&password=world
 ```
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
```

 ### void print()

 This method prints the HTTP Request to the console. 
 
 Sample output:
 ```
    HTTP Request
    Method: POST
    URL: /login
    Version: HTTP/1.1
    Headers:
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
 ```

### bool isRequest()

This method returns true if the HTTP Message is a request and false if it is a response. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    if (request->isRequest()) {
        cout << "This is a request" << endl;
    } else {
        cout << "This is a response" << endl;
    }
 ```

### string getMethod()

This method returns the method of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Method: " << request->getMethod() << endl;
```

Output:
```
    Method: POST
```
### string getURL()

This method returns the url of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "URL: " << request->getURL() << endl;
```

Output:
```
    URL: /login
```

### string getVersion()

This method returns the version of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Version: " << request->getVersion() << endl;
```

Output:
```
    Version: HTTP/1.1
```

### map<string, string> getHeaders()

This method returns the headers of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    map<string, string> headers = request->getHeaders();
    for (auto const &x : headers) {
        cout << x.first << ": " << x.second << endl;
    }
```

Output:
```
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
```

### string getBody()

This method returns the body of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Body: " << request->getBody() << endl;
```

Output:
```
    Body: username=hello&password=world
```

### void setMethod(string method)

This method sets the method of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Method: " << request->getMethod() << endl;
    request->setMethod("GET");
    cout << "Method: " << request->getMethod() << endl;
```

Output:
```
    Method: POST
    Method: GET
```

### void setURL(string url)

This method sets the url of the HTTP Request. 
 
Example usage:
```cpp
   HTTPRequest* request = new HTTPRequest("request.txt");
   cout << "URL: " << request->getURL() << endl;
   request->setURL("/logout");
   cout << "URL: " << request->getURL() << endl;
```

Output:
```
    URL: /login
    URL: /logout
```

### void setVersion(string version)

This method sets the version of the HTTP Request. 
 
Example usage:
```cpp
   HTTPRequest* request = new HTTPRequest("request.txt");
   cout << "Version: " << request->getVersion() << endl;
   request->setVersion("HTTP/1.0");
   cout << "Version: " << request->getVersion() << endl;
```

Output:
```
    Version: HTTP/1.1
    Version: HTTP/1.0
```

### void setHeaders(map<string, string> headers)

This method sets the headers of the HTTP Request. 
 
Example usage:
```cpp
   HTTPRequest* request = new HTTPRequest("request.txt");
   request->print();
   map<string, string> headers;
   headers["Host"] = "localhost:8080";
   headers["User-Agent"] = "curl/7.64.1";
   headers["Accept"] = "*/*";
   headers["Content-Length"] = "0";
   headers["Content-Type"] = "application/x-www-form-urlencoded";
   request->setHeaders(headers);
   map<string, string> headers = request->getHeaders();
   request->print();
```

Output:
```
    HTTP Request
    Method: POST
    URL: /login
    Version: HTTP/1.1
    Headers:
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
    
    HTTP Request
    Method: POST
    URL: /login
    Version: HTTP/1.1
    Headers:
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
```

### void setBody(string body)

This method sets the body of the HTTP Request. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Body: " << request->getBody() << endl;
    request->setBody("username=world&password=hello");
    cout << "Body: " << request->getBody() << endl;
```

Output:
```
    Body: username=hello&password=world
    Body: username=world&password=hello
```


### HTTPResponse()

This is the default constructor for the HTTPResponse class. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
```

### void print()

This method prints the HTTP Response to the console. 
 
 Sample output:
 ```
    HTTP Response
    Version: HTTP/1.1
    Status Code: 200
    Reason Phrase: OK
    Headers:
    Content-Type: text/html
    Content-Length: 48
    Body: <html><body><h1>It works!</h1></body></html>
 ```

### bool isResponse()

This method returns true if the HTTP Message is a response and false if it is a request. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    if (response->isResponse()) {
        cout << "This is a response" << endl;
    } else {
        cout << "This is a request" << endl;
    }
 ```

### string getVersion()

This method returns the version of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Version: " << response->getVersion() << endl;
```

Output:
```
    Version: HTTP/1.1
```

### string getStatusCode()

This method returns the status code of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Status Code: " << response->getStatusCode() << endl;
```

Output:
```
    Status Code: 200
```

### string getReasonPhrase()

This method returns the reason phrase of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Reason Phrase: " << response->getReasonPhrase() << endl;
```

Output:
```
    Reason Phrase: OK
```

### map<string, string> getHeaders()

This method returns the headers of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    map<string, string> headers = response->getHeaders();
    for (auto const &x : headers)
    {
        cout << x.first << ": " << x.second << endl;
    }
```

Output:
```
    Content-Type: text/html
    Content-Length: 48
```

### string getBody()

This method returns the body of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Body: " << response->getBody() << endl;
```

Output:
```
    Body: <html><body><h1>It works!</h1></body></html>
```

### void setVersion(string version)

This method sets the version of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Version: " << response->getVersion() << endl;
    response->setVersion("HTTP/1.0");
    cout << "Version: " << response->getVersion() << endl;
```

Output:
```
    Version: HTTP/1.1
    Version: HTTP/1.0
```

### void setStatusCode(string statusCode)

This method sets the status code of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Status Code: " << response->getStatusCode() << endl;
    response->setStatusCode("404");
    cout << "Status Code: " << response->getStatusCode() << endl;
```

Output:
```
    Status Code: 200
    Status Code: 404
```

### void setReasonPhrase(string reasonPhrase)

This method sets the reason phrase of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Reason Phrase: " << response->getReasonPhrase() << endl;
    response->setReasonPhrase("Not Found");
    cout << "Reason Phrase: " << response->getReasonPhrase() << endl;
```

Output:
```
    Reason Phrase: OK
    Reason Phrase: Not Found
```

### void setHeaders(map<string, string> headers)

This method sets the headers of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    map<string, string> headers;
    response->print();
    headers["Content-Type"] = "text/html";
    headers["Content-Length"] = "48";
    response->setHeaders(headers);
    response->print();
```

Output:
```
    HTTP Response
    Version: HTTP/1.1
    Status Code: 200
    Reason Phrase: OK
    Headers:
    Body: 

    HTTP Response
    Version: HTTP/1.1
    Status Code: 200
    Reason Phrase: OK
    Headers:
    Content-Type: text/html
    Content-Length: 48
    Body: 
```

### void setBody(string body)

This method sets the body of the HTTP Response. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
    cout << "Body: " << response->getBody() << endl;
    response->setBody("<html><body><h1>It works!</h1></body></html>");
    cout << "Body: " << response->getBody() << endl;
```

Output:
```
    Body: 
    Body: <html><body><h1>It works!</h1></body></html>
```