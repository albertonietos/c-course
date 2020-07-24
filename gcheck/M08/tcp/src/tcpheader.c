#include "tcpheader.h"


int getSourcePort(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[0] << 8) | tcp_hdr[1];  // << has precedence to |
}

int getDestinationPort(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[2] << 8) | tcp_hdr[3];
}

void setSourcePort(unsigned char *tcp_hdr, int port)
{
    tcp_hdr[0] = port >> 8;  // most significant 8 bits (leftmost)
    tcp_hdr[1] = port;  // least significant 8 bits (rightmost)
}

void setDestinationPort(unsigned char *tcp_hdr, int port)
{
    tcp_hdr[2] = port >> 8;
    tcp_hdr[3] = port;
}

int getAckFlag(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[13] >> 4) & 1;
}

void setAckFlag(unsigned char *tcp_hdr, int flag)
{
    if (flag) {
        tcp_hdr[13] = tcp_hdr[13] | 0x10;  // 0x10 is 1 0000  
    } else {
        tcp_hdr[13] = tcp_hdr[13] & ~0x10;
    }
}

int getDataOffset(const unsigned char *tcp_hdr)
{
    return tcp_hdr[12] >> 4;
}

void setDataOffset(unsigned char *tcp_hdr, int offset)
{
    tcp_hdr[12] = (tcp_hdr[12] & 0x0f) | (offset << 4);
}
