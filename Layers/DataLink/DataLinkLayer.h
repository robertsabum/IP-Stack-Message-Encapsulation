#ifndef DATALINKLAYER_H
#define DATALINKLAYER_H

#include <iostream>
#include "../Network/NetworkLayer.h"
#include "../Physical/PhysicalLayer.h"
#include "EthernetFrame.h"
#include "../Network/IPv4Packet.h"
#include "../Physical/BitStream.h"
#include <queue>

using namespace std;

class DataLinkLayer{
    private:
        queue<IPv4Packet*> IPv4buffer;
        NetworkLayer* networkLayer;
        PhysicalLayer* physicalLayer;

    public:
        DataLinkLayer() {
            this->networkLayer = NULL;
            this->physicalLayer = NULL;
        }

        ~DataLinkLayer() {
            if (this->networkLayer != NULL){
                this->networkLayer->disconnect(this);
            }
            if (this->physicalLayer != NULL){
                disconnect(this->physicalLayer);
            }
            
        }

        void connect(NetworkLayer* networkLayer) {
            this->networkLayer = networkLayer;
        }

        void connect(PhysicalLayer* physicalLayer) {
            this->physicalLayer = physicalLayer;
            this->physicalLayer->connect(this);
        }

        void disconnect(NetworkLayer* networkLayer) {
            this->networkLayer = NULL;
        }

        void disconnect(PhysicalLayer* physicalLayer) {
            this->physicalLayer = NULL;
            this->physicalLayer->disconnect(this);
        }

        void send(EthernetFrame* frame) {
            if (physicalLayer != NULL) {
                cout << "Sent an Ethernet Frame to the Physical Layer" << endl;
                physicalLayer->recieve(frame);
            }
            else {
                cout << "Data Link Layer is not connected to a Physical Layer" << endl;
            }
        }

        void send(IPv4Packet* packet) {
            if (networkLayer != NULL) {
                cout << "Sent an IPv4 Packet to the Network Layer" << endl;
                networkLayer->recieve(packet);
            }
            else {
                cout << "Data Link Layer is not connected to a Network Layer" << endl;
            }
        }

        void recieve(EthernetFrame* frame) {
                cout << "Recieved an Ethernet Frame from the Physical Layer" << endl;
                IPv4Packet* packet = frame->getPacket();
                delete frame; 
                networkLayer->send(packet);
        }

        void recieve(IPv4Packet* packet) {
            cout << "Recieved an IPv4 Packet from the Network Layer" << endl;
            IPv4buffer.push(packet);
            serve();
        }

        void serve() {
            if (IPv4buffer.size() > 0) {
                IPv4Packet* packet = IPv4buffer.front();
                IPv4buffer.pop();
                EthernetFrame* frame = new EthernetFrame(packet);
                cout << "Served item from buffer" << endl;
                send(packet);
            }
            else{
                cout << "IPv4 Buffer is empty" << endl;
            }
        }
};

#endif