#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <string>
#include <vector>
#include "../DataLink/EthernetFrame.h"

using namespace std;

class BitStream{
    private:
        EthernetFrame* frame;

    public:
        BitStream(EthernetFrame* frame) {
            this->frame = frame;
        }

        ~BitStream() {
            if (this->frame != NULL){
                delete this->frame;
            }
        }

        void setEthernetFrame(EthernetFrame* frame) {
            this->frame = frame;
        }

        EthernetFrame* getEthernetFrame() {
            return this->frame;
        }

        void writeToFile(){
            // write object to file in binary mode
            ofstream outfile;
            outfile.open("bitstream.bin", ios::out | ios::binary);
            outfile.write((char *)this, sizeof(*this));
            outfile.close();
        }
};

#endif