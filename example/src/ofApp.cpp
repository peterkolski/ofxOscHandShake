#include "ofApp.h"


void ofApp::setup(){
    auto portToReciever = 9999;

    sender1.setup( portToReciever, "RPi 1" );
    sender2.setup( portToReciever, "RPi 2" );
    reciever.setup( portToReciever );
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
