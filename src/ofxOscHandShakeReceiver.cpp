//
//  ofxOscHandShakeReceiver.cpp
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeReceiver.h"


void ofxOscHandShakeReceiver::setup( const int portRecieveingAllMsg, const string adressBroadcast )
{
    receiver_.setup( portRecieveingAllMsg );
    addressHandShake_  = adressBroadcast;
}


ofxOscHandShakeDevice ofxOscHandShakeReceiver::getDeviceCurrent()
{
    ofxOscMessage messageOSC;
    receiver_.getNextMessage(&messageOSC);

    // Message 0 -> name
    // Message 1 -> portGetting
    // Message 2 -> portSending
    if ( messageOSC.getAddress() == addressHandShake_ )
    {
        return ofxOscHandShakeDevice{ ( messageOSC.getArgAsString( 0 ) ), messageOSC.getRemoteIp(),
                                      messageOSC.getArgAsInt( 1 ), messageOSC.getArgAsInt( 2 ) };
    }
}

