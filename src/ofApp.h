#pragma once

#include "ofMain.h"
#include "StaticCGScene.h"
#include "StaticCGSceneAttr.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofShader shader;
		scgs::StaticCGScene staticCgScene;
		ofShader shader_attr;
		scgsa::StaticCGSceneAttr staticCgSceneAttr;
		ofShader shader_tex;
		ofImage img;

        int type = 0;
        ofCamera cam;
        ofMatrix4x4 modelToWorld;
        ofMatrix4x4 worldToCamera;
        ofMatrix4x4 cameraToView;
        ofMatrix4x4 matrix;
    
    ofMatrix4x4 makeLookAt(ofVec3f pos, ofVec3f center, ofVec3f up);
};
