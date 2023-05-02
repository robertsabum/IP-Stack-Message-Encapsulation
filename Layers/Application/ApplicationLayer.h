#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include "../Transport/TransportLayer.h"
#include "HTTPMessage.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include <iostream>
using namespace std;

class ApplicationLayer
{

public:
  ApplicationLayer() {}

  HTTPMessage *send(HTTPMessage *message)
  {
    if (message->isRequest())
    {
      cout << "\nSent a Request to the Transport Layer" << endl;
    }
    else
    {
      cout << "\nSent a Response to the Transport Layer" << endl;
    }
    return message;
  }

  void recieve(HTTPMessage *message)
  {
    cout << "\nRecieved an HTTPMessage from the Transport Layer" << endl;
    message->print();
  }
};

#endif