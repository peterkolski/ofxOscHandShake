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
}
