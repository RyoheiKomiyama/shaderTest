#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("shader/shader");
	shader_attr.load("shader/shader_attr");
	shader_tex.load("shader/shader_tex");
	img.load("color.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    type = 1;
	float theta = ofGetElapsedTimeMillis() / 1000.0*PI;
    ofVec3f pos(sin(theta)*4, -2, cos(theta)*4);
    //ofVec3f pos(3, 2, 3);
    ofVec3f center(0, 0, 0);
    ofVec3f up(0, 1, 0);

    modelToWorld.makeIdentityMatrix();
    worldToCamera = makeLookAt(pos, center, up);
    cameraToView.makePerspectiveMatrix(100, ofGetWidth()/(float)ofGetHeight(), 0.01, 10000);
    matrix = modelToWorld*worldToCamera*cameraToView;
    //matrix = cameraToView*worldToCamera*modelToWorld;
    
    //cout << worldToCamera << endl;
    //cout << cameraToView << endl;
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofDisableDepthTest();
	ofEnableAlphaBlending();
	ofClear(0);

	if (type == 0) {
        ofMatrix4x4 modelViewMatrix = worldToCamera;
		ofMatrix4x4 projectionMatrix = cameraToView;
		staticCgScene.draw(shader, modelViewMatrix, projectionMatrix);
		staticCgScene.drawBlackWireFrame(shader, modelViewMatrix, projectionMatrix);
	}
	else if (type == 1) {
        ofPushView();
		shader_attr.begin();
        ofLoadIdentityMatrix();
//        shader_attr.setUniformMatrix4f("modelToWorld", modelToWorld);
//        shader_attr.setUniformMatrix4f("worldToCamera", worldToCamera);
//		shader_attr.setUniformMatrix4f("cameraToView", cameraToView);
        shader_attr.setUniformMatrix4f("matrix", matrix);
		staticCgSceneAttr.drawWireFrame();
		shader_attr.end();
        ofPopView();
	}
	else if (type == 2) {
        ofMatrix4x4 modelViewMatrix = worldToCamera;
        ofMatrix4x4 projectionMatrix = cameraToView;
        ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
        ofLoadMatrix(modelViewMatrix);
        ofSetMatrixMode(ofMatrixMode::OF_MATRIX_PROJECTION);
        ofLoadMatrix(projectionMatrix);
		staticCgSceneAttr.drawWireFrame();
	}
	
    /*
	shader_tex.begin();
	ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);
	img.draw(0, 0);
	shader_tex.end();
	*/

	ofDisableAlphaBlending();
}

ofMatrix4x4 ofApp::makeLookAt(ofVec3f pos, ofVec3f center, ofVec3f up){
    ofVec3f zaxis = (pos - center).getNormalized();
    ofVec3f xaxis = up.getCrossed(zaxis).getNormalized();
    ofVec3f yaxis = zaxis.getCrossed(xaxis);
    ofMatrix4x4 lookatmat(xaxis.x, xaxis.y, xaxis.z, 0,
                          yaxis.x, yaxis.y, yaxis.z, 0,
                          zaxis.x, zaxis.y, zaxis.z, 0,
                          pos.x, pos.y, pos.z, 1);
    return lookatmat;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    //glViewport(0, 0, w, h); // maybe don't have to write this
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
