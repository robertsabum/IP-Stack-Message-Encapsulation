#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include <iostream>
#include "../Transport/TransportLayer.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include "HTTPMessage.h"
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

        void send(HTTPMessage* message) {
            if (connected) {
                cout << "Sent an HTTPMessage to the Transport Layer" << endl;
                    TransportLayer->recieve(message);
            }
            else {
                cout << "Application Layer is not connected to a Transport Layer" << endl;
            }
        }

        void recieve(HTTPMessage* message) {
            cout << "Recieved an HTTPMessage from the Transport Layer" << endl;
            message->print();
            if (message->isRequest) {
                HTTPMessage* response = new HTTPMessage(HTTPResponse());
                send(response);
            }
};

#endif