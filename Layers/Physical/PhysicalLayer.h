#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include "../DataLink/EthernetFrame.h"
#include "BitStream.h"
#include <iostream>
#include <queue>
using namespace std;

class PhysicalLayer
{
private:
  queue<EthernetFrame *> Ethernetbuffer;

public:
  PhysicalLayer() {}

  EthernetFrame *receive(BitStream *bitstream)
  {
    cout << "\nReceived a Bitstream from another TCP Stack" << endl;
    EthernetFrame *frame = bitstream->getEthernetFrame();
    // delete bitstream;
    cout << "Sent an Ethernet Frame to the Data Link Layer" << endl;
    return frame;
  }

  BitStream *receive(EthernetFrame *frame)
  {
    cout << "\nReceived an Ethernet Frame from the Data Link Layer" << endl;
    Ethernetbuffer.push(frame);
    return serve();
  }

  BitStream *serve()
  {
    if (Ethernetbuffer.size() > 0)
    {
      EthernetFrame *frame = Ethernetbuffer.front();
      Ethernetbuffer.pop();
      BitStream *bitstream = new BitStream(frame);
      bitstream->writeToFile();
      cout << "Served an item from the buffer" << endl;
      cout << "Sent out a Bitstream" << endl;
      return bitstream;
    }
    else
    {
      cout << "\nEthernet Buffer is empty" << endl;
      return nullptr;
    }
  }
};

#endif