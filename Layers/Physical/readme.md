# Physical Layer
This folder contains the code for the Physical Layer of the TCP Stack. It contains the following classes:
- [BitStream](#BitStream) 
- [Physical](#PhysicalLayer)

## BitStream

This class represents a bit stream. It has the following properties:

- `frame` : EthernetFrame*

It has the following methods:
- [BitStream(EthernetFrame* frame)](#BitStreamEthernetFrame-frame)
- [~BitStream()](#BitStream)
- [setEthernetFrame(EthernetFrame* frame)](#void-setEthernetFrameEthernetFrame-frame)
- [getEthernetFrame()](#EthernetFrame-getEthernetFrame)
- [writeToFile()](#void-writeToFile)

### Constructors

#### BitStream(EthernetFrame* frame)

This is a constructor for the BitStream class. It takes in the following parameters:

- frame: EthernetFrame*

Example usage:
```cpp
    EthernetFrame* frame = new EthernetFrame();
    BitStream* bitstream = new BitStream(frame);
```

### Getters

#### EthernetFrame* getEthernetFrame()

This method returns the EthernetFrame associated with the BitStream. 
 
Example usage:
```cpp
    BitStream* bitstream = new BitStream(frame);
    EthernetFrame* frame = bitstream->getEthernetFrame();
```

### Setters

#### void setEthernetFrame(EthernetFrame* frame)

This method sets the EthernetFrame associated with the BitStream. 
 
Example usage:
```cpp
    BitStream* bitstream = new BitStream(frame);
    EthernetFrame* newFrame = new EthernetFrame();
    bitstream->setEthernetFrame(newFrame);
```

### void writeToFile()

This method writes the BitStream to a file in binary mode. 
 
Example usage:
```cpp
    BitStream* bitstream = new BitStream(frame);
    bitstream->writeToFile();
```

## Physical Layer

This class represents the Physical Layer of the TCP Stack. It has the following properties:

- `EthernetBuffer` : vector<EthernetFrame*>

and the following methods:

- [PhysicalLayer()](#PhysicalLayer)
- [receive(BitStream *bitstream)](#EthernetFrame-receiveBitStream-bitstream)
- [receive(EthernetFrame *frame)](#BitStream-receiveEthernetFrame-frame)
- [serve()](#BitStream-serve)

### Constructors

#### PhysicalLayer()

This is the default constructor for the PhysicalLayer class. 
 
Example usage:
```cpp
    PhysicalLayer* physicalLayer = new PhysicalLayer();
```

### Methods

#### EthernetFrame *receive(BitStream *bitstream)

This method receives a BitStream from another TCP Stack and returns an EthernetFrame. 
 
Example usage:
```cpp
    PhysicalLayer* physicalLayer = new PhysicalLayer();
    BitStream* bitstream = new BitStream(frame);
    EthernetFrame* frame = physicalLayer->receive(bitstream);
```

#### BitStream *receive(EthernetFrame *frame)

This method receives an EthernetFrame from the Data Link Layer and returns a BitStream. 
 
Example usage:
```cpp
    PhysicalLayer* physicalLayer = new PhysicalLayer();
    EthernetFrame* frame = new EthernetFrame();
    BitStream* bitstream = physicalLayer->receive(frame);
```

#### BitStream *serve()

This method serves an item from the buffer and returns a BitStream. 
 
Example usage:
```cpp
    PhysicalLayer* physicalLayer = new PhysicalLayer();
    BitStream* bitstream = physicalLayer->serve();
```