//
//  ofxOscHandShake.h
//
//  Created by Peter A. Kolski on 29.09.15.
//
//
#pragma once

#ifndef __Sound__ofxOscHandShake__
#define __Sound__ofxOscHandShake__

#include "ofxOscHandShakeSender.h"
#include "ofxOscHandShakeReceiver.h"

class ofxOscHandShake
{
public:
    void setup( const string deviceName, const string broadcastIP );
    void setup( const string deviceName, const string broadcastIP, const int portGetting, const int portSendingTo );
    void update();

    int     getDeviceAmountFound()                  { return devicesMap_.size(); }
    string  getDeviceName( const unsigned int ID )  { return getDevice( ID ).getNameDevice(); }
    string  getDeviceIP( const unsigned int ID )    { return getDevice( ID ).getIp(); }
    string  getDeviceIP( const string name )        { return getDevice( name ).getIp(); }

    ofxOscHandShakeDevice getDevice( const unsigned int ID ); //TODO reference
    ofxOscHandShakeDevice getDevice( const string name );

private:
    void    updateReceiver();

    int portBroadcast  = 19591; // Should be a number, which nobody uses
    int portGettingMessage_ = -1;
    int portSendingTo_      = -1;
    std::unordered_map< string, ofxOscHandShakeDevice > devicesMap_;
    ofxOscHandShakeSender   sender_;
    ofxOscHandShakeReceiver receiver_;
};


#endif /* defined(__Sound__ofxOscHandShake__) */
