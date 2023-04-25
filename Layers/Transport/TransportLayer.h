#ifndef TRANSPORTLAYER_H
#define TRANSPORTLAYER_H

#include <iostream>
#include "../Application/ApplicationLayer.h"
#include "../Network/NetworkLayer.h"
#include "TCPSegment.h"
#include <queue>
using namespace std;

class TransportLayer {
    private:
        bool connected;
        queue<variant<HTTPResponse*, HTTPRequest*>> HTTPbuffer;
        ApplicationLayer* connectedApplicationLayer;
        NetworkLayer* connectedNetworkLayer;

    public:
        transportLayer() {
            this->connectedApplicationLayer = NULL;
            this->connectedNetworkLayer = NULL;
            this->connected = false;
        }

        ~transportLayer() {
            this->disconnect();
        }

        void connect(ApplicationLayer* applicationLayer) {
            this->connectedApplicationLayer = applicationLayer;
            this->connected = true;
        }

        void connect(NetworkLayer* networkLayer) {
            this->connectedNetworkLayer = networkLayer;
            this->connected = true;
        }

        void disconnect(ApplicationLayer* applicationLayer) {
            this->connectedApplicationLayer = NULL;
            this->connected = false;
        }

        void disconnect(NetworkLayer* networkLayer) {
            this->connectedNetworkLayer = NULL;
            this->connected = false;
        }

        bool isConnected() {
            return connected;
        }

        void send(TCPSegment* segment) {
            if (connected) {
                cout << "Sent a TCPSegment to the Network Layer" << endl;
                connectedNetworkLayer->recieve(segment);
            }
            else {
                cout << "Transport Layer is not connected to a Network Layer" << endl;
            }
        }
        
        void send(HTTPResponse* response) {
            if (connected) {
                cout << "Sent an HTTPResponse to the Application Layer" << endl;
                connectedApplicationLayer->recieve(response);
            }
            else {
                cout << "Transport Layer is not connected to a Application Layer" << endl;
            }
        }

        void send(HTTPRequest* request) {
            if (connected) {
                cout << "Sent an HTTPRequest to the Application Layer" << endl;
                connectedApplicationLayer->recieve(request);
            }
            else {
                cout << "Transport Layer is not connected to a Application Layer" << endl;
            }
        }

        void recieve(TCPSegment* segment) {
            cout << "Recieved a TCPSegment from the network layer" << endl;
            applicationLayer->recieve(segment->getPayload());
            delete segment;
        }

        void recieve(HTTPRequest* request) {
            cout << "Recieved an HTTPRequest in the buffer" << endl;
            HTTPbuffer.push(request);
        }

        void recieve(HTTPResponse* response) {
            cout << "Recieved an HTTPResponse in the buffer" << endl;
            HTTPbuffer.push(response);
        }

        void serve() {
            if (HTTPbuffer.size() > 0) {
                TCPSegment* segment = new TCPSegment(HTTPbuffer.front());
                HTTPbuffer.pop();
                cout << "Served an item from the buffer" << endl;
                send(segment);
            }
            else {
                cout << "HTTP buffer is empty" << endl;
            }
        }

}