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
    
    int     getDeviceAmountFound()              { return deviceNameList_.size(); }
    string  getDeviceName( const unsigned int ID );
    string  getDeviceIP( const string name );
    string  getDeviceIP( const unsigned int ID );

    ofxOscHandShakeDevice getDevice( const unsigned int ID );
    ofxOscHandShakeDevice getDevice( const string name );

private:
    ofxOscReceiver  receiver_;
    string          addressHandShake_;

    std::map< string, string >   deviceIP_;
    vector< string >             deviceNameList_;

    std::map< string, ofxOscHandShakeDevice > devicesMap_;
};


#endif /* defined(__Sound__ofxOscHandShakeReceiver__) */
