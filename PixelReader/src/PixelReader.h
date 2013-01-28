#pragma once

#include "ofMain.h"

class PixelReader : public ofBaseApp{
  
public:
  void setup();
  void update();
  void draw();
  void keyPressed  (int key);
  
  ofImage pic;
  int location;
  int fullSize;
  ofPixels pixels;
  bool drawPixelGrid;
};