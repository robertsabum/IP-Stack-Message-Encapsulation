#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include <iostream>
#include "../Transport/TransportLayer.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include <queue>
using namespace std;

class ApplicationLayer{
    private:
        bool connected;
        TransportLayer* TransportLayer;

    public:
        ApplicationLayer() {
            this->TransportLayer = NULL;
            this->connected = false;
        }

        ~ApplicationLayer() {
            this->disconnect();
        }

        void connect(TransportLayer* TransportLayer) {
            this->TransportLayer = TransportLayer;
            this->TransportLayer->connect(this);
            this->connected = true;
        }

        void disconnect() {
            this->TransportLayer->disconnect(this);
            this->TransportLayer = NULL;
            this->connected = false;
        }

        bool isConnected() {
            return connected;
        }

        void send(HTTPRequest* request) {
            if (connected) {
                cout << "Sent an HTTPRequest to the Transport Layer" << endl;
                TransportLayer->recieve(request);
            }
            else {
                cout << "Application Layer is not connected to a Transport Layer" << endl;
            }
        }

        void send(HTTPResponse* response) {
            if (connected) {
                cout << "Sent an HTTPResponse to the Transport Layer" << endl;
                TransportLayer->recieve(response);
            }
            else {
                cout << "Application Layer is not connected to a Transport Layer" << endl;
            }
        }

        void recieve(HTTPResponse* response) {
            cout << "Recieved a response in the buffer" << endl;
            response->print();
        }

        void recieve(HTTPRequest* request) {
            cout << "Recieved a request in the buffer" << endl;
            // send a generic response
            HTTPResponse* response = new HTTPResponse(request->getVersion(), 200, "OK", "This is a generic response");
            send(response);
        }
};

#endif