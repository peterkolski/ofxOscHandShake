#include "Detection.h"


void Detection::setup(){
    auto broadcastIP = "192.168.2.255"; // ---> put your broadcast IP here

    // ---- Declaring your device
    auto deviceName = "BerlinPunk";
    auto portGettingMessages = 111;     // ---> THE OTHER SIDE sends messages to this port
    auto portSendingTo = 222;           // ---> THE OTHER SIDE gets messages to this port

    handShaker.setup( deviceName, broadcastIP, portGettingMessages, portSendingTo );
}


void Detection::update(){
    handShaker.update();
}


void Detection::draw(){
    ofBackground( 255 );

    ofDrawBitmapStringHighlight( "Amount: " + ofToString( handShaker.getDeviceAmountFound() ), 100, 100 );

    for ( int i = 0; i < handShaker.getDeviceAmountFound(); i++ )
    {
        ofDrawBitmapStringHighlight( ofToString( i ) + " - Name: " + ofToString( handShaker.getDeviceName( i ) ), 100, 140 + i*20);
        ofDrawBitmapStringHighlight( "IP: " + ofToString( handShaker.getDeviceIP( i ) ), 300, 140 + i*20);
        ofDrawBitmapStringHighlight( "port Getting : " + ofToString( handShaker.getPortGettingMessage( i ) ), 500, 140 + i*20);
        ofDrawBitmapStringHighlight( "port Sending : " + ofToString( handShaker.getPortSendingTo( i ) ), 700, 140 + i*20);
    }
}
