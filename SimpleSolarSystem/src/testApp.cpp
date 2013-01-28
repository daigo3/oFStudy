#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofSetFrameRate(60);
  ofSetCircleResolution(100);
  ofSetVerticalSync(true);
  
  angle = 0;
  
  gradientStart.set(127, 127, 127);
  gradientEnd.set(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
  angle -= 0.02f;
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackgroundGradient(gradientStart, gradientEnd);
  
  ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ( angle * RAD_TO_DEG);
      ofFill();
  
      // Sun
      ofSetColor(252, 242, 203);
      ofCircle(0, 0, 80);
  
      // Mercury
      ofSetColor(200, 0, 0);
      ofCircle(80, 80, 15);
  
      // Venus
      ofRotateZ(30);
      ofSetColor(0, 200, 0);
      ofCircle(120, 120, 28);
  
      // Earth
      ofRotate(200, 0, 0, 1);
      ofSetColor(0, 0, 200);
      ofCircle(180, 180, 24);
  
      ofPushMatrix();
        ofTranslate(180, 180);
  
        //Moon
        ofRotateZ(angle * RAD_TO_DEG * 2);
        ofSetColor(255);
        ofCircle(30, 30, 6);
      ofPopMatrix();
  
  ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}