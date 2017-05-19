//
//  ofxOscHandShakeDevice.h
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#ifndef __Sound__ofxOscHandShakeDevice__
#define __Sound__ofxOscHandShakeDevice__

#include <stdio.h>
#include <string>

using namespace std;

struct ofxOscHandShakeDevice
{
    ofxOscHandShakeDevice( const string &nameDevice_, const string &ip_ ) : nameDevice_( nameDevice_ ), ip_( ip_ ) {}

    ofxOscHandShakeDevice( const string &nameDevice, const string &ip, int portGettingMessage, int portSendingTo )
            : nameDevice_( nameDevice ), ip_( ip ), portGettingMessage( portGettingMessage ),
              portSendingTo_( portSendingTo ) {}

    const string &getNameDevice() const { return nameDevice_; }
    const string &getIp() const { return ip_; }
    int getPortGettingMessage() const { return portGettingMessage; }
    int getPortSendingTo() const { return portSendingTo_; }

private:
    string  nameDevice_;
    string  ip_;
    int     portGettingMessage  = 0;
    int     portSendingTo_      = 0;
};

#endif /* defined(__Sound__ofxOscHandShakeDevice__) */
