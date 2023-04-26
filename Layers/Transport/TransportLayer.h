#ifndef TRANSPORTLAYER_H
#define TRANSPORTLAYER_H

#include <iostream>
#include "../Application/ApplicationLayer.h"
#include "../Network/NetworkLayer.h"
#include "HTTPMessage.h"
#include "TCPSegment.h"
#include <queue>
using namespace std;

class TransportLayer {
    private:
        queue<HTTPMessage*> HTTPbuffer;
        ApplicationLayer* applicationLayer;
        NetworkLayer* networkLayer;

    public:
        transportLayer() {
            this->applicationLayer = NULL;
            this->networkLayer = NULL;
        }

        ~transportLayer() {
            if (this->applicationLayer != NULL) {
                this->applicationLayer->disconnect(this);
            }
            if (this->networkLayer != NULL) {
                disconnect(this->networkLayer);
            }
        }

        void connect(ApplicationLayer* applicationLayer) {
            this->applicationLayer = applicationLayer;
        }

        void connect(NetworkLayer* networkLayer) {
            this->networkLayer = networkLayer;
            networkLayer->connect(this);
        }

        void disconnect(ApplicationLayer* applicationLayer) {
            this->applicationLayer = NULL;
        }

        void disconnect(NetworkLayer* networkLayer) {
            this->networkLayer = NULL;
            networkLayer->disconnect(this);
        }

        bool isConnected() {
            return (applicationLayer != NULL && networkLayer != NULL)
        }

        void send(TCPSegment* segment) {
            if (isConnected()) {
                cout << "Sent a TCP Segment to the Network Layer" << endl;
                networkLayer->recieve(segment);
            }
            else {
                cout << "Transport Layer is not connected" << endl;
            }
        }

        void send(HTTPMessage* message) {
            if (isConnected()) {
                cout << "Sent an HTTPMessage to the Application Layer" << endl;
                applicationLayer->recieve(message);
            }
            else {
                cout << "Transport Layer is not connected" << endl;
            }
        }

        void recieve(TCPSegment* segment) {
            cout << "Recieved a TCPSegment from the Network Layer" << endl;
            HTTPMessage* message = segment->getHTTPMessage();
            delete segment;
            send(message);
            }

        void recieve(HTTPMessage* message) {
            cout << "Recieved an HTTPMessage from the Application Layer" << endl;
            HTTPbuffer.push(message);
            serve();
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

};

#endif