code
```cpp

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
 This is a constructor for the HTTPRequest class. Example usage:
 ```cpp
    map<string, string> headers;
    headers["Host"] = "localhost:8080";
    headers["User-Agent"] = "curl/7.64.1";
    headers["Accept"] = "*/*";
    headers["Content-Length"] = "0";
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    HTTPRequest* request = new HTTPRequest("POST", "/login", "HTTP/1.1", headers, "");
 ```


 ### HTTPRequest()

 This is the default constructor for the HTTPRequest class. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest();
 ```

 ### HTTPRequest(string filename)

 This is the constructor for the HTTPRequest class. It takes in the following parameters:

 - filename: string

 It opens the file with the given filename and parses the HTTP Request from the file. Example file:
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

 This method prints the HTTP Request to the console. Sample output:
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

 This method returns true if the HTTP Message is a request and false if it is a response. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    if (request->isRequest()) {
        cout << "This is a request" << endl;
    } else {
        cout << "This is a response" << endl;
    }
 ```

 ### string getMethod()

 This method returns the method of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Method: " << request->getMethod() << endl;
 ```

 ### string getURL()

 This method returns the url of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "URL: " << request->getURL() << endl;
 ```

 ### string getVersion()

 This method returns the version of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Version: " << request->getVersion() << endl;
 ```

 ### map<string, string> getHeaders()

 This method returns the headers of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    map<string, string> headers = request->getHeaders();
    for (auto const &x : headers) {
        cout << x.first << ": " << x.second << endl;
    }
 ```

 ### string getBody()

 This method returns the body of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    cout << "Body: " << request->getBody() << endl;
 ```

 ### void setMethod(string method)

 This method sets the method of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    request->setMethod("GET");
    cout << "Method: " << request->getMethod() << endl;
 ```

 ### void setURL(string url)

 This method sets the url of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    request->setURL("/logout");
    cout << "URL: " << request->getURL() << endl;
 ```

 ### void setVersion(string version)

 This method sets the version of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    request->setVersion("HTTP/1.0");
    cout << "Version: " << request->getVersion() << endl;
 ```

 ### void setHeaders(map<string, string> headers)

 This method sets the headers of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    map<string, string> headers;
    headers["Host"] = "localhost:8080";
    headers["User-Agent"] = "curl/7.64.1";
    headers["Accept"] = "*/*";
    headers["Content-Length"] = "0";
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    request->setHeaders(headers);
    map<string, string> headers = request->getHeaders();
    for (auto const &x : headers) {
        cout << x.first << ": " << x.second << endl;
    }
 ```

 ### void setBody(string body)

 This method sets the body of the HTTP Request. Example usage:
 ```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    request->setBody("username=hello&password=world");
    cout << "Body: " << request->getBody() << endl;
 ```

 ## HTTPResponse

 This class represents an HTTP Response. It has the following properties:

 - version: string
 - statusCode: int
 - statusMessage: string
 - headers: map<string, string>
 - body: string

 It has the following methods:
 - HTTPResponse(string version, int statusCode, string statusMessage, map<string, string> headers, string body)
 - HTTPResponse()
 - HTTPResponse(string filename)
 - void print()
 - bool isRequest()
 - string getVersion()
 - int getStatusCode()
 - string getStatusMessage()
 - map<string, string> getHeaders()
 - string getBody()
 - void setVersion(string version)
 - void setStatusCode(int statusCode)
 - void setStatusMessage(string statusMessage)
 - void setHeaders(map<string, string> headers)
 - void setBody(string body)

 ### HTTPResponse(string version, int statusCode, string statusMessage, map<string, string> headers, string body)

 This is the constructor for the HTTPResponse class. It takes in the following parameters:

 - version: string
 - statusCode: int
 - statusMessage: string
 - headers: map<string, string>
 - body: string

 ### HTTPResponse()

 This is the default constructor for the HTTPResponse class. It sets the following properties:

 - version: "HTTP/1.1"
 - statusCode: 200
 - statusMessage: "OK"
 - headers: map<string, string>()
 - body: ""

 ### HTTPResponse(string filename)

 This is the constructor for the HTTPResponse class. It takes in the following parameters:

 - filename: string

 It opens the file with the given filename and parses the HTTP Response from the file.

 ### void print()

 This method prints the HTTP Response to the console.

 ### bool isRequest()

 This method returns true if the HTTP Message is a request and false if it is a response.

 ### string getVersion()

 This method returns the version of the HTTP Response.

 ### int getStatusCode()

 This method returns the status code of the HTTP Response.

 ### string getStatusMessage()

 This method returns the status message of the HTTP Response.

 ### map<string, string> getHeaders()

 This method returns the headers of the HTTP Response.

 ### string getBody()

 This method returns the body of the HTTP Response.

 ### void setVersion(string version)

 This method sets the version of the HTTP Response.

 ### void setStatusCode(int statusCode)

 This method sets the status code of the HTTP Response.

 ### void setStatusMessage(string statusMessage)

 This method sets the status message of the HTTP Response.

 ### void setHeaders(map<string, string> headers)

 This method sets the headers of the HTTP Response.

 ### void setBody(string body)

 This method sets the body of the HTTP Response.

 ## ApplicationLayer

 This class represents the application layer in the network stack. It has the following methods:

 - send(HTTPMessage *message)
 - recieve(HTTPMessage *message)

 ### send(HTTPMessage *message)

 This method sends an HTTPMessage to the transport layer.

 ### recieve(HTTPMessage *message)

 This method recieves an HTTPMessage from the transport layer.s method sets the headers of the HTTP Response.

 ### void setBody(string body)

 This method sets the body of the HTTP Response.

 ## ApplicationLayer

 This class represents the application layer in the network stack. It has the following methods:

 - send(HTTPMessage *message)
 - recieve(HTTPMessage *message)

 ### send(HTTPMessage *message)

 This method sends an HTTPMessage to the transport layer.

 ### recieve(HTTPMessage *message)

 This method recieves an HTTPMessage from the transport layer.