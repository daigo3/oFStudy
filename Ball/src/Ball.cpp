//
//  Ball.cpp
//  Ball
//
//  Created by daigo3 on 1/27/13.
//
//

#include <iostream>
#include "Ball.h"

using namespace std;

Ball::Ball() {
  mass = ofRandom(3.0) + 1.0;
  bounce = 0.9;
  location.x = ofRandom(ofGetWidth());
  location.y = 0;
}

void Ball::updateBall() {
  // add the acceleration to the velocity
  // and then add the velocity to the location
  velocity += acceleration;
  location += velocity;
  
  acceleration *= 0.5;
  
  if(location.y > ofGetWindowSize().y - 50) {
    velocity.y *= -bounce;
    location.y = ofGetWindowSize().y - 50;
  }
  if(location.y < 0) {
    velocity.y *= -bounce;
    location.y = 0;
  }
  
  if(location.x > ofGetWindowSize().x) {
    velocity.x += -bounce;
    location.x = 1000;
  }
  
  if(location.x < 0) {
    velocity.x *= -bounce;
    location.x = 0;
  }
}

void Ball::drawFrame() {
  ofSetColor(color);
  ofCircle(location.x, location.y, 50);
}

void Ball::collision(Ball& b1) {
  cout << b1.mass << " " << b1.location.x << " " << b1.location.y << endl;
  float newMass,
        diff,
        angle,
        newX,
        newY,
        newVelocityX,
        newVelocityY,
        fy21,
        sign;
  
  newMass = b1.mass / mass;
  newX = b1.location.x - location.x;
  newY = b1.location.y - location.y;
  newVelocityX = b1.velocity.x - velocity.x;
  newVelocityY = b1.velocity.y - velocity.y;
  
  if( (newVelocityX * newX + newVelocityY * newY) >= 0 ) return;
  
  fy21 = fabs(newY);
  if( fabs(newX) < fy21 ) {
    if(newX>0) {
      sign = -1;
    } else {
      sign = 1;
    }
    
    newX = fy21 * sign;
  }
  
  angle = newY / newX;
  diff = -2 * (newVelocityX + angle * newVelocityY) / ((1 + angle * angle) * (1 + newMass));
  b1.velocity.x = b1.velocity.x + diff;
  b1.velocity.y = b1.velocity.y + angle * diff;
  velocity.x = velocity.x - newMass * diff;
  velocity.y = velocity.y - angle * newMass * diff;
}

void Ball::addForce(ofVec2f force) {
  force /= mass;
  acceleration += force;
}
