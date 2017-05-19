//
//  ofxOscHandShakeSender.cpp
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeSender.h"

void ofxOscHandShakeSender::setup( const string deviceName, const int portBroadcast, const string broadcastIP,
                                   const string adressBroadcast )
{
    addressHandShake_  = adressBroadcast;
    sender_.enableBroadcast();
    sender_.setup( broadcastIP, portBroadcast );
    deviceName_ = deviceName;
}

void ofxOscHandShakeSender::setup( const string deviceName, const int portBroadcast, const string broadcastIP,
                                   const int portGettingMessage, const int portSending, string adressBroadcast )
{
    addressHandShake_  = adressBroadcast;
    sender_.enableBroadcast();
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
