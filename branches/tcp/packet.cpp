#include "packet.h"

Packet::Packet():vector<byte>(), dataLength(0)
{ }

Packet::Packet(unsigned short initSize):vector<byte>(initSize,0), dataLength(0)
{ }

void Packet::initSync()
{
    at(SYNC1) = 0XF5;
    at(SYNC2) = 0XFA;
}

void Packet::setPid1(byte p1)
{
    at(PID1) = p1;
}

void Packet::setPid2(byte p2)
{
    at(PID2) = p2;
}

word16 Packet::calcLen()
{
    int vectorSize = size();
	word16 len = 0;

	int len_0 = vectorSize - 8;	//original line
	switch(len_0){
        case 834:
            len = 768;
            break;
        case 1602:
            len = 1536;
            break;
        case 3138:
            len = 3072;
            break;
        case 6210:
            len = 6144;
            break;
        case 12354:
            len = 12288;
            break;
        case 24640:
            len = 24576;
            break;
        default:
            len = len_0;
    }

    return len;
}

word16 Packet::calcChecksum()
{
    word16 sum = 0;
    for (it = begin(); it != end(); it++)
    {
//         printf("Packet::calcChecksum: calculating sum, adding data = %x\n", *it);
        sum += *it;
    }
    //subtracting checksum bytes, if they came from PX5 they will have value, if not they will be zeros
    sum -= at(DATA+dataLength);
    sum -= at(DATA+dataLength+1);
//     printf("Packet::calcChecksum(): sum = %x\n", sum);
    word16 checksum = twosComplement(sum);
//     printf("Packet::calcChecksum(): checksum: %x\n", checksum);
    return checksum;
}

void Packet::calcAndFillChecksum()
{
//     printf("dataLength: %d\n", dataLength);
    word16 checksum = calcChecksum();
//     printf("Step 1\n");
    at(DATA+dataLength)   = msbyte(checksum);
//     printf("Step 2\n");
    at(DATA+dataLength+1) = lsbyte(checksum);
//     printf("Step 3\n");
}

void Packet::validateChecksum()
{
    word16 calculatedChecksum = calcChecksum();
    word16 currentChecksum = mergeBytes(at(size()-2),at(size()-1));
    if (calculatedChecksum != currentChecksum)
    {
        AmptekException e = AmptekException("Checksum mismatch. Package discarted.");
        throw e;
    }
}

void Packet::setData(byte* data, word16 len)
{
    dataLength = len;
    insert(begin()+DATA, data, data+len);
    at(LEN_MSB) = msbyte(len);
    at(LEN_LSB) = lsbyte(len);
}

void Packet::fromByteArray(byte* response)
{
    at(SYNC1)   = response[SYNC1];
    at(SYNC2)   = response[SYNC2];
    at(PID1)    = response[PID1];
    at(PID2)    = response[PID2];
    at(LEN_MSB) = response[LEN_MSB];
    at(LEN_LSB) = response[LEN_LSB];
    dataLength  = mergeBytes(at(LEN_MSB), at(LEN_LSB));
    insert(begin()+DATA, response+DATA, response+DATA+dataLength);
    at(DATA+dataLength) = response[DATA+dataLength];
    at(DATA+dataLength+1) = response[DATA+dataLength+1];
    validateChecksum();
}

string Packet::toString()
{
    char hexBuff[5];
    stringstream ss;
    ss << "SYNC1 = " << hex << (short)at(SYNC1);
    ss << " SYNC2 = " << (short)at(SYNC2) << endl;
    ss << "PID1 = " << (short)at(PID1);
    ss << " PID2 = " << (short)at(PID2) << endl;
    ss << "LEN_MSB = " << (short)at(LEN_MSB);
    ss << " LEN_LSB = " << (short)at(LEN_LSB) << endl;
    for (int i = 0; i < dataLength; i++)
        ss << "DATA[" << dec << i << hex << "] = " << (short)at(DATA+i) << endl;
    ss << "CHECKSUM_MSB = " << (short)at(size()-2);
    ss << " CHECKSUM_LSB = " << (short)at(size()-1) << endl;
    return ss.str();
}
