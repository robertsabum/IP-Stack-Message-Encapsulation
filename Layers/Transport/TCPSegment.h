#ifndef TCPSEGMENT_H
#define TCPSEGMENT_H

#include <iostream>
#include <variant>
#include "../Application/HTTPRequest.h"
using namespace std;

class TCPSegment{
    private:
        uint16_t sourcePort;
        uint16_t destinationPort;
        uint32_t sequenceNumber;
        uint32_t acknowledgementNumber;
        uint8_t dataOffset;
        uint8_t flags;
        uint16_t windowSize;
        uint16_t checksum;
        uint16_t urgentPointer;
        unsigned char* options;
        variant<HTTPRequest*, HTTPResponse*> payload;

    public:
        TCPSegment(variant<HTTPRequest*, HTTPResponse*> payload) {
            this->payload = payload;
            this->sourcePort = rand() % 65535;
            this->destinationPort = rand() % 65535;
            this->sequenceNumber = rand() % 4294967295;
            this->acknowledgementNumber = 0;
            this->dataOffset = 0;
            this->flags = 0;
            this->windowSize = 0;
            this->checksum = 0;
            this->urgentPointer = 0;
            this->options = NULL;
        }

        ~TCPSegment() {

        }

        uint16_t getSourcePort() {
            return sourcePort;
        }

        uint16_t getDestinationPort() {
            return destinationPort;
        }

        uint32_t getSequenceNumber() {
            return sequenceNumber;
        }

        uint32_t getAcknowledgementNumber() {
            return acknowledgementNumber;
        }

        uint8_t getDataOffset() {
            return dataOffset;
        }

        uint8_t getFlags() {
            return flags;
        }

        uint16_t getWindowSize() {
            return windowSize;
        }

        uint16_t getChecksum() {
            return checksum;
        }

        uint16_t getUrgentPointer() {
            return urgentPointer;
        }

        unsigned char* getOptions() {
            return options;
        }

        HTTPRequest* getHTTPRequest() {
            return request;
        }

        void setSourcePort(uint16_t sourcePort) {
            this->sourcePort = sourcePort;
        }

        void setDestinationPort(uint16_t destinationPort) {
            this->destinationPort = destinationPort;
        }

        void setSequenceNumber(uint32_t sequenceNumber) {
            this->sequenceNumber = sequenceNumber;
        }

        void setAcknowledgementNumber(uint32_t acknowledgementNumber) {
            this->acknowledgementNumber = acknowledgementNumber;
        }

        void setDataOffset(uint8_t dataOffset) {
            this->dataOffset = dataOffset;
        }

        void setFlags(uint8_t flags) {
            this->flags = flags;
        }

        void setWindowSize(uint16_t windowSize) {
            this->windowSize = windowSize;
        }

        void setChecksum(uint16_t checksum) {
            this->checksum = checksum;
        }

        void setUrgentPointer(uint16_t urgentPointer) {
            this->urgentPointer = urgentPointer;
        }

        void setOptions(unsigned char* options) {
            this->options = options;
        }

        void setHTTPRequest(HTTPRequest* request) {
            this->request = request;
        }
};

#endif