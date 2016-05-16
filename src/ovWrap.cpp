#include "ovWrap.h"

//This class unwraps 360° shots into normal perspective

//--------------------------------------------------------------
void ovWrap::setup(){

}

//--------------------------------------------------------------
void ovWrap::update(){

}

//--------------------------------------------------------------
void ovWrap::draw(ofTexture *preview, GLUquadricObj *quadric){

	ofSetColor(255, 255, 255);

	//Binds the image to sphere
	preview->bind();

	//Positions it in right orientation
	ofPushMatrix();
	ofRotateX(90);

	//Apply operations to texture matrix
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();

	//Scale texture to sphere
	ofScale(preview->getWidth(), preview->getHeight());

	//Apply operations to model matrix
	glMatrixMode(GL_MODELVIEW);

	//Enable depth comparisons, needed so you see the correct planes from your perspective
	glEnable(GL_DEPTH_TEST);
	//Disables the use of ARB textures, has to be disabled for drawing sphere
	ofDisableArbTex();

	gluSphere(quadric, 200, 100, 100);

	//Disables depth comparisons, needed for performing texture operations
	glDisable(GL_DEPTH_TEST);
	//Enables the use of ARB textures, needed to bind textures
	ofEnableArbTex(); //needed for textures to work with gluSphe

	//Apply operations to texture matrix
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);

	//Determines weather to unbind video or image
	preview->unbind();

	ofPopMatrix();
}
