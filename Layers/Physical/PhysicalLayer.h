#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include <iostream>
#include "../DataLink/EthernetFrame.h"
#include "../DataLink/DataLinkLayer.h"
#include "BitStream.h"
#include <queue>
using namespace std;

class PhysicalLayer {
    private:
        queue<EthernetFrame*> Ethernetbuffer;
        PhysicalLayer* physicalLayer;
        DataLinkLayer* dataLinkLayer;
        

    public:
        PhysicalLayer() {
            this->physicalLayer = NULL;
            this->dataLinkLayer = NULL;
        }

        ~PhysicalLayer() {
            if (this->physicalLayer != NULL){
                this->physicalLayer->disconnect(this);
            }
            if (this->dataLinkLayer != NULL){
                this->dataLinkLayer->disconnect(this);
            }
        }

        void connect(PhysicalLayer* physicalLayer) {
            this->physicalLayer = physicalLayer;
        }

        void connect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = dataLinkLayer;
        }

        void disconnect(PhysicalLayer* physicalLayer) {
            this->physicalLayer = NULL;
        }

        void disconnect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = NULL;
        }

        void send(EthernetFrame* frame) {
            if (this->dataLinkLayer != NULL) {
                cout << "Sent an Ethernet Frame to the Data Link Layer" << endl;
                this->dataLinkLayer->receive(frame);
            }
            else {
                cout << "Physical Layer is not connected to a Data Link Layer" << endl;
            }
        }

        void send(BitStream* bitstream) {
            if (this->physicalLayer != NULL) {
                cout << "Sent a Bitstream to the Physical Layer" << endl;
                this->physicalLayer->receive(bitstream);
            }
            else {
                cout << "Physical Layer is not connected to a Physical Layer" << endl;
            }
        }

        void receive(EthernetFrame* frame) {
            cout << "Received an Ethernet Frame from the Physical Layer" << endl;
            Ethernetbuffer.push(frame);
            serve();
        }

        void receive(BitStream* bitstream) {
            cout << "Received a Bitstream from the Physical Layer" << endl;
            EthernetFrame* frame = bitstream->getEthernetFrame();
            delete bitstream;
            send(frame);
        }

        void serve() {
            if (Ethernetbuffer.size() > 0) {
                EthernetFrame* frame = Ethernetbuffer.front();
                Ethernetbuffer.pop();
                BitStream* bitstream = new BitStream(frame);
                send(bitstream);
                cout << "Served an item from the buffer" << endl;
            }
            else {
                cout << "Ethernet Buffer is empty" << endl;
            }
        }
};

#endif