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

### Constructors

#### HTTPRequest(string method, string url, string version, map<string, string> headers, string body)
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

#### HTTPRequest()

This is the default constructor for the HTTPRequest class. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest();
```

#### HTTPRequest(string filename)

This is the constructor for the HTTPRequest class. It takes in the following parameters:

- filename: string

It opens the file with the given filename and parses the HTTP Request from the file. 
 
Example file:
```
    POST /login HTTP/1.1
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept:* /*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    username=hello&password=world
 ```

Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
```

#### void print()

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
    Accept:* /*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
```

### Getters

#### bool isRequest()

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

#### string getMethod()

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
#### string getURL()

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

#### string getVersion()

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

#### map<string, string> getHeaders()

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
    Accept:* /*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
```

#### string getBody()

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

### Setters

#### void setMethod(string method)

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

#### void setURL(string url)

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

#### void setVersion(string version)

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

#### void setHeaders(map<string, string> headers)

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
    Accept:* /*
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
    Accept:* /*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
```

#### void setBody(string body)

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

## HTTPResponse

This class represents an HTTP Response. It has the following properties:

- `version` : string
- `status` : string
- `reasonPhrase` : string
- `headers` : map<string, string>
- `body` : string


It has the following methods:

- [HTTPResponse(string version, string status, string reasonPhrase, map<string, string> headers, string body)](#HTTPResponsestring-version-string-status-string-reasonPhrase-mapstring-string-headers-string-body)
- [HTTPResponse()](#HTTPResponse)
- [HTTPResponse(string filename)](#HTTPResponsestring-filename)
- [print()](#void-print)
- [isRequest()](#bool-isRequest)
- [getVersion()](#string-getVersion)
- [getStatus()](#string-getStatus)
- [getReasonPhrase()](#string-getReasonPhrase)
- [getHeaders()](#mapstring-string-getHeaders)
- [getBody()](#string-getBody)
- [setVersion(string version)](#void-setVersionstring-version)
- [setStatus(string status)](#void-setStatusstring-status)
- [setReasonPhrase(string reasonPhrase)](#void-setReasonPhrasestring-reasonPhrase)
- [setHeaders(map<string, string> headers)](#void-setHeadersmapstring-string-headers)
- [setBody(string body)](#void-setBodystring-body)

### Constructors

#### HTTPResponse(string version, string status, string reasonPhrase, map<string, string> headers, string body)
This is a constructor for the HTTPResponse class.

Example usage:
```cpp
    map<string, string> headers;
    headers["Host"] = "localhost:8080";
    headers["User-Agent"] = "curl/7.64.1";
    headers["Accept"] = "*/*";
    headers["Content-Length"] = "0";
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    HTTPResponse* response = new HTTPResponse("HTTP/1.1", "200", "OK", headers, "");
```

#### HTTPResponse()

This is the default constructor for the HTTPResponse class. 
 
Example usage:
```cpp
    HTTPResponse* response = new HTTPResponse();
```

#### void print()

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

### Getters

#### bool isResponse()

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

#### string getVersion()

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

#### string getStatusCode()

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

#### string getReasonPhrase()

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

#### map<string, string> getHeaders()

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

#### string getBody()

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

### Setters

#### void setVersion(string version)

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

#### void setStatusCode(string statusCode)

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

#### void setReasonPhrase(string reasonPhrase)

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

#### void setHeaders(map<string, string> headers)

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

#### void setBody(string body)

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

## HTTPMessage

This class represents an HTTP Message. It has the following properties:

- `_isRequest` : bool
- `request` : HTTPRequest*
- `response` : HTTPResponse*

It has the following methods:
- [HTTPMessage(HTTPRequest* _request)](#HTTPMessageHTTPRequest-_request)
- [HTTPMessage(HTTPResponse* _response)](#HTTPMessageHTTPResponse-_response)
- [print()](#void-print-1)
- [isRequest()](#bool-isRequest-1)

### Constructors

#### HTTPMessage(HTTPRequest* _request)

This is a constructor for the HTTPMessage class. It takes in the following parameters:

- _request: HTTPRequest*

Example usage:
```cpp
    map<string, string> headers;
    headers["Host"] = "localhost:8080";
    headers["User-Agent"] = "curl/7.64.1";
    headers["Accept"] = "*/*";
    headers["Content-Length"] = "0";
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    HTTPRequest* request = new HTTPRequest("POST", "/login", "HTTP/1.1",    headers, "");
    HTTPMessage* message = new HTTPMessage(request);
```

#### HTTPMessage(HTTPResponse* _response)

This is a constructor for the HTTPMessage class. It takes in the following parameters:

- _response: HTTPResponse*

Example usage:
```cpp
    map<string, string> headers;
    headers["Content-Type"] = "text/html";
    headers["Content-Length"] = "0";
    HTTPResponse* response = new HTTPResponse("HTTP/1.1", 200, "OK", headers, "");
    HTTPMessage* message = new HTTPMessage(response);
```

#### void print()

This method prints the HTTP Message to the console. 
 
Sample output:
```
    HTTP Request
    Method: POST
    URL: /login
    Version: HTTP/1.1
    Headers:
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept:* /*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
    Body: username=hello&password=world
```

### Getters

#### bool isRequest()

This method returns true if the HTTP Message is a request and false if it is a response. 
 
Example usage:
```cpp
    HTTPRequest* request = new HTTPRequest("request.txt");
    HTTPMessage* message = new HTTPMessage(request);
    if (message->isRequest()) {
        cout << "This is a request" << endl;
    } else {
        cout << "This is a response" << endl;
    }
```

Output:
```
    This is a request
```


## ApplicationLayer

This class represents the Application Layer of the TCP Stack. It has the following methods:
- [ApplicationLayer()](#ApplicationLayer)
- [send(HTTPMessage* message)](#HTTPMessage-sendHTTPMessage-message)
- [recieve(HTTPMessage* message)](#void-recieveHTTPMessage-message)

### Constructors

#### ApplicationLayer()

This is the default constructor for the ApplicationLayer class. 
 
Example usage:
```cpp
    ApplicationLayer* applicationLayer = new ApplicationLayer();
```

### Methods

#### HTTPMessage* send(HTTPMessage* message)

This method sends an HTTPMessage to the Transport Layer. 
 
Example usage:
```cpp
    ApplicationLayer* applicationLayer = new ApplicationLayer();
    HTTPRequest* request = new HTTPRequest("request.txt");
    HTTPMessage* message = applicationLayer->send(request);
```

#### void recieve(HTTPMessage* message)

This method recieves an HTTPMessage from the Transport Layer.
If its a response, it prints the response to the console.
If its a request, it sends back a response. 
 
Example usage:
```cpp
    ApplicationLayer* applicationLayer = new ApplicationLayer();
    HTTPRequest* request = new HTTPRequest("request.txt");
    applicationLayer->recieve(request);
```