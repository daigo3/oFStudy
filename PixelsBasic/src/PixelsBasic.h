#pragma once

#include "ofMain.h"

class PixelsBasic: public ofBaseApp{
  
public:
  void setup();
  void draw();
  
  void keyPressed  (int key);
  
  ofImage image, modImage;
  
};
