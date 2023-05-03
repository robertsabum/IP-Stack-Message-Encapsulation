
# DataLink Layer
This folder contains the code for the DataLink Layer of the TCP Stack. It contains the following classes:
- [EthernetFrame](#EthernetFrame) 
- [DataLinkLayer](#DataLinkLayer)


## EthernetFrame

This class represents an Ethernet Frame. It has the following properties:

- `preamble` : unsigned char[7]
- `startFrameDelimiter` : unsigned char
- `destinationAddress` : unsigned char[6]
- `sourceAddress` : unsigned char[6]
- `type` : unsigned char[2]
- `data` : unsigned char[1500]
- `frameCheckSequence` : unsigned char[4]
- `interFrameGap` : unsigned char[12]
- `packet` : IPv4Packet*

It has the following methods:
- [EthernetFrame(IPv4Packet* packet)](#EthernetFrameIPv4Packet-packet)
- [~EthernetFrame()](#~EthernetFrame)
- [setPreamble(unsigned char* preamble)](#void-setPreambleunsigned-char-preamble)
- [setStartFrameDelimiter(unsigned char startFrameDelimiter)](#void-setStartFrameDelimiterunsigned-char-startFrameDelimiter)
- [setDestinationAddress(unsigned char* destinationAddress)](#void-setDestinationAddressunsigned-char-destinationAddress)
- [setSourceAddress(unsigned char* sourceAddress)](#void-setSourceAddressunsigned-char-sourceAddress)
- [setType(unsigned char* type)](#void-setTypeunsigned-char-type)
- [setData(unsigned char* data)](#void-setDataunsigned-char-data)
- [setFrameCheckSequence(unsigned char* frameCheckSequence)](#void-setFrameCheckSequenceunsigned-char-frameCheckSequence)
- [setInterFrameGap(unsigned char* interFrameGap)](#void-setInterFrameGapunsigned-char-interFrameGap)
- [setPacket(IPv4Packet* packet)](#void-setPacketIPv4Packet-packet)
- [getPreamble()](#unsigned-char-getPreamble-1)
- [getStartFrameDelimiter()](#unsigned-char-getStartFrameDelimiter)
- [getDestinationAddress()](#unsigned-char-getDestinationAddress)
- [getSourceAddress()](#unsigned-char-getSourceAddress)
- [getType()](#unsigned-char-getType)
- [getData()](#unsigned-char-getData)
- [getFrameCheckSequence()](#unsigned-char-getFrameCheckSequence)
- [getInterFrameGap()](#unsigned-char-getInterFrameGap)
- [getPacket()](#IPv4Packet-getPacket)

### Constructors

#### EthernetFrame(IPv4Packet* packet)

This is the constructor for the EthernetFrame class. It takes an IPv4Packet as a parameter and adds
headers to it to make it an EthernetFrame. The headers are set to random and default values. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet();
    EthernetFrame* frame = new EthernetFrame(packet);
```

### Getters

#### unsigned char* getPreamble()

This method gets the preamble of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* preamble = frame->getPreamble();
```

#### unsigned char getStartFrameDelimiter()

This method gets the start frame delimiter of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char startFrameDelimiter = frame->getStartFrameDelimiter();
```

#### unsigned char* getDestinationAddress()

This method gets the destination address of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* destinationAddress = frame->getDestinationAddress();
```

#### unsigned char* getSourceAddress()

This method gets the source address of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* sourceAddress = frame->getSourceAddress();
```

#### unsigned char* getType()

This method gets the type of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* type = frame->getType();
```

#### unsigned char* getData()

This method gets the data of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* data = frame->getData();
```

#### unsigned char* getFrameCheckSequence()

This method gets the frame check sequence of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* frameCheckSequence = frame->getFrameCheckSequence();
```

#### unsigned char* getInterFrameGap()

This method gets the interframe gap of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char* interFrameGap = frame->getInterFrameGap();
```

#### IPv4Packet* getPacket()

This method gets the packet of the EthernetFrame. 
 
Example usage:
```cpp
    IPv4Packet* packet = frame->getPacket();
```

### Setters

#### void setPreamble(unsigned char* preamble)

This method sets the preamble of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char preamble[7] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
    frame->setPreamble(preamble);
```

#### void setStartFrameDelimiter(unsigned char startFrameDelimiter)

This method sets the start frame delimiter of the EthernetFrame. 
 
Example usage:
```cpp
    frame->setStartFrameDelimiter(0xAB);
```

#### void setDestinationAddress(unsigned char* destinationAddress)

This method sets the destination address of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char destinationAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    frame->setDestinationAddress(destinationAddress);
```

#### void setSourceAddress(unsigned char* sourceAddress)

This method sets the source address of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char sourceAddress[6] = {0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB};
    frame->setSourceAddress(sourceAddress);
```

#### void setType(unsigned char* type)

This method sets the type of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char type[2] = {0x08, 0x00};
    frame->setType(type);
```

#### void setData(unsigned char* data)

This method sets the data of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char data[1500] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
    frame->setData(data);
```

#### void setFrameCheckSequence(unsigned char* frameCheckSequence)

This method sets the frame check sequence of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char frameCheckSequence[4] = {0x00, 0x01, 0x02, 0x03};
    frame->setFrameCheckSequence(frameCheckSequence);
```

#### void setInterFrameGap(unsigned char* interFrameGap)

This method sets the interframe gap of the EthernetFrame. 
 
Example usage:
```cpp
    unsigned char interFrameGap[12] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B};
    frame->setInterFrameGap(interFrameGap);
```

#### void setPacket(IPv4Packet* packet)

This method sets the packet of the EthernetFrame. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet();
    frame->setPacket(packet);
```

## DataLinkLayer

This class represents the Data Link Layer of the TCP Stack. It has the following properties:

- `IPv4buffer` : queue<IPv4Packet*>

and the following methods:

- [DataLinkLayer()](#DataLinkLayer)
- [recieve(EthernetFrame* frame)](#DataLinkLayer-recieveEthernetFrame-frame)
- [recieve(IPv4Packet* packet)](#EthernetFrame-recieveIPv4Packet-packet)
- [serve()](#EthernetFrame-serve)

### Constructors

#### DataLinkLayer()

This is the constructor for the DataLinkLayer class. It takes no parameters and
initializes the IPv4buffer to an empty queue. 
 
Example usage:
```cpp
    DataLinkLayer* dataLinkLayer = new DataLinkLayer();
```

### Methods

#### IPv4Packet* recieve(EthernetFrame* frame)

This method recieves an EthernetFrame from the Physical Layer and unpacks it into an IPv4Packet
which it then returns. 
 
Example usage:
```cpp
    EthernetFrame* frame = new EthernetFrame();
    IPv4Packet* packet = dataLinkLayer->recieve(frame);
```

#### EthernetFrame* recieve(IPv4Packet* packet)

This method recieves an IPv4Packet from the Network Layer queues it in the IPv4buffer and calls `serve()`.
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet();
    EthernetFrame* frame = dataLinkLayer->recieve(packet);
```

#### EthernetFrame* serve()

This method serves an item from the TCP buffer by encapsulating it in an EthernetFrame
which it then returns.  
 
Example usage:
```cpp
    EthernetFrame* frame = dataLinkLayer->serve();
```