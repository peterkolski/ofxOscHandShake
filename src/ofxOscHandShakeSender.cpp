//
//  ofxOscHandShakeSender.cpp
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeSender.h"

ofxOscHandShakeSender::ofxOscHandShakeSender()
{
    isReceived_       = false;
//    hostBroadcast_    = "0.0.0.0";
    hostBroadcast_    = "192.168.2.255";
    addressHandShake_  = "ofxOscHandShake/reachout";
    sender_.enableBroadcast();
}

void ofxOscHandShakeSender::setup( const int portSendTo, const string deviceName )
{
    sender_.setup( hostBroadcast_, portSendTo );
    deviceName_ = deviceName;
}

void ofxOscHandShakeSender::update()
{
//    if ( !isReceived_ )
//    {
        // TODO receive and check if message arrived + set bool true
        // only stop messaging if both sides send true
        
        ofxOscMessage   messageInfo;
        messageInfo.setAddress( addressHandShake_ );
        messageInfo.addStringArg( deviceName_ );
        messageInfo.addIntArg( isReceived_ );
        sender_.sendMessage( messageInfo );
//    }
}
