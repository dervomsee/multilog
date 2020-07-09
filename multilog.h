/*
 multilog.h - UDP logging library

 */

#ifndef MultiLog_h
#define MultiLog_h

#include <inttypes.h>
#include "Print.h"
#include <WiFiUdp.h>

class MultiLog: public Print
{

    public:
        MultiLog( IPAddress Ip, uint32_t port, HardwareSerial * _Serial );
        MultiLog( IPAddress Ip, uint32_t port );
        MultiLog( HardwareSerial * _Serial );
        size_t write(uint8_t);
        size_t write(const uint8_t *buffer, size_t size);    

    protected:
        
};
#endif
