#include "Detection.h"


void Detection::setup(){
    auto broadcastIP = "192.168.2.255"; // ---> put your broadcast IP here
    handShaker.setup( "BerlinPunk", broadcastIP );
}


void Detection::update(){
    handShaker.update();
}


void Detection::draw(){
    ofBackground( 255 );
    ofDrawBitmapStringHighlight( "Amount: " + ofToString( handShaker.getDeviceAmountFound() ), 100, 100 );

    for ( int i = 0; i < handShaker.getDeviceAmountFound(); i++ )
    {
        ofDrawBitmapStringHighlight( "Name " + ofToString( i )+ ": " + ofToString( handShaker.getDeviceName( i ) ), 100, 140 + i*20);
        ofDrawBitmapStringHighlight( "IP " + ofToString( i )+ ": " + ofToString( handShaker.getDeviceIP( i ) ), 300, 140 + i*20);
    }
}
