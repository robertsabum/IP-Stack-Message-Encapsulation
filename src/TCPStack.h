#ifndef TCPSTACK_H
#define TCPSTACK_H

#include "../Layers/Application/ApplicationLayer.h"
#include "../Layers/Transport/TransportLayer.h"
#include "../Layers/Network/NetworkLayer.h"
#include "../Layers/DataLink/DataLinkLayer.h"
#include "../Layers/Physical/PhysicalLayer.h"
#include "../Layers/Application/HTTPMessage.h"
#include "../Layers/Physical/BitStream.h"
#include <iostream>
using namespace std;

class TCPStack
{
private:
	ApplicationLayer *applicationLayer;
	TransportLayer *transportLayer;
	NetworkLayer *networkLayer;
	DataLinkLayer *dataLinkLayer;
	PhysicalLayer *physicalLayer;

public:
	TCPStack()
	{
		this->applicationLayer = new ApplicationLayer();
		this->transportLayer = new TransportLayer();
		this->networkLayer = new NetworkLayer();
		this->dataLinkLayer = new DataLinkLayer();
		this->physicalLayer = new PhysicalLayer();
	}

	BitStream *send(HTTPMessage *message)
	{
		TCPSegment *segment = this->transportLayer->recieve(message);
		IPv4Packet *packet = this->networkLayer->recieve(segment);
		EthernetFrame *frame = this->dataLinkLayer->recieve(packet);
		BitStream *bits = this->physicalLayer->receive(frame);
		return bits;
	}

	void receive(BitStream *bits)
	{
		EthernetFrame *frame = this->physicalLayer->receive(bits);
		IPv4Packet *packet = this->dataLinkLayer->recieve(frame);
		TCPSegment *segment = this->networkLayer->recieve(packet);
		HTTPMessage *message = this->transportLayer->recieve(segment);
		this->applicationLayer->recieve(message);
	}
};

#endif
