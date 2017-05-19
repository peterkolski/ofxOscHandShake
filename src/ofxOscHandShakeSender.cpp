//
//  ofxOscHandShakeSender.cpp
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeSender.h"

ofxOscHandShakeSender::ofxOscHandShakeSender()
{
    addressHandShake_  = "ofxOscHandShake/reachout";
    sender_.enableBroadcast();
}

void ofxOscHandShakeSender::setup( const string deviceName, const int portBroadcast, const string broadcastIP )
{
    sender_.setup( broadcastIP, portBroadcast );
    deviceName_ = deviceName;
}

void ofxOscHandShakeSender::setup( const string deviceName, const int portBroadcast, const string broadcastIP,
                                   const int portGettingMessage, const int portSending )
{
    sender_.setup( broadcastIP, portBroadcast );
    deviceName_         = deviceName;
    portGettingMessage_ = portGettingMessage;
    portSendingTo_      = portSending;
}

void ofxOscHandShakeSender::update()
{
    ofxOscMessage   messageInfo;
    messageInfo.setAddress( addressHandShake_ );
    messageInfo.addStringArg( deviceName_ );
    messageInfo.addIntArg( portGettingMessage_ );
    messageInfo.addIntArg( portSendingTo_ );
    sender_.sendMessage( messageInfo );
}
