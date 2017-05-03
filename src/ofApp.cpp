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
	
	type = 2;
	float theta = ofGetElapsedTimeMillis() / 1000.0*PI;
	cam.setPosition(ofVec3f(sin(theta)*4, 2, cos(theta)*4));
	cam.lookAt(ofVec3f(0, 0, 0), ofVec3f(0,1,0));

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableAlphaBlending();
	ofClear(0);

	if (type == 0) {
		cam.begin();
		ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
		ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);
		staticCgScene.draw(shader, modelViewMatrix, projectionMatrix);
		staticCgScene.drawBlackWireFrame(shader, modelViewMatrix, projectionMatrix);
		cam.end();
	}
	else if (type == 1) {
		cam.begin();
		ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
		ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);
		shader_attr.begin();
		shader_attr.setUniformMatrix4f("modelViewMatrix", modelViewMatrix);
		shader_attr.setUniformMatrix4f("projectionMatrix", projectionMatrix);
		staticCgSceneAttr.drawWireFrame();
		shader_attr.end();
		cam.end();
	}
	else if (type == 2) {
		cam.begin();
		ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
		ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);
		staticCgSceneAttr.drawWireFrame();
		cam.end();
	}

	
	shader_tex.begin();
	ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);
	img.draw(0, 0);
	shader_tex.end();
	

	ofDisableAlphaBlending();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
