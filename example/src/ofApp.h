#pragma once

#include "ofMain.h"
#include "ofxOscHandShake.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

    ofxOscHandShakeSender   sender1, sender2;
    ofxOscHandShakeReceiver reciever;
};
