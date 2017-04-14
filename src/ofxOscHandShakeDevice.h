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

struct ofxReceivedDevice
{
    ofxReceivedDevice();
    ofxReceivedDevice( string ip, string address )
    :   ip_( ip ),
        address_( address )
    {}
    
    string  ip()        { return ip_; }
    string  address()    { return address_; }
    
private:
    string  ip_;
    string  address_;
};

#endif /* defined(__Sound__ofxOscHandShakeDevice__) */
