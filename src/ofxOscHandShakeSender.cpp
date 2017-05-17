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
    addressHandShake_  = "ofxOscHandShake/reachout";
    sender_.enableBroadcast();
}

void ofxOscHandShakeSender::setup( const string deviceName, const int portSendTo, const string broadcastIP )
{
    sender_.setup( broadcastIP, portSendTo );
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
