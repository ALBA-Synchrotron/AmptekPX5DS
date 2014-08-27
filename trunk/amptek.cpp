#include "amptek.h"
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <iostream> 
#include <semaphore.h>



sem_t mu;
AmptekCommHandler::AmptekCommHandler(const char* hostname,
                                     int port,
                                     double timeout,
                                     Tango::DeviceImpl* device): Tango::LogAdapter(device)
{
 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        stringstream ss;
        ss << "Error opening socket: " << strerror(errno);
        AmptekException e = AmptekException(ss.str());
        throw e;
    }

    server.sin_family = AF_INET;
    host = gethostbyname(hostname);
    if (host==NULL)
    {
        stringstream ss;
        ss << "Error opening socket: host " << hostname << "does not exist";
        AmptekException e = AmptekException(ss.str());
        throw e;
    }

    bcopy((char *)host->h_addr,
        (char *)&server.sin_addr,
         host->h_length);
    server.sin_port = htons(port);
    length=sizeof(struct sockaddr_in);

    //setting up a timeout for receiving
    if (timeout < 0)
        throw AmptekException("Error opening socket: timeout value mas be greater than 0");
    int seconds = floor(timeout);
    int useconds = floor((timeout - seconds) * 1e6);
    struct timeval tv;
    tv.tv_sec = seconds;
    tv.tv_usec = useconds;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));
    sem_init(&mu, 0, 1);
}

AmptekCommHandler::~AmptekCommHandler()
{
    close(sockfd);
}

void AmptekCommHandler::send(Packet* requestPacket)
{
    int n=sendto(sockfd, &(requestPacket->at(0)), requestPacket->size(), 0, (const struct sockaddr *)&server, length);
    if (n <= 0)
    {
        AmptekException e = AmptekException();
        stringstream ss;
        if (n == 0)
            ss << "Error writing to the socket. " << n << " bytes have been sent.";
        else
            ss << "Error writing to the socket. " << strerror(errno);
        e.setDescription(ss.str());
        throw e;
    }
}

void AmptekCommHandler::receive(Packet* responsePacket)
{
    byte response[MAX_PACKET_LEN];
    bzero(response,MAX_PACKET_LEN);
    int n = recvfrom(sockfd, &response, MAX_PACKET_LEN, 0, (struct sockaddr *)&from, &length);

    DEBUG_STREAM << "AmptekCommHandler::receive(): received " << n << " bytes: " << endl;
    stringstream charResponse;
     for (int i = 0; i < n; i++)
         charResponse << "response[" << dec << i << "] = " << hex << (short)response[i] << endl;
    DEBUG_STREAM << charResponse.str();

    if (n <= 0)
    {
        stringstream ss;
        ss << "Error reading from the socket. " << n << " bytes have been received.";
        AmptekException e = AmptekException(ss.str());
        throw e;
    }
    responsePacket->fromByteArray(response);
}

void AmptekCommHandler::clearInputBuffer()
{
    byte response[MAX_PACKET_LEN];
    bzero(response,MAX_PACKET_LEN);
    int n;
    do
    {
        n = recvfrom(sockfd, &response, MAX_PACKET_LEN, 0, (struct sockaddr *)&from, &length);
        DEBUG_STREAM << "AmptekCommHandler::clearInputBuffer(): received " << n << " bytes: " << endl;
        stringstream charResponse;
        for (int i = 0; i < n; i++)
            charResponse << "buffer[" << dec << i << "] = " << hex << (short)response[i] << endl;
        DEBUG_STREAM << charResponse.str();
    }
    while(n > 0);
}


