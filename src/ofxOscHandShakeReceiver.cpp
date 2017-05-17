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
    while( receiver_.hasWaitingMessages() )
    {
        ofxOscMessage m;
        receiver_.getNextMessage(&m);
        
        if ( m.getAddress() == addressHandShake_ )
        {
            // Message 0 -> name
            // Message 1 -> isReceived
            
            // --- Does the device not exist yet
            if ( deviceIP_.count( m.getArgAsString( 0 ) ) == 0 ) {
                deviceList_.push_back( m.getArgAsString( 0 ) );
                deviceIP_[ m.getArgAsString( 0 ) ] = m.getRemoteIp();
            }
        }
    }

}

string  ofxOscHandShakeReceiver::getDeviceName(const unsigned int ID )
{
    if (  ID < deviceList_.size() )
    {
        return deviceList_.at( ID );
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with id " << ID;
        return "";
    }
}

string  ofxOscHandShakeReceiver::getDeviceIP( const string name )
{
    if (deviceIP_.count( name ) )
    {
        return deviceIP_.at( name );
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with name " << name;
        return "";
    }

}

string  ofxOscHandShakeReceiver::getDeviceIP( const unsigned int ID )
{
    if (  ID < deviceList_.size() )
    {
        return deviceIP_.at( deviceList_[ ID ] );
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with id " << ID;
        return "";
    }

}