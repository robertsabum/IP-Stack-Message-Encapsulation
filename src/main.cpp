#include <string>
#include <iostream>
#include "../Layers/Application/HTTPRequest.h"
#include "../Layers/Application/HTTPMessage.h"
// #include "../Layers/Application/ApplicationLayer.h"
// #include "../Layers/Transport/TransportLayer.h"
// #include "../Layers/Network/NetworkLayer.h"
// #include "../Layers/DataLink/DataLinkLayer.h"
// #include "../Layers/Physical/PhysicalLayer.h"

using namespace std;


int main(){
    string file = "htt_get_request.txt";
    HTTPRequest* request = new HTTPRequest(file);
    request->print();
    
}