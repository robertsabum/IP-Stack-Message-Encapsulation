#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include "../Network/IPv4Packet.h"
using namespace std;

class EthernetFrame
{
private:
    IPv4Packet *packet;
    unsigned char preamble[7];           // 7 bytes for the preamble
    unsigned char startFrameDelimiter;   // 1 byte for the start frame delimiter
    unsigned char destinationAddress[6]; // 6 bytes for the destination address
    unsigned char sourceAddress[6];      // 6 bytes for the source address
    unsigned char type[2];               // 2 bytes for the type
    unsigned char data[1500];            // 1500 bytes for the data
    unsigned char frameCheckSequence[4]; // 4 bytes for the frame check sequence
    unsigned char interFrameGap[12];     // 12 bytes for the interframe gap

public:
    EthernetFrame(IPv4Packet *packet)
    {
        this->packet = packet;

        for (int i = 0; i < 7; i++)
        {
            this->preamble[i] = 0;
        }

        this->startFrameDelimiter = 0;

        for (int i = 0; i < 6; i++)
        {
            this->destinationAddress[i] = 0;
            this->sourceAddress[i] = 0;
        }
        for (int i = 0; i < 2; i++)
        {
            this->type[i] = 0;
        }
        for (int i = 0; i < 1500; i++)
        {
            this->data[i] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            this->frameCheckSequence[i] = 0;
        }
        for (int i = 0; i < 12; i++)
        {
            this->interFrameGap[i] = 0;
        }
    }

    ~EthernetFrame()
    {
    }

    void setPreamble(unsigned char *preamble)
    {
        for (int i = 0; i < 7; i++)
        {
            this->preamble[i] = preamble[i];
        }
    }

    void setStartFrameDelimiter(unsigned char startFrameDelimiter)
    {
        this->startFrameDelimiter = startFrameDelimiter;
    }

    void setDestinationAddress(unsigned char *destinationAddress)
    {
        for (int i = 0; i < 6; i++)
        {
            this->destinationAddress[i] = destinationAddress[i];
        }
    }

    void setSourceAddress(unsigned char *sourceAddress)
    {
        for (int i = 0; i < 6; i++)
        {
            this->sourceAddress[i] = sourceAddress[i];
        }
    }

    void setType(unsigned char *type)
    {
        for (int i = 0; i < 2; i++)
        {
            this->type[i] = type[i];
        }
    }

    void setData(unsigned char *data)
    {
        for (int i = 0; i < 1500; i++)
        {
            this->data[i] = data[i];
        }
    }

    void setFrameCheckSequence(unsigned char *frameCheckSequence)
    {
        for (int i = 0; i < 4; i++)
        {
            this->frameCheckSequence[i] = frameCheckSequence[i];
        }
    }

    void setInterFrameGap(unsigned char *interFrameGap)
    {
        for (int i = 0; i < 12; i++)
        {
            this->interFrameGap[i] = interFrameGap[i];
        }
    }

    void setPacket(IPv4Packet *packet)
    {
        this->packet = packet;
    }

    unsigned char *getPreamble()
    {
        return this->preamble;
    }

    unsigned char getStartFrameDelimiter()
    {
        return this->startFrameDelimiter;
    }

    unsigned char *getDestinationAddress()
    {
        return this->destinationAddress;
    }

    unsigned char *getSourceAddress()
    {
        return this->sourceAddress;
    }

    unsigned char *getType()
    {
        return this->type;
    }

    unsigned char *getData()
    {
        return this->data;
    }

    unsigned char *getFrameCheckSequence()
    {
        return this->frameCheckSequence;
    }

    unsigned char *getInterFrameGap()
    {
        return this->interFrameGap;
    }

    IPv4Packet *getPacket()
    {
        return this->packet;
    }
};

#endif