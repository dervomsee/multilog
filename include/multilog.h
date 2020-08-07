/*
 multilog.h - UDP logging library

 */

#ifndef MultiLog_h
#define MultiLog_h

#include <inttypes.h>
#include "Print.h"
#include <WiFiUdp.h>
#include "HardwareSerial.h"

class MultiLog: public Print
{
    public:
        /* MultiLog contructor
         * The argument Ip could be a single IP or a broadcast address. 
         * The port is the destination port, where the messeges will be send to.
         * As Serial a pointer to a HardwareSerial port must be passed. 
        */
        MultiLog( IPAddress Ip, uint32_t port, HardwareSerial * Serial );  
        MultiLog( IPAddress Ip, uint32_t port );
        MultiLog( HardwareSerial * Serial ); 

    protected:
        size_t write(uint8_t);
        size_t write(const uint8_t * buffer, size_t size);           
};
#endif
