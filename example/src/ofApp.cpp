#include "ofApp.h"


void ofApp::setup(){
    sender.setup( 8888, 9999, "RPi 1" );
    reciever.setup( 9999, 8888 );
}


void ofApp::update(){
    sender.update();
    reciever.update();
}


void ofApp::draw(){
    ofBackground( 255 );

    ofDrawBitmapStringHighlight( ofToString( "Amount: " + reciever.getDeviceAmountFound() ), 100, 100 );
//    ofDrawBitmapStringHighlight( ofToString( "Name 1: " + reciever.getDeviceName( 0 ) ), 100, 140 );
//    ofDrawBitmapStringHighlight( ofToString( "IP 1: " + reciever.getDeviceIP( 0 ) ), 100, 180 );
}
