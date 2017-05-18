#pragma once

#include "ofMain.h"
#include "ofxOscHandShake.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

	ofxOscHandShake			handShaker;
};
