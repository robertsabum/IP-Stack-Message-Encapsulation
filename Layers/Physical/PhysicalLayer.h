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
                dataLinkLayer->disconnect(this);
            }
        }

        void connect(PhysicalLayer* physicalLayer) {
            this->physicalLayer = physicalLayer;
        }

        void connect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = dataLinkLayer;
        }

        void disconnect(physicalLayer* physicalLayer) {
            this->physicalLayer = NULL;
        }

        void disconnect(DataLinkLayer* dataLinkLayer) {
            this->dataLinkLayer = NULL;
        }

        void send(EthernetFrame* frame) {
            if (dataLinkLayer != NULL) {
                cout << "Sent an Ethernet Frame to the Data Link Layer" << endl;
                dataLinkLayer->receive(frame);
            }
            else {
                cout << "Physical Layer is not connected to a Data Link Layer" << endl;
            }
        }

        void send(Bitstream* bitstream) {
            if (physicalLayer != NULL) {
                cout << "Sent a Bitstream to the Physical Layer" << endl;
                physicalLayer->receive(bitstream);
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

        void receive(Bitstream* bitstream) {
            cout << "Received a Bitstream from the Physical Layer" << endl;
            EthernetFrame* frame = bitsream->getEthernetFrame();
            delete bitstream;
            send(frame);
        }

        void serve() {
            if (Ethernetbuffer.size() > 0) {
                EthernetFrame* frame = Ethernetbuffer.front();
                Ethernetbuffer.pop();
                Bitstream* bitstream = new Bitstream(frame);
                send(bitstream);
                cout << "Served an item from the buffer" << endl;
            }
            else {
                cout << "Ethernet Buffer is empty" << endl;
            }
        }
};

#endif