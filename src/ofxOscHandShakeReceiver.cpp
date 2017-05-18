//
//  ofxOscHandShakeReceiver.cpp
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeReceiver.h"


void ofxOscHandShakeReceiver::setup( const int portRecieveingAllMsg )
{
        receiver_.setup( portRecieveingAllMsg );
}


ofxOscHandShakeDevice ofxOscHandShakeReceiver::getDeviceCurrent()
{
    ofxOscMessage m;
    receiver_.getNextMessage(&m);

    // TODO This can crash, if you get the wrong message

//    if ( m.getAddress() == addressHandShake_ )
//    {
        // Message 0 -> name
        // Message 1 -> isReceived

//    }

    return ofxOscHandShakeDevice{ ( m.getArgAsString( 0 ) ), m.getRemoteIp() };
}

