#ifndef AMPTEK_H
#define AMPTEK_H

#include <tango.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#include "packet.h"

enum PID1_VALUES{
ACK=0xFF
};

enum PID2_ACK_VALUES{
OK,
SYNC_ERR,
PID_ERR,
LEN_ERR,
CHECKSUM_ERR,
BAD_PARAM,
BAD_HEX,
UNRECOGNIZED_CMD,
FPGA_ERR,
CP2201_NOT_FOUND,
SCOPED_DATA_NOT_AVAILABLE,
PC5_NOT_PRESENT,
OK_INTERFACE_SHERING_REQUEST,
BUSY,
I2C_ERR,
OK_FPGA_UPLOAD_ADDR,
NOT_SUPPORTED
};

enum SPECTRUM_DATA_SIZE{
SIZE_256 = 768,
SIZE_512 = 1536,
SIZE_1024 = 3072,
SIZE_2048 = 6144,
SIZE_4096 = 12288,
SIZE_8192 = 24576,
};

enum SPECTRUM_DATA_PACKETS{
PACKETS_256 = 2,
PACKETS_512 = 3,
PACKETS_1024 = 6,
PACKETS_2048 = 12,
PACKETS_4096 = 24,
PACKETS_8192 = 48,
};

class AmptekCommHandler: public Tango::LogAdapter
{
    int sockfd;
    unsigned int length;
    struct sockaddr_in server, from;
    struct hostent *host;

public:
    AmptekCommHandler(Tango::DeviceImpl* device): Tango::LogAdapter(device) { };
    AmptekCommHandler(const char* hostname, int port, double timeout, Tango::DeviceImpl* device);
    ~AmptekCommHandler();
    void send(Packet* requestPacket);
    void receive(Packet* responsePacket);
    void clearInputBuffer();
    void receiveSpectrum(Packet* responsePacket);
    void acknowledge(Packet* responsePacket);
    void sendWithReceive(Packet* requestPacket, Packet* responsePacket, int nrOfUdpAttempts=3);
    void sendWithReceiveSpectrum(Packet* requestPacket, Packet* responsePacket, int nrOfUdpAttempts=3);
};

bool interpretAcknowledge(Packet* responsePacket, stringstream* description);

#endif