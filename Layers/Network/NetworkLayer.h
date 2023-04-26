#ifndef NETWORKLAYER_H
#define NETWORKLAYER_H

#include "../Transport/TCPSegment.h"
#include "IPv4Packet.h"
#include <iostream>
#include <queue>

using namespace std;

class NetworkLayer
{
private:
  queue<TCPSegment *> TCPbuffer;

public:
  NetworkLayer() {}

  TCPSegment *recieve(IPv4Packet *packet)
  {
    cout << "\nRecieved an IPv4 Packet from the Data Link Layer" << endl;
    TCPSegment *segment = packet->getTCPSegment();
    // delete packet;
    cout << "Sent a TCP Segment to the Transport Layer" << endl;
    return segment;
  }

  IPv4Packet *recieve(TCPSegment *segment)
  {
    cout << "\nRecieved a TCP Segment from the Transport Layer" << endl;
    this->TCPbuffer.push(segment);
    return serve();
  }

  IPv4Packet *serve()
  {
    if (TCPbuffer.size() > 0)
    {
      TCPSegment *segment = this->TCPbuffer.front();
      this->TCPbuffer.pop();
      IPv4Packet *packet = new IPv4Packet(segment);
      cout << "Served item from buffer" << endl;
      cout << "Sent an IPv4 Packet to the Data Link Layer" << endl;
      return packet;
    }
    else
    {
      cout << "\nTCP Buffer is empty" << endl;
      return nullptr;
    }
  }
};

#endif