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
    receiver_.update();
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
