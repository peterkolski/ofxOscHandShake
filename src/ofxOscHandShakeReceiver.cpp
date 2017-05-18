//
//  ofxOscHandShakeReceiver.cpp
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#include "ofxOscHandShakeReceiver.h"

ofxOscHandShakeReceiver::ofxOscHandShakeReceiver()
{
    addressHandShake_  = "ofxOscHandShake/reachout";
}

void ofxOscHandShakeReceiver::setup( const int portRecieveingAllMsg )
{
        receiver_.setup( portRecieveingAllMsg );
}


void ofxOscHandShakeReceiver::update()
{
    if ( ofGetElapsedTimeMillis() % 100 == 0)
    {
        deviceIP_.clear();
        deviceNameList_.clear();
    }

    while( receiver_.hasWaitingMessages() )
    {
        ofxOscMessage m;
        receiver_.getNextMessage(&m);
        
        if ( m.getAddress() == addressHandShake_ )
        {
            // Message 0 -> name
            // Message 1 -> isReceived

            auto deviceName = m.getArgAsString( 0 );

            // --- Does the device not exist yet
            if ( deviceIP_.count( deviceName ) == 0 ) {
                deviceNameList_.push_back( deviceName );
                deviceIP_[ deviceName ] = m.getRemoteIp();
            }

            if ( devicesMap_.count( deviceName ) == 0 )
            {
                devicesMap_.emplace( std::make_pair( deviceName,
                                                     ofxOscHandShakeDevice{ deviceName, m.getRemoteIp() }) );
            }
        }
    }

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

