#include "ofApp.h"


void ofApp::setup(){
    sender1.setup( 9999, "RPi 1" );
    sender2.setup( 9999, "RPi 2" );
    reciever.setup( 9999 );
}


void ofApp::update(){
    sender1.update();
    sender2.update();
    reciever.update();
}


void ofApp::draw(){
    ofBackground( 255 );

    auto deviceName=std::string();
    auto deviceIP=std::string();
    auto deviceAmountFound = reciever.getDeviceAmountFound();

    if ( deviceAmountFound )
    {
        deviceName = reciever.getDeviceName( 0 );
        deviceIP = reciever.getDeviceIP( 0 );
    }

    ofDrawBitmapStringHighlight( "Amount: " + ofToString( deviceAmountFound ), 100, 100 );
    ofDrawBitmapStringHighlight( "Name 0: " + ofToString( deviceName ), 100, 140 );
    ofDrawBitmapStringHighlight( "IP 0: " + ofToString( deviceIP ), 100, 180 );
}
