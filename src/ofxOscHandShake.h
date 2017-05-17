//
//  ofxOscHandShake.h
//
//  Created by Peter A. Kolski on 29.09.15.
//
//
#pragma once

#ifndef __Sound__ofxOscHandShake__
#define __Sound__ofxOscHandShake__

#include "ofxOscHandShakeSender.h"
#include "ofxOscHandShakeReceiver.h"

class ofxOscHandShake
{
public:
    void setup( const string deviceName, const string broadcastIP );
    void update();

    int     getDeviceAmountFound()              { return receiver_.getDeviceAmountFound(); }

private:
    ofxOscHandShakeSender   sender_;
    ofxOscHandShakeReceiver receiver_;
};

#endif /* defined(__Sound__ofxOscHandShake__) */
