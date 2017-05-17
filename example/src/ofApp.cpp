#include "ofApp.h"


void ofApp::setup(){
    auto portToReciever = 9999;

    sender1.setup( "Peter new", portToReciever, "192.168.2.255" );
    reciever.setup( portToReciever );
}


void ofApp::update(){
    sender1.update();
    reciever.update();
}


void ofApp::draw(){
    ofBackground( 255 );

    auto deviceName=std::string();
    auto deviceIP=std::string();
    auto deviceAmountFound = reciever.getDeviceAmountFound();



    ofDrawBitmapStringHighlight( "Amount: " + ofToString( deviceAmountFound ), 100, 100 );

    for ( int i = 0; i < deviceAmountFound; i++ )
    {
        deviceName = reciever.getDeviceName( i );
        deviceIP = reciever.getDeviceIP( i );
        ofDrawBitmapStringHighlight( "Name " + ofToString( i )+ ": " + ofToString( deviceName ), 100, 140 + i*20);
        ofDrawBitmapStringHighlight( "IP " + ofToString( i )+ ": " + ofToString( deviceIP ), 300, 140 + i*20);
    }
}
