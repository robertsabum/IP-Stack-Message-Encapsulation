# Transport Layer
This folder contains the code for the Application Layer of the TCP Stack. It contains the following classes:
- [TCPSegment](#TCPSegment) 
- [TransportLayer](#TransportLayer)

## TCPSegment

This class represents a TCP Segment. It has the following properties:

- `sourcePort` : uint16_t
- `destinationPort` : uint16_t
- `sequenceNumber` : uint32_t
- `acknowledgementNumber` : uint32_t
- `dataOffset` : uint8_t
- `flags` : uint8_t
- `windowSize` : uint16_t
- `checksum` : uint16_t
- `urgentPointer` : uint16_t
- `options` : unsigned char*
- `message` : HTTPMessage*

It has the following methods:
- [TCPSegment(HTTPMessage* message)](#TCPSegmentHTTPMessage-message)
- [~TCPSegment()](#~TCPSegment)
- [getSourcePort()](#uint16_t-getSourcePort-1)
- [getDestinationPort()](#uint16_t-getDestinationPort-1)
- [getSequenceNumber()](#uint32_t-getSequenceNumber-1)
- [getAcknowledgementNumber()](#uint32_t-getAcknowledgementNumber-1)
- [getDataOffset()](#uint8_t-getDataOffset-1)
- [getFlags()](#uint8_t-getFlags-1)
- [getWindowSize()](#uint16_t-getWindowSize-1)
- [getChecksum()](#uint16_t-getChecksum-1)
- [getUrgentPointer()](#uint16_t-getUrgentPointer-1)
- [getOptions()](#unsigned-char-getOptions-1)
- [getHTTPMessage()](#HTTPMessage-getHTTPMessage-1)
- [setSourcePort(uint16_t sourcePort)](#void-setSourcePortuint16_t-sourcePort)
- [setDestinationPort(uint16_t destinationPort)](#void-setDestinationPortuint16_t-destinationPort)
- [setSequenceNumber(uint32_t sequenceNumber)](#void-setSequenceNumberuint32_t-sequenceNumber)
- [setAcknowledgementNumber(uint32_t acknowledgementNumber)](#void-setAcknowledgementNumberuint32_t-acknowledgementNumber)
- [setDataOffset(uint8_t dataOffset)](#void-setDataOffsetuint8_t-dataOffset)
- [setFlags(uint8_t flags)](#void-setFlagsuint8_t-flags)
- [setWindowSize(uint16_t windowSize)](#void-setWindowSizeuint16_t-windowSize)
- [setChecksum(uint16_t checksum)](#void-setChecksumuint16_t-checksum)
- [setUrgentPointer(uint16_t urgentPointer)](#void-setUrgentPointeruint16_t-urgentPointer)
- [setOptions(unsigned char* options)](#void-setOptionsunsigned-char-options)
- [setHTTPMessage(HTTPMessage* message)](#void-setHTTPMessageHTTPMessage-message)

### Constructors

#### TCPSegment(HTTPMessage* message)

This is a constructor for the TCPSegment class. It takes in the following parameters:

- message: HTTPMessage*

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
    TCPSegment* segment = new TCPSegment(message);
```

#### ~TCPSegment()

This is the destructor for the TCPSegment class.

Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    delete segment;
```

### Getters

#### uint16_t getSourcePort()

This method returns the source port of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint16_t sourcePort = segment->getSourcePort();
```

#### uint16_t getDestinationPort()

This method returns the destination port of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint16_t destinationPort = segment->getDestinationPort();
```

#### uint32_t getSequenceNumber()

This method returns the sequence number of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint32_t sequenceNumber = segment->getSequenceNumber();
```

#### uint32_t getAcknowledgementNumber()

This method returns the acknowledgement number of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint32_t acknowledgementNumber = segment->getAcknowledgementNumber();
```

#### uint8_t getDataOffset()

This method returns the data offset of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint8_t dataOffset = segment->getDataOffset();
```

#### uint8_t getFlags()

This method returns the flags of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint8_t flags = segment->getFlags();
```

#### uint16_t getWindowSize()

This method returns the window size of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint16_t windowSize = segment->getWindowSize();
```

#### uint16_t getChecksum()

This method returns the checksum of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint16_t checksum = segment->getChecksum();
```

#### uint16_t getUrgentPointer()

This method returns the urgent pointer of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    uint16_t urgentPointer = segment->getUrgentPointer();
```

#### unsigned char* getOptions()

This method returns the options of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    unsigned char* options = segment->getOptions();
```

#### HTTPMessage* getHTTPMessage()

This method returns the HTTPMessage of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    HTTPMessage* message = segment->getHTTPMessage();
```

### Setters

#### void setSourcePort(uint16_t sourcePort)

This method sets the source port of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setSourcePort(8080);
```

#### void setDestinationPort(uint16_t destinationPort)

This method sets the destination port of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setDestinationPort(80);
```

#### void setSequenceNumber(uint32_t sequenceNumber)

This method sets the sequence number of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setSequenceNumber(12345);
```

#### void setAcknowledgementNumber(uint32_t acknowledgementNumber)

This method sets the acknowledgement number of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setAcknowledgementNumber(54321);
```

#### void setDataOffset(uint8_t dataOffset)

This method sets the data offset of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setDataOffset(5);
```

#### void setFlags(uint8_t flags)

This method sets the flags of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setFlags(0x02);
```

#### void setWindowSize(uint16_t windowSize)

This method sets the window size of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setWindowSize(1024);
```

#### void setChecksum(uint16_t checksum)

This method sets the checksum of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setChecksum(0xABCD);
```

#### void setUrgentPointer(uint16_t urgentPointer)

This method sets the urgent pointer of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    segment->setUrgentPointer(0x1234);
```

#### void setOptions(unsigned char* options)

This method sets the options of the TCP Segment. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment(message);
    unsigned char* options = new unsigned char[4];
    options[0] = 0x01;
    options[1] = 0x02;
    options[2] = 0x03;
    options[3] = 0x04;
    segment->setOptions(options);
```

#### void setHTTPMessage(HTTPMessage* message)

This method sets the HTTPMessage of the TCP Segment. 
 
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
    TCPSegment* segment = new TCPSegment(message);
    segment->setHTTPMessage(message);
```

## TransportLayer

This class represents the Transport Layer of the TCP Stack. It has the following properties:

- `HTTPBuffer` : queue<HTTPMessage*>

and the following methods:

- [TransportLayer()](#TransportLayer)
- [recieve(TCPSegment *segment)](#HTTPMessage-recieveTCPSegment-segment)
- [recieve(HTTPMessage *message)](#TCPSegment-recieveHTTPMessage-message)
- [serve()](#TCPSegment-serve)

### Constructors

#### TransportLayer()

This is the default constructor for the TransportLayer class. It takes no arguments and initializes the HTTPBuffer to an empty queue.
 
Example usage:
```cpp
    TransportLayer* transportLayer = new TransportLayer();
```

### Methods

#### HTTPMessage *recieve(TCPSegment *segment)

This method recieves a TCPSegment from the Network Layer and returns the encapsulated HTTPMessage. 
 
Example usage:
```cpp
    TransportLayer* transportLayer = new TransportLayer();
    TCPSegment* segment = new TCPSegment("segment.txt");
    HTTPMessage* message = transportLayer->recieve(segment);
```

#### TCPSegment *recieve(HTTPMessage *message)

This method recieves an HTTPMessage from the Application Layer and enqueue it in the HTTPBuffer. It then calls `serve()` 
 
Example usage:
```cpp
    TransportLayer* transportLayer = new TransportLayer();
    HTTPRequest* request = new HTTPRequest("request.txt");
    TCPSegment* segment = transportLayer->recieve(request);
```

#### TCPSegment *serve()

This method serves an item from the buffer by adding the TCP Header and returning the TCPSegment. 
 
Example usage:
```cpp
    TransportLayer* transportLayer = new TransportLayer();
    HTTPRequest* request = new HTTPRequest("request.txt");
    HTTPMessage* message = new HTTPMessage(request);
    transportLayer->recieve(message);
    TCPSegment* segment = transportLayer->serve();
```