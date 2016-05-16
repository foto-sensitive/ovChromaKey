#include "ofApp.h"

/*Created by Robert Pavlovskis on 01/18/2016
This is example shows how you can apply a chroma key filter to a 360° media.
Use the slider to adjust the threshold of green and the tolerance of other colours.*/

//--------------------------------------------------------------
void ofApp::setup(){

	//Load Demo Foreground Video
	vid.loadMovie("hands.avi");
	vid.play();
	//Load Background
	img.loadImage("bg.jpg");

	//Prepare quadric for sphere
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);

	//Place camera inside sphere at 0,0,0
	cam.setAutoDistance(false);

	//Dimension
	width = vid.getWidth();
	height = vid.getHeight();

	//Assigns length to array
	pixelout = new unsigned char[width * height * 3];
	pixelin = new unsigned char[width * height * 3];
	pixels = new unsigned char[width * height * 3];

	//Gets pixels from background image
	pixels = img.getPixels();

	//GUI
	gui.setup();
	gui.add(thre.setup("Threshold", 220, 0, 255));
	gui.add(tol.setup("Tolerance", 0, 0, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
	vid.update();

	//Run only if video is updated, conserve CPU
	if (vid.isFrameNew()) {

		//Gets pixels from video
		pixelin = vid.getPixels();

		//Iterate through two dimensional image
		for (i = 0; i < vid.getWidth(); i++) {
			for (j = 0; j < vid.getHeight(); j++) {

				//Map 2D For loop to 1D pixel Array
				pointer = (j*vid.getWidth() + i);
				red = pixelin[pointer * 3 + 0];//red
				green = pixelin[pointer * 3 + 1];//green
				blue = pixelin[pointer * 3 + 2];//blue

				//Compare colour values, Threshold of Green and Tolerance of others
				//Determines weather to draw pixel, based on the green value and other colours present in it.
				if (green <= blue - tol || green <= red - tol || green < thre) {

					pixelout[pointer * 3 + 0] = red;
					pixelout[pointer * 3 + 1] = green;
					pixelout[pointer * 3 + 2] = blue;

				} else {//Draws background if threshold has been exceded
					pixelout[pointer * 3 + 0] = pixels[pointer * 3 + 0];
					pixelout[pointer * 3 + 1] = pixels[pointer * 3 + 1];
					pixelout[pointer * 3 + 2] = pixels[pointer * 3 + 2];
				}
			}
		}
		//Writes pixels to chroma-keyed preview
		preview.loadData(pixelout, vid.getWidth(), vid.getHeight(), GL_RGB);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Place camera inside the sphere
	cam.begin();
	//Map 360° texture to sphere
	myUnwrap.draw(&preview, quadric);
	cam.end();

	gui.draw();

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
