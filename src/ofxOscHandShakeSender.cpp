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
    hostBroadcast_    = "0.0.0.0";
    addressHandShake_  = "ofxOscHandShake/reachout";
}

void ofxOscHandShakeSender::setup( const int portSender, const string deviceName )
{
    sender_.setup( hostBroadcast_, portSender );
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
