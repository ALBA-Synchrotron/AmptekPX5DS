#include "types.h"

#include <stdio.h>
#include <iostream>
#include <sstream>

#include <string.h>
#include <bitset>

using namespace std;

void charToByte(char* chars, byte* bytes, unsigned int count){
    for(unsigned int i = 0; i < count; i++)
        bytes[i] = (byte)chars[i];
}

void charToByte(const char* chars, byte* bytes, unsigned int count){
    for(unsigned int i = 0; i < count; i++)
        bytes[i] = (byte)chars[i];
}

void strToMSBandLSB(int decimal_value, byte* bytes){
	std::string binary = std::bitset<16>(decimal_value).to_string(); //to binary	
	for(int i=0;i<2;i++){
		std::string token = binary.substr(0, 8);	//substring
		binary.erase(0, 8);
		
		std::stringstream ss;	//binary to hex
        	std::bitset<8>set(token);
        	ss << std::hex << set.to_ulong();
        	std::string res (ss.str());
		std::cout << dec << std::endl;
		//int dec = std::stoi(res,nullptr,16);
		int dec = std::stoi(res,0,16);
		std::cout << "static_cast<byte>(dec)"<<static_cast<byte>(dec) << std::endl;
		bytes[i] = static_cast<byte>(dec);;
	}
}


void byteToChar(byte* bytes, char* chars, unsigned int count){
    for(unsigned int i = 0; i < count; i++)
         chars[i] = (char)bytes[i];
    chars[count] = NULL;
}

word16 twosComplement(word16 number)
{
    word16 invert_number = ~number;
    word16 complement = invert_number + 1;
    word16 pattern = 0xFFFF;
//     printf("twosComplement(): pattern = %x\n", pattern);
    complement &= pattern; // considering only 16 LSBs
//     printf("twosComplement(): complement = %x\n", complement);
    return complement;
}

byte lsbyte(word16 number)
{
    return number & 0xFF;
}

byte msbyte(word16 number)
{
    return ((number & 0xFF00) >> 8);
}

word16 mergeBytes(byte msbyte, byte lsbyte)
{
    word16 number = msbyte;
//     printf("mergeBytes(): msbyte = %d; lsbyte = %d\n", msbyte, lsbyte);
    number <<= 8;
//     printf("mergeBytes(): number = %d\n", number);
    number += lsbyte;
//     printf("mergeBytes(): number = %d\n", number);
    return number;
}

unsigned int mergeBytes(byte msb, byte b, byte lsb)
{
    unsigned int shifted_msb = msb << 16;
    word16 shifted_b = b << 8;
    return shifted_msb + shifted_b + lsb;
}

unsigned int mergeBytes(byte msb, byte mb, byte lb, byte lsb)
{
    unsigned int shifted_msb = msb << 24;
    unsigned int shifted_mb = mb << 16;
    word16 shifted_lb = lb << 8;
    return shifted_msb + shifted_mb + shifted_lb + lsb;
}
