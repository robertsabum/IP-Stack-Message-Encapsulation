#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <map>
using namespace std;

class HTTPRequest{
    private:
        string method;
        string url;
        string version;
        map<string, string> headers;
        string body;

    public:
        HTTPRequest(string method, string url, string version, map<string, string> headers, string body) {
            this->method = method;
            this->url = url;
            this->version = version;
            this->headers = headers;
            this->body = body;
        }

        ~HTTPRequest() {

        }

        string getMethod() {
            return method;
        }

        string getUrl() {
            return url;
        }

        string getVersion() {
            return version;
        }

        map<string, string> getHeaders() {
            return headers;
        }

        string getBody() {
            return body;
        }
}

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
        HTTPRequest* request;

    public:
        TCPSegment(HTTPRequest* request) {
            this->request = request;
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

class IPPacket{
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
        IPPacket(TCPSegment* segment, uint32_t sourceAddress) {
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

        ~IPPacket() {

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
}

class EthernetFrame {
    private:
        unsigned char preamble[7];              // 7 bytes for the preamble
        unsigned char startFrameDelimiter;      // 1 byte for the start frame delimiter
        unsigned char destinationAddress[6];    // 6 bytes for the destination address
        unsigned char sourceAddress[6];         // 6 bytes for the source address
        unsigned char type[2];                  // 2 bytes for the type
        unsigned char data[1500];               // 1500 bytes for the data
        unsigned char frameCheckSequence[4];    // 4 bytes for the frame check sequence
        unsigned char interFrameGap[12];        // 12 bytes for the interframe gap


    public:
        EthernetFrame() {
            for (int i = 0; i < 7; i++) {
                preamble[i] = 0;
            }
            startFrameDelimiter = 0;
            for (int i = 0; i < 6; i++) {
                destinationAddress[i] = 0;
                sourceAddress[i] = 0;
            }
            for (int i = 0; i < 2; i++) {
                type[i] = 0;
            }
            for (int i = 0; i < 1500; i++) {
                data[i] = 0;
            }
            for (int i = 0; i < 4; i++) {
                frameCheckSequence[i] = 0;
            }
            for (int i = 0; i < 12; i++) {
                interFrameGap[i] = 0;
            }
        }

        ~EthernetFrame() {

        }

        void setPreamble(unsigned char* preamble) {
            for (int i = 0; i < 7; i++) {
                this->preamble[i] = preamble[i];
            }
        }

        void setStartFrameDelimiter(unsigned char startFrameDelimiter) {
            this->startFrameDelimiter = startFrameDelimiter;
        }

        void setDestinationAddress(unsigned char* destinationAddress) {
            for (int i = 0; i < 6; i++) {
                this->destinationAddress[i] = destinationAddress[i];
            }
        }

        void setSourceAddress(unsigned char* sourceAddress) {
            for (int i = 0; i < 6; i++) {
                this->sourceAddress[i] = sourceAddress[i];
            }
        }

        void setType(unsigned char* type) {
            for (int i = 0; i < 2; i++) {
                this->type[i] = type[i];
            }
        }

        void setData(unsigned char* data) {
            for (int i = 0; i < 1500; i++) {
                this->data[i] = data[i];
            }
        }

        void setFrameCheckSequence(unsigned char* frameCheckSequence) {
            for (int i = 0; i < 4; i++) {
                this->frameCheckSequence[i] = frameCheckSequence[i];
            }
        }

        void setInterFrameGap(unsigned char* interFrameGap) {
            for (int i = 0; i < 12; i++) {
                this->interFrameGap[i] = interFrameGap[i];
            }
        }

        unsigned char* getPreamble() {
            return preamble;
        }

        unsigned char getStartFrameDelimiter() {
            return startFrameDelimiter;
        }

        unsigned char* getDestinationAddress() {
            return destinationAddress;
        }

        unsigned char* getSourceAddress() {
            return sourceAddress;
        }

        unsigned char* getType() {
            return type;
        }

        unsigned char* getData() {
            return data;
        }

        unsigned char* getFrameCheckSequence() {
            return frameCheckSequence;
        }

        unsigned char* getInterFrameGap() {
            return interFrameGap;
        }
}


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

class DataLinkLayer {
    private:
        PhysicalLayer physicalLayer;
        vector<EthernetFrame> buffer;
        unsigned char* macAddress;

    public:
        DataLinkLayer(PhysicalLayer physicalLayer, unsigned char* macAddress) {
            this->physicalLayer = physicalLayer;
            this->macAddress = macAddress;
        }

        ~DataLinkLayer() {

        }

        void send(string destinationAddress, string data) {
            unsigned char* destAddr = new unsigned char[6];
            unsigned char* srcAddr = new unsigned char[6];
            unsigned char* dataBytes = new unsigned char[1500];

            // TODO: Convert destinationAddress to bytes
            // TODO: Generate sourceAddress randomly

            EthernetFrame frame(new unsigned char[7], 0xAB, destAddr, srcAddr, new unsigned char[2], dataBytes, new unsigned char[4], new unsigned char[12]);
            buffer.push_back(frame);

            if (buffer.size() == 1) {
                sendNextFrame();
            }
        }

        void sendNextFrame() {
            if (!buffer.empty()) {
                EthernetFrame frame = buffer.front();
                buffer.erase(buffer.begin());
                physicalLayer.sendFrame(frame);
            }
        }
};