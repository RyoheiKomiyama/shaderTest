#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// suuuuuuuuper important!!!!!!!
	// http://www.wasted-laboratory.info/2015/07/14/ofWithGL.html
	ofGLWindowSettings s;
	s.setGLVersion(4, 1);
	ofCreateWindow(s);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
