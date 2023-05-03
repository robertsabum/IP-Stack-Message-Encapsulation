# Network Layer
This folder contains the code for the Network Layer of the TCP Stack. It contains the following classes:
- [IPv4Packet](#IPv4Packet) 
- [NetworkLayer](#NetworkLayer)

## IPv4Packet

This class represents an IPv4 Packet. It has the following methods:
- [IPv4Packet(TCPSegment *segment)](#IPv4PacketTCPSegment-segment)
- [getVersion()](#uint8_t-getVersion)
- [getIHL()](#uint8_t-getIHL)
- [getDSCP()](#uint8_t-getDSCP)
- [getECN()](#uint8_t-getECN)
- [getTotalLength()](#uint16_t-getTotalLength)
- [getIdentification()](#uint16_t-getIdentification)
- [getFlags()](#uint8_t-getFlags)
- [getFragmentOffset()](#uint16_t-getFragmentOffset)
- [getTTL()](#uint8_t-getTTL)
- [getProtocol()](#uint8_t-getProtocol)
- [getHeaderChecksum()](#uint16_t-getHeaderChecksum)
- [getSourceAddress()](#uint32_t-getSourceAddress)
- [getDestinationAddress()](#uint32_t-getDestinationAddress)
- [getOptions()](#unsigned-char-getOptions)
- [getTCPSegment()](#TCPSegment-getTCPSegment)
- [setVersion(uint8_t version)](#void-setVersionuint8_t-version)
- [setIHL(uint8_t IHL)](#void-setIHLuint8_t-IHL)
- [setDSCP(uint8_t DSCP)](#void-setDSCPuint8_t-DSCP)
- [setECN(uint8_t ECN)](#void-setECNuint8_t-ECN)
- [setTotalLength(uint16_t totalLength)](#void-setTotalLengthuint16_t-totalLength)
- [setIdentification(uint16_t identification)](#void-setIdentificationuint16_t-identification)
- [setFlags(uint8_t flags)](#void-setFlagsuint8_t-flags)
- [setFragmentOffset(uint16_t fragmentOffset)](#void-setFragmentOffsetuint16_t-fragmentOffset)
- [setTTL(uint8_t TTL)](#void-setTTLuint8_t-TTL)
- [setProtocol(uint8_t protocol)](#void-setProtocoluint8_t-protocol)
- [setHeaderChecksum(uint16_t headerChecksum)](#void-setHeaderChecksumuint16_t-headerChecksum)
- [setSourceAddress(uint32_t sourceAddress)](#void-setSourceAddressuint32_t-sourceAddress)
- [setDestinationAddress(uint32_t destinationAddress)](#void-setDestinationAddressuint32_t-destinationAddress)
- [setOptions(unsigned char *options)](#void-setOptionsunsigned-char-options)
- [setTCPSegment(TCPSegment *segment)](#void-setTCPSegmentTCPSegment-segment)

### Constructors

#### IPv4Packet(TCPSegment *segment)

This is the constructor for the IPv4Packet class. It takes a TCPSegment as a parameter. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment("segment.txt");
    IPv4Packet* packet = new IPv4Packet(segment);
```

### Getters

#### uint8_t getVersion()

This method returns the version of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t version = packet->getVersion();
```

#### uint8_t getIHL()

This method returns the IHL of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t IHL = packet->getIHL();
```

#### uint8_t getDSCP()

This method returns the DSCP of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t DSCP = packet->getDSCP();
```

#### uint8_t getECN()

This method returns the ECN of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t ECN = packet->getECN();
```

#### uint16_t getTotalLength()

This method returns the total length of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint16_t totalLength = packet->getTotalLength();
```

#### uint16_t getIdentification()

This method returns the identification of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint16_t identification = packet->getIdentification();
```

#### uint8_t getFlags()

This method returns the flags of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t flags = packet->getFlags();
```

#### uint16_t getFragmentOffset()

This method returns the fragment offset of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint16_t fragmentOffset = packet->getFragmentOffset();
```

#### uint8_t getTTL()

This method returns the TTL of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t TTL = packet->getTTL();
```

#### uint8_t getProtocol()

This method returns the protocol of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint8_t protocol = packet->getProtocol();
```

#### uint16_t getHeaderChecksum()

This method returns the header checksum of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint16_t headerChecksum = packet->getHeaderChecksum();
```

#### uint32_t getSourceAddress()

This method returns the source address of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint32_t sourceAddress = packet->getSourceAddress();
```

#### uint32_t getDestinationAddress()

This method returns the destination address of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    uint32_t destinationAddress = packet->getDestinationAddress();
```

#### unsigned char *getOptions()

This method returns the options of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    unsigned char* options = packet->getOptions();
```

#### TCPSegment *getTCPSegment()

This method returns the TCPSegment of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    TCPSegment* segment = packet->getTCPSegment();
```

### Setters

#### void setVersion(uint8_t version)

This method sets the version of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setVersion(4);
```

#### void setIHL(uint8_t IHL)

This method sets the IHL of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setIHL(5);
```

#### void setDSCP(uint8_t DSCP)

This method sets the DSCP of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setDSCP(0);
```

#### void setECN(uint8_t ECN)

This method sets the ECN of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setECN(0);
```

#### void setTotalLength(uint16_t totalLength)

This method sets the total length of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setTotalLength(0);
```

#### void setIdentification(uint16_t identification)

This method sets the identification of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setIdentification(0);
```

#### void setFlags(uint8_t flags)

This method sets the flags of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setFlags(0);
```

#### void setFragmentOffset(uint16_t fragmentOffset)

This method sets the fragment offset of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setFragmentOffset(0);
```

#### void setTTL(uint8_t TTL)

This method sets the TTL of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setTTL(0);
```

#### void setProtocol(uint8_t protocol)

This method sets the protocol of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setProtocol(6);
```

#### void setHeaderChecksum(uint16_t headerChecksum)

This method sets the header checksum of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setHeaderChecksum(0);
```

#### void setSourceAddress(uint32_t sourceAddress)

This method sets the source address of the IPv4Packet. 
 
Example usage:
```cpp
      IPv4Packet* packet = new IPv4Packet(segment);
    packet->setSourceAddress(0);
```

#### void setDestinationAddress(uint32_t destinationAddress)

This method sets the destination address of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    packet->setDestinationAddress(0);
```

#### void setOptions(unsigned char *options)

This method sets the options of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    unsigned char* options = new unsigned char[4];
    packet->setOptions(options);
```

#### void setTCPSegment(TCPSegment *segment)

This method sets the TCPSegment of the IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet(segment);
    TCPSegment* segment = new TCPSegment("segment.txt");
    packet->setTCPSegment(segment);
```


## NetworkLayer

This class represents the Network Layer of the TCP Stack. It has the following properties:

- `TCPBuffer` : vector<TCPSegment*>

and the following methods:
- [NetworkLayer()](#NetworkLayer)
- [recieve(IPv4Packet *packet)](#TCPSegment-recieveIPv4Packet-packet)
- [recieve(TCPSegment *segment)](#IPv4Packet-recieveTCPSegment-segment)
- [serve()](#IPv4Packet-serve)

### Constructors

#### NetworkLayer()

This is the constructor for the NetworkLayer class. It takes no parameters. 
 
Example usage:
```cpp
    NetworkLayer* networkLayer = new NetworkLayer();
```

### Methods

#### TCPSegment *recieve(IPv4Packet *packet)

This method recieves an IPv4Packet from the Data Link Layer and returns a TCPSegment. 
 
Example usage:
```cpp
    IPv4Packet* packet = new IPv4Packet();
    TCPSegment* segment = networkLayer->recieve(packet);
```

#### IPv4Packet *recieve(TCPSegment *segment)

This method recieves a TCPSegment from the Transport Layer and returns an IPv4Packet. 
 
Example usage:
```cpp
    TCPSegment* segment = new TCPSegment();
    IPv4Packet* packet = networkLayer->recieve(segment);
```

#### IPv4Packet *serve()

This method serves an item from the TCP buffer and returns an IPv4Packet. 
 
Example usage:
```cpp
    IPv4Packet* packet = networkLayer->serve();
```