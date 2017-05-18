#include "ofxOscHandShake.h"

void ofxOscHandShake::setup( const string deviceName, const string broadcastIP )
{
    auto _port  = 19591;
    sender_.setup( deviceName, _port, broadcastIP );
    receiver_.setup( _port );
}

void ofxOscHandShake::update()
{
    sender_.update();
    updateReceiver();
}

void ofxOscHandShake::updateReceiver()
{
    // --- Clear after a second
    if ( ofGetElapsedTimeMillis() % 100 == 0)
    {
        devicesMap_.clear();
    }

    while( receiver_.hasRecievedDevice() )
    {
        auto device = receiver_.getDeviceCurrent();
        if ( devicesMap_.count( device.getNameDevice() ) == 0 )
        {
            devicesMap_.insert( std::make_pair( device.getNameDevice(), device ) );
        }
    }
}

//TODO Maybe reference? But then no last creation possible
ofxOscHandShakeDevice ofxOscHandShake::getDevice( const unsigned int ID )
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

ofxOscHandShakeDevice ofxOscHandShake::getDevice( const string name )
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