#pragma once

#include "ofMain.h"
#include "ofxOscHandShake.h"


class Detection : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

	ofxOscHandShake			handShaker;
};
