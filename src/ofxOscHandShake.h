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
    void setup( const string deviceName, const string broadcastIP, const int portGetting, const int portSendingTo );
    void update();

    int     getDeviceAmountFound()                  { return devicesMap_.size(); }
    bool    isDeviceFound( const string name );
    string  getDeviceName( const unsigned int ID )  { return getDevice( ID ).getNameDevice(); }
    string  getDeviceIP( const unsigned int ID )    { return getDevice( ID ).getIp(); }
    string  getDeviceIP( const string name )        { return getDevice( name ).getIp(); }
    int     getPortGettingMessage( const string name ) { return getDevice( name ).getPortGettingMessage(); }
    int     getPortGettingMessage( const int ID )   { return getDevice( ID ).getPortGettingMessage(); }
    int     getPortSendingTo( const int ID )        { return getDevice( ID ).getPortSendingTo(); }
    int     getPortSendingTo( const string name )   { return getDevice( name ).getPortSendingTo(); }

    ofxOscHandShakeDevice getDevice( const unsigned int ID ); //TODO reference
    ofxOscHandShakeDevice getDevice( const string name );

private:
    void    updateReceiver();

    string                  adressBroadcast_ = "ofxOscHandShake/reachout";
    int                     portBroadcast_   = 19591; // Should be a number, which nobody uses
    ofxOscHandShakeSender   sender_;
    ofxOscHandShakeReceiver receiver_;
    std::unordered_map< string, ofxOscHandShakeDevice > devicesMap_;
};


#endif /* defined(__Sound__ofxOscHandShake__) */
