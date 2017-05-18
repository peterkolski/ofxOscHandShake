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
    ofxOscHandShakeDevice( const string &nameDevice_, const string &ip_ )
            : nameDevice_( nameDevice_ ), ip_( ip_ ) {}

    const string &getNameDevice_() const { return nameDevice_; }
    const string &getIp_() const { return ip_; }
//    int getPortRecieveing() const { return portRecieveing_; }
//    int getPortSendingFrom() const { return portSendingFrom_; }

private:
    string  nameDevice_;
    string  ip_;
//    int     portRecieveing_;
//    int     portSendingFrom_;
};

#endif /* defined(__Sound__ofxOscHandShakeDevice__) */
