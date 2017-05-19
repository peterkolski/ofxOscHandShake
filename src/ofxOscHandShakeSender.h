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
    void setup( const string deviceName, const int portBroadcast, const string broadcastIP );
    void setup( const string deviceName, const int portBroadcast, const string broadcastIP,
                const int portGettingMessage, const int  portSending );
    void update();
    
private:
    ofxOscSender    sender_;
    string          addressHandShake_;
    string          deviceName_;
    int             portGettingMessage_ = -1;
    int             portSendingTo_      = -1;
};

#endif /* defined(__Sound__ofxOscHandShakeSender__) */
