

/*Created by Robert Pavlovskis on 01/18/2016
This is example shows how you can apply a chroma key filter to a 360° media.
Use the slider to adjust the threshold of green and the tolerance of other colours.*/


#pragma once

#include "ofMain.h"
#include "ovWrap.h"
#include "ofxGui.h"

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

		//This class unwraps 360° shots into normal perspective
		ovWrap myUnwrap;

		//Renders the sphere
		GLUquadricObj *quadric;

		//Adds camera and controls
		ofEasyCam cam;

		ofVideoPlayer vid;
		ofImage img;

		//Write masked video to.
		ofTexture preview;

		//Pixel Arrays
		unsigned char * pixelout;
		unsigned char * pixelin;
		unsigned char * pixels;

		//Pixel values
		int red, green, blue, alpha; 
		
        //Dimension
		int width, height;

        //Iterators
		int i, j, pointer;

		//GUI
		ofxPanel gui;
		ofxIntSlider thre, tol;
};
