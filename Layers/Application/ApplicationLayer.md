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

Output:
```
    Host: localhost:8080
    User-Agent: curl/7.64.1
    Accept: */*
    Content-Length: 0
    Content-Type: application/x-www-form-urlencoded
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