void AmptekCommHandler::receiveSpectrum(Packet* responsePacket)
{   sem_wait(&mu);
    byte response[MAX_PACKET_LEN];
    bzero(response,MAX_PACKET_LEN);
    int n = recvfrom(sockfd, &response, MAX_PACKET_LEN, 0, (struct sockaddr *)&from, &length);
    if (n <= 0)
    {
        stringstream ss;
        ss << "Error reading from the socket. " << n << " bytes have been received.";
        AmptekException e = AmptekException(ss.str());
        throw e;
    }
    responsePacket->at(PID1)    = response[PID1];
    responsePacket->at(PID2)    = response[PID2];

    word16 dataLength  = mergeBytes(response[LEN_MSB], response[LEN_LSB]);
    vector<byte> dataVector;
    dataVector.insert(dataVector.begin(), response+DATA, response+MAX_PACKET_LEN);

    unsigned short nrOfPackets;
    switch(dataLength)
    {
        case SIZE_256:
            nrOfPackets = PACKETS_256;
            break;
        case SIZE_512:
            nrOfPackets = PACKETS_512;
            break;
        case SIZE_1024:
            nrOfPackets = PACKETS_1024;
            break;
        case SIZE_2048:
            nrOfPackets = PACKETS_2048;
            break;
        case SIZE_4096:
            nrOfPackets = PACKETS_4096;
            break;
        case SIZE_8192:
            nrOfPackets = PACKETS_8192;
            break;
        default:
            stringstream ss;
            ss << "Received data length: " << dataLength << " does not correspond to any valid value.";
            AmptekException e = AmptekException(ss.str());
            throw e;
    }

    for(short i = 1; i < nrOfPackets; i++)
    {
        bzero(response,MAX_PACKET_LEN);
        int n = recvfrom(sockfd, &response, MAX_PACKET_LEN, 0, (struct sockaddr *)&from, &length);

        if (n <= 0)
        {
            stringstream ss;
            ss << "Error reading from the socket. " << n << " bytes have been received.";
            AmptekException e = AmptekException(ss.str());
            throw e;
        }

        if(i != nrOfPackets - 1)
            dataVector.insert(dataVector.end(), response, response+MAX_PACKET_LEN);
        else
        {
            int missingData = dataLength - dataVector.size();
            dataVector.insert(dataVector.end(), response, response+missingData);
            responsePacket->setData(&(dataVector.at(0)), dataLength);
            responsePacket->push_back(response[missingData]);   //appending Checksum MSB
            responsePacket->push_back(response[missingData+1]); //appending Checksum LSB
        }
    }
   sem_post(&mu);

}

