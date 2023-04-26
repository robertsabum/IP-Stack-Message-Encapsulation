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
        TransportLayer* TransportLayer;
        DataLinkLayer* DataLinkLayer;

    public:
        NetworkLayer() {
            this->TransportLayer = NULL;
            this->DataLinkLayer = NULL;
        }

        ~NetworkLayer() {
            if (this->TransportLayer != NULL){
                this->TransportLayer->disconnect(this);
            }
            if (this->DataLinkLayer != NULL){
                disconnect(this->DataLinkLayer);
            }
        }

        void connect(TransportLayer* TransportLayer) {
            this->TransportLayer = TransportLayer;
        }

        void connect(DataLinkLayer* DataLinkLayer) {
            this->DataLinkLayer = DataLinkLayer;
            this->DataLinkLayer->connect(this);
        }

        void disconnect(TransportLayer* TransportLayer) {
            this->TransportLayer = NULL;
        }

        void disconnect(DataLinkLayer* DataLinkLayer) {
            this->DataLinkLayer = NULL;
            this->DataLinkLayer->disconnect(this);
        }

        void send(IPv4Packet* packet) {
            if (DataLinkLayer != NULL) {
                cout << "Sent an IPv4 Packet to the Data Link Layer" << endl;
                DataLinkLayer->recieve(packet);
            }
            else {
                cout << "Network Layer is not connected to a Data Link Layer" << endl;
            }
        }

        void send(TCPSegment* segment) {
            if (TransportLayer != NULL) {
                cout << "Sent a TCP Segment to the Transport Layer" << endl;
                TransportLayer->recieve(segment);
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
            TCPbuffer.push(segment);
            serve();
        }

        void serve() {
            if (TCPbuffer.size() > 0) {
                TCPSegment* segment = TCPbuffer.front();
                TCPbuffer.pop();
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