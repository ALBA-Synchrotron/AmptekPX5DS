#ifndef PACKET_H
#define PACKET_H

#include <vector>
#include <string>
#include <sstream>
#include "types.h"

#define MIN_PACKET_LEN 8
#define MAX_PACKET_LEN 520

using namespace std;

enum Offset 
{
    SYNC1,
    SYNC2,
    PID1,
    PID2,
    LEN_MSB,
    LEN_LSB,
    DATA
};

class AmptekException
{
    string d;
public:
    AmptekException(){ }
    AmptekException(string d): d(d) { }
    string description() {return d;}
    void setDescription(string descr){d = descr;}
};


class Packet: public vector<byte>
{
    friend class vector;
    vector<byte>::iterator it;

public:
    Packet();
    Packet(unsigned short initSize);
    word16 dataLength;
    void initSync();
    void setPid1(byte p1);
    void setPid2(byte p2);
    word16 calcLen();
    word16 calcChecksum();
    void calcAndFillChecksum();
    void validateChecksum();
    void setData(byte* data, word16 size);
    string toString();
    void fromByteArray(byte* response);
};

#endif
