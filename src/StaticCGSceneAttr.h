//
//  StaticCGSceneAttr.h
//  demoViewer
//
//  Created by ryoheikomiyama on 2017/04/23.
//
//

#ifndef StaticCGSceneAttr_h
#define StaticCGSceneAttr_h

// meter or centimeter
#define METERSCALE
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

namespace scgsa {

	class ColorBox {

		ofMesh mesh;
		ofFloatColor color;
		ofVec3f pos;

	public:
		ColorBox(ofFloatColor color, ofVec3f pos) {

			// color, pos
			this->color = color;
			this->pos = pos;

			// vertices
			float box_size = 60 / SCALE;
			vector<ofVec3f> vertices = {
				ofVec3f(0, 0, 0)+pos,
				ofVec3f(0, box_size, 0)+pos,
				ofVec3f(box_size, box_size, 0)+pos,
				ofVec3f(box_size, 0, 0)+pos,
				ofVec3f(0, 0, box_size)+pos,
				ofVec3f(0, box_size, box_size)+pos,
				ofVec3f(box_size, box_size, box_size)+pos,
				ofVec3f(box_size, 0, box_size)+pos
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

		void update() {}

		void draw() {
			mesh.draw();
		}

		void drawWireFrame() {
			mesh.drawWireframe();
		}

	};


	class Grass {

		ofMesh mesh;
		ofFloatColor color;
        ofVec3f pos;

	public:
		Grass(ofFloatColor color, ofVec3f pos) {

			this->color = color;
            this->pos = pos;

			// vertices
			vector<ofVec3f> vertices = {
                ofVec3f(0, 0, 0) + pos,
                ofVec3f(200/SCALE, 0, 0) + pos,
                ofVec3f(200/SCALE, 0, 100/SCALE) + pos,
                ofVec3f(0, 0, 100/SCALE) + pos
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

		void update() {}

		void draw() {
			mesh.draw();
		}

		void drawWireFrame() {
			mesh.drawWireframe();
		}


	};




	class StaticCGSceneAttr {

		vector<ColorBox> boxes;
		vector<Grass> grasses;

	public:
		StaticCGSceneAttr() {
			ColorBox box_r(ofFloatColor(200 / COLORSCALE, 100 / COLORSCALE, 100 / COLORSCALE), ofVec3f(0, 0, -160 / SCALE));
			ColorBox box_y(ofFloatColor(210 / COLORSCALE, 210 / COLORSCALE, 100 / COLORSCALE), ofVec3f(-200 / SCALE, 0, -60 / SCALE));
			ColorBox box_b(ofFloatColor(70 / COLORSCALE, 100 / COLORSCALE, 130 / COLORSCALE), ofVec3f(140 / SCALE, 0, 40 / SCALE));
			boxes.push_back(box_r);
			boxes.push_back(box_y);
			boxes.push_back(box_b);
			ColorBox box_r_black(ofFloatColor(0, 0, 0), ofVec3f(0, 0, -160 / SCALE));
			ColorBox box_y_black(ofFloatColor(0, 0, 0), ofVec3f(-200 / SCALE, 0, -60 / SCALE));
			ColorBox box_b_black(ofFloatColor(0, 0, 0), ofVec3f(140 / SCALE, 0, 40 / SCALE));
			boxes.push_back(box_r_black);
			boxes.push_back(box_y_black);
			boxes.push_back(box_b_black);

            for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                    Grass grass(ofFloatColor(80 / COLORSCALE, 120 / COLORSCALE, 60 / COLORSCALE), ofVec3f(2*(i-1)*100/SCALE, 0, (j-2)*100/SCALE));
                    grasses.push_back(grass);
                }
            }
            for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                    Grass grass_black(ofFloatColor(0, 0, 0), ofVec3f(2*(i-1)*100/SCALE, 0, (j-2)*100/SCALE));
                    grasses.push_back(grass_black);
                }
            }
		}

		void update() {
			for (auto& box : boxes) {
				box.update();
			}
			for (auto& grass : grasses) {
				grass.update();
			}
		}

		void draw() {
			for (int i = 0; i < 3; i++) {
				boxes[i].draw();
			}
            for (int i=0; i<8; i++){
                grasses[i].draw();
            }
		}

		void drawWireFrame() {
			for (int i = 0; i < 3; i++) {
				boxes[i].drawWireFrame();
			}
            for (int i=0; i<8; i++){
                grasses[i].drawWireFrame();
            }
		}

		void drawBlackWireFrame() {
			for (int i = 3; i < 6; i++) {
				boxes[i].drawWireFrame();
			}
            for (int i=8; i<16; i++){
                grasses[i].drawWireFrame();
            }
		}

	};

}

#endif /* StaticCGSceneAttr_h */
