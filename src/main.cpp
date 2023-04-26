#include "../Layers/Application/HTTPMessage.h"
#include "../Layers/Application/HTTPRequest.h"
#include "TCPStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // string file = "http_get_request.txt";
  HTTPRequest *request = new HTTPRequest();
  // request->print();
  TCPStack *stack1 = new TCPStack();
  TCPStack *stack2 = new TCPStack();

  BitStream *bits1 = stack1->send(new HTTPMessage(request));
  stack2->receive(bits1);
}