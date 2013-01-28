#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofSetCircleResolution(200);
  ofBackground(255, 255, 255);
  ofSetVerticalSync(true);
  
  fillColor.set(255, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
  fillColor.setHue(fillColor.getHue() + 1);
  if(fillColor.getHue() > 254) {
    fillColor.setHue(0);
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  // circle
  // ==========================
  ofBackground(255, 255, 255);
  ofSetColor(fillColor);
  ofFill();
  ofCircle(100, 400, 100);
  
  ofNoFill();
  ofSetLineWidth(10);
  ofSetColor(fillColor);
  ofCircle(400, 400, 200);
  
}