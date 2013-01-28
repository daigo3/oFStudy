//
//  Ball.h
//  Ball
//
//  Created by daigo3 on 1/27/13.
//
//

#ifndef __Ball__Ball__
#define __Ball__Ball__

#include "ofMain.h"
#include <iostream>

class Ball {
public:
  Ball();
    
  void addForce(ofVec2f force);
  void updateBall();
  ofVec2f location;
  
  ofVec2f velocity;
  ofVec2f acceleration;
  float mass; // how heady are we
  float maximum_velocity;
  
  float bounce;
  ofColor color;
  
  void drawFrame();
  void collision(Ball &b1);

};

#endif /* defined(__Ball__Ball__) */
