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

	public:
		Grass() {

			// color
			color = ofFloatColor(80 / COLORSCALE, 120 / COLORSCALE, 60 / COLORSCALE);

			// vertices
			float square_size = 200 / SCALE;
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
		Grass grass;

	public:
		StaticCGSceneAttr() {
			ColorBox box_r(ofFloatColor(200 / COLORSCALE, 100 / COLORSCALE, 100 / COLORSCALE), ofVec3f(0, 0, -160 / SCALE));
			ColorBox box_y(ofFloatColor(210 / COLORSCALE, 210 / COLORSCALE, 100 / COLORSCALE), ofVec3f(-200 / SCALE, 0, -60 / SCALE));
			ColorBox box_b(ofFloatColor(70 / COLORSCALE, 100 / COLORSCALE, 130 / COLORSCALE), ofVec3f(140 / SCALE, 0, 40 / SCALE));
			boxes.push_back(box_r);
			boxes.push_back(box_y);
			boxes.push_back(box_b);
		}

		void update() {
			for (auto& box : boxes) {
				box.update();
			}
			grass.update();
		}

		void draw() {
			for (auto& box : boxes) {
				box.draw();
			}
			grass.draw();
		}

		void drawWireFrame() {
			for (auto& box : boxes) {
				box.drawWireFrame();
			}
			grass.drawWireFrame();
		}

	};

}

#endif /* StaticCGSceneAttr_h */
