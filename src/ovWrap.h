#pragma once

#include "ofMain.h"

//This class unwraps 360° shots into normal perspective

class ovWrap : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw(ofTexture *preview, GLUquadricObj *quadric);
		
};
