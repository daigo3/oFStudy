#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
  gravity = ofVec3f(0.0, 5.0f);
  balls[0].color[0] = 0;
  balls[1].color[1] = 0;
  balls[2].color[2] = 0;
  
  ofBackground(255);
  
  // for smooth animation
  ofSetVerticalSync(true);
  ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
  for(int i = 0; i < COUNT; i++) {
    balls[i].addForce(gravity);
    balls[i].updateBall();
  }
  
  checkCollision();
}

//--------------------------------------------------------------
void testApp::draw(){
  for(int i = 0; i < COUNT; i++) {
    balls[i].drawFrame();
    
    drawConnectors();
    
    ofSetColor(255, 0, 0);
    ofSetLineWidth(2);
    
    float midx = ofGetWidth() / 2;
    float midy = ofGetHeight() / 2;
    ofLine(midx, midy, midx + (gravity.x * 200.f), midy + (gravity.y * 200.f));
  }
}

void testApp::drawConnectors() {
  ofSetColor(0, 0, 0);
  ofSetLineWidth(1);
  for(int i = 0; i < COUNT; i++) {
    for(int j = i + 1; j < COUNT; j++) {
      ofLine(balls[i].location.x, balls[i].location.y, balls[j].location.x, balls[j].location.y);
    }
  }
}

void testApp::checkCollision() {
  for(int i = 0; i < COUNT; i++) {
    for(int j = i + 1; j < COUNT; j++) {
      if(ofDist(balls[i].location.x, balls[i].location.y,
                balls[j].location.x, balls[j].location.y) < 100) {
        balls[i].collision(balls[j]);
      }
    }
  }
}


//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
  gravity.set(float(x) / ofGetWidth() - 0.5, (float)y / ofGetHeight() - 0.5);
}