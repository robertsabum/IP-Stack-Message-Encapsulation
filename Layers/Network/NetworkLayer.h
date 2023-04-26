#ifndef NETWORKLAYER_H
#define NETWORKLAYER_H

#include <iostream>
#include "../Transport/TransportLayer.h"
#include "../DataLink/DataLinkLayer.h"
#include "IPv4Packet.h"
#include "../Transport/TCPSegment.h"
#include "../DataLink/EthernetFrame.h"
#include <queue>


using namespace std;


class NetworkLayer{
    private:
        queue<TCPSegment*> TCPbuffer;
        TransportLayer* transportLayer;
        DataLinkLayer* dataLinkLayer;

    public:
        NetworkLayer() {
            this->transportLayer = NULL;
            this->dataLinkLayer = NULL;
        }

        ~NetworkLayer() {
            if (this->transportLayer != NULL){
                this->transportLayer->disconnect(this);
            }
            if (this->dataLinkLayer != NULL){
                disconnect(this->dataLinkLayer);
            }
        }

        void connect(TransportLayer* transportLayer) {
            this->transportLayer = transportLayer;
        }

        void connect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = dataLinkLayer;
            this->dataLinkLayer->connect(this);
        }

        void disconnect(TransportLayer* transportLayer) {
            this->transportLayer = NULL;
        }

        void disconnect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = NULL;
            this->dataLinkLayer->disconnect(this);
        }

        void send(IPv4Packet* packet) {
            if (this->dataLinkLayer != NULL) {
                cout << "Sent an IPv4 Packet to the Data Link Layer" << endl;
                this->dataLinkLayer->recieve(packet);
            }
            else {
                cout << "Network Layer is not connected to a Data Link Layer" << endl;
            }
        }

        void send(TCPSegment* segment) {
            if (this->transportLayer != NULL) {
                cout << "Sent a TCP Segment to the Transport Layer" << endl;
                this->transportLayer->recieve(segment);
            }
            else {
                cout << "Network Layer is not connected to a Transport Layer" << endl;
            }
        }

        void recieve(IPv4Packet* packet) {
            cout << "Recieved an IPv4 Packet from the Data Link Layer" << endl;
            TCPSegment* segment = packet->getTCPSegment();
            delete packet;
            send(segment);
        }

        void recieve(TCPSegment* segment) {
            cout << "Recieved a TCP Segment from the Transport Layer" << endl;
            this->TCPbuffer.push(segment);
            serve();
        }

        void serve() {
            if (TCPbuffer.size() > 0) {
                TCPSegment* segment = this->TCPbuffer.front();
                this->TCPbuffer.pop();
                IPv4Packet* packet = new IPv4Packet(segment);
                cout << "Served item from buffer" << endl;
                send(packet);
            }
            else {
                cout << "TCP Buffer is empty" << endl;
            }
        }
};

#endif