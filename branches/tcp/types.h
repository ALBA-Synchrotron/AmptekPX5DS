#ifndef TYPES_H
#define TYPES_H
#include <stdio.h>
 
typedef unsigned char      byte;    // Byte is a char
typedef unsigned short int word16;  // 16-bit word is a short int
typedef unsigned int       word32;  // 32-bit word is an int

void charToByte(char* chars, byte* bytes, unsigned int count);

void charToByte(const char* chars, byte* bytes, unsigned int count);

void byteToChar(byte* bytes, char* chars, unsigned int count);

void strToMSBandLSB(int i, byte* bytes);

word16 twosComplement(word16 number);

byte lsbyte(word16 number);

byte msbyte(word16 number);

word16 mergeBytes(byte msbyte, byte lsbyte);

unsigned int mergeBytes(byte msb, byte b, byte lsb);

unsigned int mergeBytes(byte msb, byte mb, byte lb, byte lsb);
#endif
