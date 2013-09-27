#pragma once

#include "ofMain.h"

// you must include the header files of the classes you create
#include "Walrus.h"

// we define the constant NUMFREDS
// by convention, this is written in all caps
#define NUMFREDS 100

class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    // sam is a standalone Walrus
    Walrus sam;
    
    // fred is an array of Walruses
    Walrus fred[NUMFREDS];
};
