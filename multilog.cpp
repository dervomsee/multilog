#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "pins_arduino.h"
#include "multilog.h"

IPAddress _Ip;
uint32_t  _port;
WiFiUDP   _Udp;
bool      _bUdpEnabled = false;
HardwareSerial * _Serial;
bool      _bSerialEnabled = false;

MultiLog::MultiLog( IPAddress Ip, uint32_t port, HardwareSerial * Serial )
{
    _Ip = Ip;
    _port = port;
    _bUdpEnabled = true;
    if(Serial!=NULL)
    {
       _Serial = Serial;
       _bSerialEnabled = true; 
    }
    else
    {
        _bSerialEnabled = false;
    }    
}

MultiLog::MultiLog( IPAddress Ip, uint32_t port )
{
    _Ip = Ip;
    _port = port;
    _bUdpEnabled = true;
    _bSerialEnabled = false;   
}

MultiLog::MultiLog( HardwareSerial * Serial )
{
    _bUdpEnabled = false;
    if(Serial!=NULL)
    {
       _Serial = Serial;
       _bSerialEnabled = true; 
    }
    else
    {
        _bSerialEnabled = false;
    }    
}

size_t MultiLog::write(const uint8_t *buffer, size_t size)
{
    if(_bUdpEnabled)
    {
        _Udp.beginPacket(_Ip, _port); // subnet Broadcast IP and port
        _Udp.write(buffer, size);
        _Udp.endPacket();
    }
    if(_bSerialEnabled)
    {
        _Serial->write(buffer, size);
    }
    return size;
}

size_t MultiLog::write(uint8_t c)
{
    if(_bUdpEnabled)
    {
        _Udp.beginPacket(_Ip, _port); // subnet Broadcast IP and port
        _Udp.write(c);
        _Udp.endPacket();
    }
    if(_bSerialEnabled)
    {
        _Serial->write(c);
    }
    return 1;
}