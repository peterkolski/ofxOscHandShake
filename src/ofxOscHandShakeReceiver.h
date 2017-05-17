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
    ofxOscHandShakeReceiver();
    
    void    setup( const int portRecieveingAllMsg );
    void    update();
    
    int     getDeviceAmountFound()              { return deviceList_.size(); }
    string  getDeviceName( const unsigned int ID );
    string  getDeviceIP( const string name );
    string  getDeviceIP( const unsigned int ID );
    
private:
    ofxOscReceiver  receiver_;
    string          addressHandShake_;
    bool            isReceived_;
    
    std::map< string, string >   deviceIP_;
    vector< string >             deviceList_;
};


#endif /* defined(__Sound__ofxOscHandShakeReceiver__) */
