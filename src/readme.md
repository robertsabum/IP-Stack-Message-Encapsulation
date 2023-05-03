# TCPStack

This class represents the TCP Stack. It has the following properties:

 - `applicationLayer` : ApplicationLayer
 - `transportLayer`: TransportLayer
 - `networkLayer` : NetworkLayer
 - `dataLinkLayer` : DataLinkLayer
 - `physicalLayer` : PhysicalLayer

and the following methods:

- [TCPStack()](#TCPStack)
- [send(HTTPMessage *message)](#BitStream-sendHTTPMessage-message)
- [receive(BitStream *bits)](#void-receiveBitStream-bits)

### Constructors

#### TCPStack()

This is the default constructor for the TCPStack class. When called it creates objects for each layer in the TCP Stack.
 
Example usage:
```cpp
    TCPStack* tcpStack = new TCPStack();
```

### Methods

#### BitStream *send(HTTPMessage *message)

This method sends an HTTPMessage to the Physical Layer. By forwarding the message 
through each layer and adding header information at each layer.
 
Example usage:
```cpp
    TCPStack* tcpStack = new TCPStack();
    HTTPRequest* request = new HTTPRequest("request.txt");
    BitStream* bits = tcpStack->send(request);
```

#### void receive(BitStream *bits)

This method recieves a BitStream from the Physical Layer by forwarding the message 
through each layer and unpacking the contents of the message at each layer. 
 
Example usage:
```cpp
    TCPStack* tcpStack = new TCPStack();
    BitStream* bits = new BitStream("bits.txt");
    tcpStack->receive(bits);
```