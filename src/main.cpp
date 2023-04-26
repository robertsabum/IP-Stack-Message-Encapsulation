#include "../Layers/Application/HTTPMessage.h"
#include "../Layers/Application/HTTPRequest.h"
#include "TCPStack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string filename = "http_post_request.txt";
  HTTPRequest *request = new HTTPRequest(filename);

  TCPStack *stack1 = new TCPStack();
  TCPStack *stack2 = new TCPStack();

  cout << "\n\n ****** Sending HTTP Request ******" << endl;
  BitStream *bits1 = stack1->send(new HTTPMessage(request));
  
  cout << "\n\n ****** Recieving Bitstream ******" << endl;
  stack2->receive(bits1);
}