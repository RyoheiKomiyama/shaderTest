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

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableAlphaBlending();
	ofClear(0);

	ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofMatrix4x4 projectionMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION);


	/*
	cam.begin();
	staticCgScene.draw(shader, modelViewMatrix, projectionMatrix);
	staticCgScene.drawBlackWireFrame(shader, modelViewMatrix, projectionMatrix);
	cam.end();
	*/

	
	cam.begin();
	shader_attr.begin();
	shader_attr.setUniformMatrix4f("modelViewMatrix", modelViewMatrix);
	shader_attr.setUniformMatrix4f("projectionMatrix", projectionMatrix);
	staticCgSceneAttr.drawWireFrame();
	shader_attr.end();
	cam.end();
	
	
	shader_tex.begin();
	shader_tex.setUniformMatrix4f("modelViewMatrix", modelViewMatrix);
	shader_tex.setUniformMatrix4f("projectionMatrix", projectionMatrix);
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
