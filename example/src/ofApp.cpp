#include "ofApp.h"


void ofApp::setup(){
    auto portToReciever = 9999;

    sender1.setup( portToReciever, "Peter1" );
//    sender2.setup( portToReciever, "Peter2" );
    reciever.setup( portToReciever );
}


void ofApp::update(){
    sender1.update();
//    sender2.update();
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

    for ( int i = 0; i < deviceAmountFound; i++ )
    {
        ofDrawBitmapStringHighlight( "Name " + ofToString( i )+ ": " + ofToString( deviceName ), 100, 140 + i*20);
        ofDrawBitmapStringHighlight( "IP " + ofToString( i )+ ": " + ofToString( deviceIP ), 300, 140 + i*20);
    }
}
