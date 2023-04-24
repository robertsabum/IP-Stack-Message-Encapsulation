#ifndef PHYSICALLAYER_H
#define PHYSICALLAYER_H

#include <iostream>
using namespace std;

class PhysicalLayer {
    private:
        string id:
        string protocol;
        unsigned char* sourceAddress;
        unsigned char* destinationAddress;
        

    public:
        PhysicalLayer(string id, unsigned char* sourceAddress, unsigned char* destinationAddress) {
            this->id = id;
            this->protocol = "802.3";   // 10BASE-T Ethernet
            this->sourceAddress = sourceAddress;
            this->destinationAddress = destinationAddress;
        }

        ~PhysicalLayer() {

        }

        string getId() {
            return id;
        }

        string getProtocol() {
            return protocol;
        }

        unsigned char* getSourceAddress() {
            return sourceAddress;
        }

        unsigned char* getDestinationAddress() {
            return destinationAddress;
        }


        void sendFrame(EthernetFrame frame) {
            frame.setSourceAddress(sourceAddress);
            frame.setDestinationAddress(destinationAddress);
        }

        void receiveFrame(EthernetFrame frame) {
    
        }
};