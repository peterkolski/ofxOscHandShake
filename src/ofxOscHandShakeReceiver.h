//
//  ofxOscHandShakeReceiver.h
//  Sound
//
//  Created by Peter A. Kolski on 29.09.15.
//
//

#ifndef __Sound__ofxOscHandShakeReceiver__
#define __Sound__ofxOscHandShakeReceiver__

#include <stdio.h>
#include <map>
#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxOscHandShakeDevice.h"

class ofxOscHandShakeReceiver{
public:
    void                    setup( const int portRecieveingAllMsg, const string adressBroadcast );
    bool                    hasRecievedDevice() { return receiver_.hasWaitingMessages(); }
    ofxOscHandShakeDevice   getDeviceCurrent();

private:
    ofxOscReceiver  receiver_;
    string          addressHandShake_;

    std::map< string, string >   deviceIP_;
    vector< string >             deviceNameList_;

    std::unordered_map< string, ofxOscHandShakeDevice > devicesMap_;
};


#endif /* defined(__Sound__ofxOscHandShakeReceiver__) */
