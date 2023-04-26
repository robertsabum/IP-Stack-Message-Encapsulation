#ifndef DATALINKLAYER_H
#define DATALINKLAYER_H

#include "../Network/IPv4Packet.h"
#include "EthernetFrame.h"
#include <iostream>
#include <queue>

using namespace std;

class DataLinkLayer
{
private:
  queue<IPv4Packet *> IPv4buffer;

public:
  DataLinkLayer() {}

  IPv4Packet *recieve(EthernetFrame *frame)
  {
    cout << "\nRecieved an Ethernet Frame from the Physical Layer" << endl;
    IPv4Packet *packet = frame->getPacket();
    // delete frame;
    cout << "Sent an IPv4 Packet to the Network Layer" << endl;
    return packet;
  }

  EthernetFrame *recieve(IPv4Packet *packet)
  {
    cout << "\nRecieved an IPv4 Packet from the Network Layer" << endl;
    this->IPv4buffer.push(packet);
    return serve();
  }

  EthernetFrame *serve()
  {
    if (IPv4buffer.size() > 0)
    {
      IPv4Packet *packet = this->IPv4buffer.front();
      this->IPv4buffer.pop();
      EthernetFrame *frame = new EthernetFrame(packet);
      cout << "Served item from buffer" << endl;
      cout << "Sent an Ethernet Frame to the Physical Layer" << endl;
      return frame;
    }
    else
    {
      cout << "\nIPv4 Buffer is empty" << endl;
      return nullptr;
    }
  }
};

#endif