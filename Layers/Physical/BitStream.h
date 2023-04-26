#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <string>
#include <vector>
#include "../DataLink/EthernetFrame.h"

using namespace std;

class BitStream{
    private:
        vector<bool> bits;
        EthernetFrame* frame;

    public:
        BitStream(EthernetFrame* frame) {
            this->frame = frame;
            this->bits = vector<bool>();
        }

        ~BitStream() {
            if (this->frame != NULL){
                delete this->frame;
            }
        }

        void setBits(vector<bool> bits) {
            this->bits = bits;
        }

        vector<bool> getBits() {
            return this->bits;
        }

        void setEthernetFrame(EthernetFrame* frame) {
            this->frame = frame;
        }

        EthernetFrame* getEthernetFrame() {
            return this->frame;
        }
};

#endif