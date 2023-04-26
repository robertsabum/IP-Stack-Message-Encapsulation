#ifndef IPV4PACKET_H
#define IPV4PACKET_H

#include <iostream>
#include "../Transport/TCPSegment.h"
using namespace std;

class IPv4Packet{
    private:
        uint8_t version;
        uint8_t IHL;
        uint8_t DSCP;
        uint8_t ECN;
        uint16_t totalLength;
        uint16_t identification;
        uint8_t flags;
        uint16_t fragmentOffset;
        uint8_t TTL;
        uint8_t protocol;
        uint16_t headerChecksum;
        uint32_t sourceAddress;
        uint32_t destinationAddress;
        unsigned char* options;
        TCPSegment* segment;

    public:
        IPv4Packet(TCPSegment* segment, uint32_t sourceAddress) {
            this->segment = segment;
            this->version = 4;
            this->IHL = 5;
            this->DSCP = 0;
            this->ECN = 0;
            this->totalLength = 0;
            this->identification = 0;
            this->flags = 0;
            this->fragmentOffset = 0;
            this->TTL = 0;
            this->protocol = 6;
            this->headerChecksum = 0;
            this->sourceAddress = sourceAddress;
            this->destinationAddress = rand() % 4294967295;
            this->options = NULL;
        }

        ~IPv4Packet() {

        }

        uint8_t getVersion() {
            return version;
        }

        uint8_t getIHL() {
            return IHL;
        }

        uint8_t getDSCP() {
            return DSCP;
        }

        uint8_t getECN() {
            return ECN;
        }

        uint16_t getTotalLength() {
            return totalLength;
        }

        uint16_t getIdentification() {
            return identification;
        }

        uint8_t getFlags() {
            return flags;
        }

        uint16_t getFragmentOffset() {
            return fragmentOffset;
        }

        uint8_t getTTL() {
            return TTL;
        }

        uint8_t getProtocol() {
            return protocol;
        }

        uint16_t getHeaderChecksum() {
            return headerChecksum;
        }

        uint32_t getSourceAddress() {
            return sourceAddress;
        }

        uint32_t getDestinationAddress() {
            return destinationAddress;
        }

        unsigned char* getOptions() {
            return options;
        }

        TCPSegment* getTCPSegment() {
            return segment;
        }

        void setVersion(uint8_t version) {
            this->version = version;
        }

        void setIHL(uint8_t IHL) {
            this->IHL = IHL;
        }

        void setDSCP(uint8_t DSCP) {
            this->DSCP = DSCP;
        }

        void setECN(uint8_t ECN) {
            this->ECN = ECN;
        }

        void setTotalLength(uint16_t totalLength) {
            this->totalLength = totalLength;
        }

        void setIdentification(uint16_t identification) {
            this->identification = identification;
        }

        void setFlags(uint8_t flags) {
            this->flags = flags;
        }

        void setFragmentOffset(uint16_t fragmentOffset) {
            this->fragmentOffset = fragmentOffset;
        }

        void setTTL(uint8_t TTL) {
            this->TTL = TTL;
        }

        void setProtocol(uint8_t protocol) {
            this->protocol = protocol;
        }

        void setHeaderChecksum(uint16_t headerChecksum) {
            this->headerChecksum = headerChecksum;
        }

        void setSourceAddress(uint32_t sourceAddress) {
            this->sourceAddress = sourceAddress;
        }

        void setDestinationAddress(uint32_t destinationAddress) {
            this->destinationAddress = destinationAddress;
        }

        void setOptions(unsigned char* options) {
            this->options = options;
        }

        void setTCPSegment(TCPSegment* segment) {
            this->segment = segment;
        }
};

#endif