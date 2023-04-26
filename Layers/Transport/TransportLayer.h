#ifndef TRANSPORTLAYER_H
#define TRANSPORTLAYER_H

#include "../Application/HTTPMessage.h"
#include "TCPSegment.h"
#include <iostream>
#include <queue>
using namespace std;

class TransportLayer
{
private:
  queue<HTTPMessage *> HTTPbuffer;

public:
  TransportLayer() {}

  HTTPMessage *recieve(TCPSegment *segment)
  {
    cout << "\nRecieved a TCPSegment from the Network Layer" << endl;
    HTTPMessage *message = segment->getHTTPMessage();
    // delete segment;
    cout << "Sent an HTTPMessage to the Application Layer" << endl;
    return message;
  }

  TCPSegment *recieve(HTTPMessage *message)
  {
    cout << "\nRecieved an HTTPMessage from the Application Layer" << endl;
    this->HTTPbuffer.push(message);
    return serve();
  }

  TCPSegment *serve()
  {
    if (HTTPbuffer.size() > 0)
    {
      HTTPMessage *message = this->HTTPbuffer.front();
      TCPSegment *segment = new TCPSegment(message);
      this->HTTPbuffer.pop();
      cout << "Served an item from the buffer" << endl;
      cout << "Sent a TCP Segment to the Network Layer" << endl;
      return segment;
    }
    else
    {
      cout << "\nHTTP buffer is empty" << endl;
      return nullptr;
    }
  }
};

#endif