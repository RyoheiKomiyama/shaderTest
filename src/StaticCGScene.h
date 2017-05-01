//
//  StaticCGScene.h
//  demoViewer
//
//  Created by ryoheikomiyama on 2017/04/23.
//
//

#ifndef StaticCGScene_h
#define StaticCGScene_h

// meter or centimeter
//#define METERSCALE
#ifdef METERSCALE
#define SCALE 100.0
#else
#define SCALE 1.0
#endif

// 1 or 255
#define COLOR1
#ifdef COLOR1
#define COLORSCALE 255.0
#else
#define COLORSCALE 1.0
#endif


#include "ofMain.h"


class ColorBox{
public:
    ofMesh mesh;
    ofFloatColor color;
    ofVec3f pos;
    
public:
    ColorBox(ofFloatColor color, ofVec3f pos){
        
        // color, pos
        this->color = color;
        this->pos = pos;

        // vertices
        float box_size = 60/SCALE;
        vector<ofVec3f> vertices = {
            ofVec3f(0, 0, 0),
            ofVec3f(0, box_size, 0),
            ofVec3f(box_size, box_size, 0),
            ofVec3f(box_size, 0, 0),
            ofVec3f(0, 0, box_size),
            ofVec3f(0, box_size, box_size),
            ofVec3f(box_size, box_size, box_size),
            ofVec3f(box_size, 0, box_size)
        };
        mesh.addVertices(vertices);

		vector<ofFloatColor> colors;
		for (int i = 0; i < vertices.size(); i++) {
			colors.push_back(color);
		}
		mesh.addColors(colors);
        
        // triangle
        mesh.addTriangle(0, 1, 2);
        mesh.addTriangle(0, 2, 3);
        mesh.addTriangle(4, 5, 1);
        mesh.addTriangle(4, 1, 0);
        mesh.addTriangle(7, 6, 5);
        mesh.addTriangle(7, 5, 4);
        mesh.addTriangle(3, 2, 6);
        mesh.addTriangle(3, 6, 7);
        mesh.addTriangle(1, 5, 6);
        mesh.addTriangle(1, 6, 2);
        mesh.addTriangle(4, 0, 3);
        mesh.addTriangle(4, 3, 7);
    }
    
    void update(){}
    
    void draw(){
        ofPushMatrix();
        ofTranslate(pos);
        mesh.draw();
        ofPopMatrix();
    }
    
    void drawWireFrame(){
        ofPushMatrix();
        ofTranslate(pos);
        mesh.drawWireframe();
        ofPopMatrix();
    }
    
};


class Grass{
public:
    ofMesh mesh;
    ofFloatColor color;
    
public:
    Grass(){
        
        // color
        color = ofFloatColor(80 / COLORSCALE, 120 / COLORSCALE, 60 / COLORSCALE);
        
        // vertices
        float square_size = 200/SCALE;
        vector<ofVec3f> vertices = {
            ofVec3f(-square_size, 0, -square_size),
            ofVec3f(-square_size, 0, square_size),
            ofVec3f(square_size, 0, square_size),
            ofVec3f(square_size, 0, -square_size)
        };
        mesh.addVertices(vertices);

		vector<ofFloatColor> colors;
		for (int i = 0; i < vertices.size(); i++) {
			colors.push_back(color);
		}
		mesh.addColors(colors);
        
        // triangle
        mesh.addTriangle(0, 1, 2);
        mesh.addTriangle(0, 2, 3);
    }
    
    void update(){}
    
    void draw(){
        mesh.draw();
    }
    
    void drawWireFrame(){
        mesh.drawWireframe();
    }
    
    
};




class StaticCGScene{
    public:
    vector<ColorBox> boxes;
    Grass grass;
    
public:
    StaticCGScene(){
        ColorBox box_r(ofFloatColor(200 / COLORSCALE, 100 / COLORSCALE, 100 / COLORSCALE), ofVec3f(0, 1, -160 / SCALE));
        ColorBox box_y(ofFloatColor(210 / COLORSCALE, 210 / COLORSCALE, 100 / COLORSCALE), ofVec3f(-200 / SCALE, 1, -60 / SCALE));
        ColorBox box_b(ofFloatColor(70 / COLORSCALE, 100 / COLORSCALE, 130 / COLORSCALE), ofVec3f(140 / SCALE, 1, 40 / SCALE));
        boxes.push_back(box_r);
        boxes.push_back(box_y);
        boxes.push_back(box_b);
    }
    
    void update(){
        for(auto& box: boxes){
            box.update();
        }
        grass.update();
    }
    
    void draw(ofShader& shader, ofMatrix4x4 mvm, ofMatrix4x4 pm){
		ofEnableDepthTest();
		shader.begin();
		shader.setUniformMatrix4f("modelViewMatrix", mvm);
		shader.setUniformMatrix4f("projectionMatrix", pm);
		for (auto& box : boxes) {
			shader.setUniform3f("color", ofVec3f(box.color.r, box.color.g, box.color.b));
			box.draw();
		}
		shader.setUniform3f("color", ofVec3f(grass.color.r, grass.color.g, grass.color.b));
		grass.draw();
		shader.end();
		ofDisableDepthTest();
	}
    
	void drawWireFrame(ofShader& shader, ofMatrix4x4 mvm, ofMatrix4x4 pm) {
		ofEnableDepthTest();
		shader.begin();
		shader.setUniformMatrix4f("modelViewMatrix", mvm);
		shader.setUniformMatrix4f("projectionMatrix", pm);
		for (auto& box : boxes) {
			shader.setUniform3f("color", ofVec3f(box.color.r, box.color.g, box.color.b));
			box.drawWireFrame();
		}
		shader.setUniform3f("color", ofVec3f(grass.color.r, grass.color.g, grass.color.b));
		grass.drawWireFrame();
		shader.end();
		ofDisableDepthTest();
	}

	void drawBlackWireFrame(ofShader& shader, ofMatrix4x4 mvm, ofMatrix4x4 pm) {
		ofEnableDepthTest();
		shader.begin();
		shader.setUniformMatrix4f("modelViewMatrix", mvm);
		shader.setUniformMatrix4f("projectionMatrix", pm);
		for (auto& box : boxes) {
			shader.setUniform3f("color", ofVec3f(0, 0, 0));
			box.drawWireFrame();
		}
		shader.setUniform3f("color", ofVec3f(0, 0, 0));
		grass.drawWireFrame();
		shader.end();
		ofDisableDepthTest();
	}

};

#endif /* StaticCGScene_h */
