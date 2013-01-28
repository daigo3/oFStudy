//
//  ball.h
//  HelloWorld
//
//  Created by daigo3 on 1/26/13.
//
//

#ifndef __HelloWorld__ball__
#define __HelloWorld__ball__

#include "ofMain.h"

class Ball {
public:
  // Constructor
  Ball();
  
  // Mehods
  void moveTo(int _xDestiny, int _yDestiny);
  void draw();
  
  // Properties
  int x;
  int y;
  ofColor color;
};

#endif /* defined(__HelloWorld__ball__) */
