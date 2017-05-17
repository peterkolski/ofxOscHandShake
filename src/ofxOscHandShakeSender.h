//
//  ofxOscHandShakeSender.h
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#ifndef __Sound__ofxOscHandShakeSender__
#define __Sound__ofxOscHandShakeSender__

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"


class ofxOscHandShakeSender{
public:
    ofxOscHandShakeSender();
    void setup( const int portSendTo, const string deviceName );
    void update();
    
private:
    ofxOscSender    sender_;
    string          addressHandShake_, hostBroadcast_;
    string          deviceName_;
    bool            isReceived_;
};

#endif /* defined(__Sound__ofxOscHandShakeSender__) */
