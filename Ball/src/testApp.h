#pragma once

#include "ofMain.h"
#include "Ball.h"

#define COUNT 3

class testApp : public ofBaseApp{
  
public:
  void setup();
  void update();
  void draw();
  
  void mouseMoved(int x, int y );
  
  void drawConnectors();
  void checkCollision();
  
  ofVec2f gravity;
  
  Ball balls[3];
};