void AmptekCommHandler::acknowledge(Packet* responsePacket)
{
    receive(responsePacket);
    AmptekException e;
    if(responsePacket->at(PID1) == ACK)
    {
        switch(responsePacket->at(PID2))
        {
            case OK:
            case OK_FPGA_UPLOAD_ADDR:
            case OK_INTERFACE_SHERING_REQUEST:
                break;
            case SYNC_ERR:
                e.setDescription("Sync bytes in Request Packet were not correct, \
                                                     and therefore, the Request Packet was rejected.");
                throw e;
                break;
            case PID_ERR:
                e.setDescription("PID1 & PID2 combination is not recognized as a valid \
                                                     Request Packet, and therefore, the Request Packet was rejected.");
                throw e;
                break;
            case LEN_ERR:
                e.setDescription("LEN field of the Request Packet was not consistent with \
                                                     Request Packet type defined by the PID1 & PID2 combination. \
                                                     It is not recognized as a valid Request Packet, \
                                                     and therefore, the Request Packet was rejected.");
                throw e;
                break;
            case CHECKSUM_ERR:
                e.setDescription("Checksum of the Request Packet was incorrect, \
                                                     and therefore, the Request Packet was rejected.");
                throw e;
                break;
            case BAD_PARAM:
                e.setDescription("Bad parameter.");
                throw e;
                break;
            case BAD_HEX:
                e.setDescription("Microcontroller or FPGA upload packets error: \
                                                     hex record contained in the data field \
                                                     of the Request Packet had a checksum or other structural error.");
                throw e;
                break;
            case UNRECOGNIZED_CMD:
                e.setDescription("Unrecognized command.");
                throw e;
                break;
            case FPGA_ERR:
                e.setDescription("FPGA initialization failed.");
                throw e;
                break;
            case CP2201_NOT_FOUND:
                e.setDescription("Set Ethernet Settings Request Packet was received, \
                                                     but an Ethernet controller was not detected on the DP5.");
                throw e;
                break;
            case SCOPED_DATA_NOT_AVAILABLE:
                e.setDescription("Send Scope Data Request Packet was received, \
                                                     but the digital oscilloscope hasn’t triggered, \
                                                     so no data is available. [The digital oscilloscope must be armed, \
                                                     and then a trigger must occur for data to be available.]");
                throw e;
                break;
            case PC5_NOT_PRESENT:
                e.setDescription("ASCII command errors – the data field will contain the \
                                                     ASCII command and parameter which caused the error. “Bad Parameter” \
                                                     means that the parameter isn’t recognized \
                                                     or exceeds the range of the command. “Unrecognized Command” \
                                                     means that the 4-character command isn’t recognized. \
                                                     “PC5 Not Present” is returned if a PC5 is not mated to the DP5, \
                                                     and a command requiring a PC5 is sent. (i.e. “HVSE”, Set High \
                                                     Voltage.) [A ‘Bad Parameter’ ACK packet may also be returned \
                                                     for a malformed I2C Request Packet, in which case LEN=0.] \
                                                     If an incomplete or garbled command is returned in the data field, \
                                                     it may mean that the ASCII Configuration Packet has structural \
                                                     issues. (Disallowed whitespace, missing semicolon, etc.)");
                throw e;
                break;
            case BUSY:
                e.setDescription("Busy, another interface in use.");
                throw e;
                break;
            case I2C_ERR:
                e.setDescription("‘I2C Transfer’ Request Packet, but no I2C ACK \
                                                     was detected from an I2C Slave.");
                throw e;
                break;
            case NOT_SUPPORTED:
                e.setDescription("Request Packet has been recognized as valid by the firmware, \
                                                     but it is not supported by the installed FPGA version. \
                                                     Update the FPGA to the latest FP version.");
                throw e;
                break;
            default:
                e.setDescription("Not recognized PID2 of the Acknowledge Package.");
                throw e;
                break;
        }
    }
    else
    {
        e.setDescription("Response Package was not an Acknowledge.");
        throw e;
    }
}

void AmptekCommHandler::sendWithReceive(Packet* requestPacket, Packet* responsePacket, int nrOfUdpAttempts)
{
    sem_wait(&mu);
    int missingAttempts = nrOfUdpAttempts;
    while(true)
    {
        try
        {
            this->send(requestPacket);
            this->receive(responsePacket);
            break;
        }
        catch(AmptekException& e)
        {
            WARN_STREAM << "AmptekCommHandler::sendWithReceive(): " << e.description().c_str() << endl;
            if (missingAttempts == 0)
            {
                stringstream ss;
                ss << "Communication error. It was not able to succeed within " << nrOfUdpAttempts << " attempts.";
                AmptekException e = AmptekException(ss.str());
                throw e;
            }
            else
                missingAttempts--;
        }
    }
   sem_post(&mu);
}

void AmptekCommHandler::sendWithReceiveSpectrum(Packet* requestPacket, Packet* responsePacket, int nrOfUdpAttempts)
{
    int missingAttempts = nrOfUdpAttempts;
    while(true)
    {
        try
        {
            this->send(requestPacket);
            this->receiveSpectrum(responsePacket);
            break;
        }
        catch(AmptekException& e)
        {
            WARN_STREAM << "AmptekCommHandler::sendWithReceiveSpectrum(): " << e.description().c_str() << endl;
            if (missingAttempts == 0)
            {
                stringstream ss;
                ss << "AmptekCommHandler::sendWithReceiveSpectrum(): Communication error. \
                       It was not able to succeed within " << nrOfUdpAttempts << " attempts.";
                AmptekException e = AmptekException(ss.str());
                throw e;
            }
            else
                missingAttempts--;
        }
    }
}

