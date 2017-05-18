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

string  ofxOscHandShakeReceiver::getDeviceName(const unsigned int ID )
{
    if (  ID < deviceNameList_.size() )
    {
        return deviceNameList_.at( ID );
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
    if (  ID < deviceNameList_.size() )
    {
        return deviceIP_.at( deviceNameList_[ ID ] );
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with id " << ID;
        return "";
    }

}

//TODO Maybe reference? But then no last creation possible
ofxOscHandShakeDevice ofxOscHandShakeReceiver::getDevice( const unsigned int ID )
{
    if (  ID < devicesMap_.size() )
    {
        return (*(std::next( devicesMap_.begin(), ID ))).second;
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with id " << ID;
        return ofxOscHandShakeDevice{"", 0}; //TODO What should I here?
    }
}

ofxOscHandShakeDevice ofxOscHandShakeReceiver::getDevice( const string name )
{
    if (  devicesMap_.count( name ) )
    {
        return devicesMap_.at( name );
    }
    else
    {
        ofLogError() << "OscHandShakeReceiver - No device found with name " << name;
        return ofxOscHandShakeDevice{"", 0}; //TODO What should I here?
    }
}

