#include "ofMain.h"
#include "Communication.h"

int main( ){
	ofSetupOpenGL(1024,768, OF_WINDOW);
	ofRunApp( new Communication());
}