bool interpretAcknowledge(Packet* responsePacket, stringstream* description)
{ 
    bool ackOK = false;
    if(responsePacket->at(PID1) == ACK)
    {
        switch(responsePacket->at(PID2))
        {
            case OK:
                (*description) << "OK";
                ackOK = true;
                break;
            case OK_FPGA_UPLOAD_ADDR:
                (*description) << "OK, FPGA uplad address";
                ackOK = true;
                break;
            case OK_INTERFACE_SHERING_REQUEST:
                (*description) << "OK, with interface sharing request";
                ackOK = true;
                break;
            case SYNC_ERR:
                (*description) << "Sync bytes in Request Packet were not correct, \
                                                     and therefore, the Request Packet was rejected.";
                break;
            case PID_ERR:
                (*description) << "PID1 & PID2 combination is not recognized as a valid \
                                                     Request Packet, and therefore, the Request Packet was rejected.";
                break;
            case LEN_ERR:
                (*description) << "LEN field of the Request Packet was not consistent with \
                                                     Request Packet type defined by the PID1 & PID2 combination. \
                                                     It is not recognized as a valid Request Packet, \
                                                     and therefore, the Request Packet was rejected.";
                break;
            case CHECKSUM_ERR:
                (*description) << "Checksum of the Request Packet was incorrect, \
                                                     and therefore, the Request Packet was rejected.";
                break;
            case BAD_PARAM:
                (*description) << "Bad parameter.";
                break;
            case BAD_HEX:
                (*description) <<"Microcontroller or FPGA upload packets error: \
                                                     hex record contained in the data field \
                                                     of the Request Packet had a checksum or other structural error.";
                break;
            case UNRECOGNIZED_CMD:
                (*description) << "Unrecognized command.";
                break;
            case FPGA_ERR:
                (*description) << "FPGA initialization failed.";
                break;
            case CP2201_NOT_FOUND:
                (*description) << "Set Ethernet Settings Request Packet was received, \
                                                     but an Ethernet controller was not detected on the DP5.";
                break;
            case SCOPED_DATA_NOT_AVAILABLE:
                (*description) << "Send Scope Data Request Packet was received, \
                                                     but the digital oscilloscope hasn’t triggered, \
                                                     so no data is available. [The digital oscilloscope must be armed, \
                                                     and then a trigger must occur for data to be available.]";
                break;
            case PC5_NOT_PRESENT:
                (*description) << "ASCII command errors – the data field will contain the \
                                                     ASCII command and parameter which caused the error. “Bad Parameter” \
                                                     means that the parameter isn’t recognized \
                                                     or exceeds the range of the command. “Unrecognized Command” \
                                                     means that the 4-character command isn’t recognized. \
                                                     “PC5 Not Present” is returned if a PC5 is not mated to the DP5, \
                                                     and a command requiring a PC5 is sent. (i.e. “HVSE”, Set High \
                                                     Voltage.) [A ‘Bad Parameter’ ACK packet may also be returned \
                                                     for a malformed I2C Request Packet, in which case LEN=0.] \
                                                     If an incomplete or garbled command is returned in the data field, \
                                                     it may mean that the ASCII Configuration Packet has structural \
                                                     issues. (Disallowed whitespace, missing semicolon, etc.)";
                break;
            case BUSY:
                (*description) << "Busy, another interface in use.";
                break;
            case I2C_ERR:
                (*description) << "‘I2C Transfer’ Request Packet, but no I2C ACK \
                                                     was detected from an I2C Slave.";
                break;
            case NOT_SUPPORTED:
                (*description) << "Request Packet has been recognized as valid by the firmware, \
                                                     but it is not supported by the installed FPGA version. \
                                                     Update the FPGA to the latest FP version.";
                break;
            default:
                (*description) << "Not recognized PID2 of the Acknowledge Package.";
                break;
        }
    }
    else
    {
        (*description) << "Response Package was not an Acknowledge.";
    }
    return ackOK;
}
