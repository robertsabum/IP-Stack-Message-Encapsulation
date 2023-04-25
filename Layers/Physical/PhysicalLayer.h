#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include <iostream>
#include "../DataLink/EthernetFrame.h"
#include "../DataLink/DataLinkLayer.h"
using namespace std;

class PhysicalLayer {
    private:
        bool connected;
        PhysicalLayer* destinationPhysicalLayer;
        DataLinkLayer* sourceDataLinkLayer;
        

    public:
        PhysicalLayer(DataLinkLayer* sourceDataLinkLayer) {
            this->connected = false;
            this->sourceDataLinkLayer = sourceDataLinkLayer;
        }

        ~PhysicalLayer() {

        }

        void connect(PhysicalLayer* destinationPhysicalLayer) {
            this->destinationPhysicalLayer = destinationPhysicalLayer;
            this->connected = true;
        }

        void disconnect() {
            this->destinationPhysicalLayer = NULL;
            this->connected = false;
        }

        bool isConnected() {
            return connected;
        }

        void send(EthernetFrame* frame) {
            if (connected) {
                destinationPhysicalLayer->receive(frame);
            }
        }

        void receive(EthernetFrame* frame) {
            sourceDataLinkLayer->receive(frame);
        }
};

#endif