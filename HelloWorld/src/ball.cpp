//
//  ball.cpp
//  HelloWorld
//
//  Created by daigo3 on 1/26/13.
//
//

#include "ball.h"

Ball::Ball() {
  color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
  x = ofRandom( ofGetWindowWidth() );
  y = ofRandom( ofGetWindowHeight() );
}

void Ball::moveTo(int _xDistiny, int _yDistiny) {
  x += (_xDistiny - x) * 0.1;
  y += (_yDistiny - y) * 0.1;
}

void Ball::draw() {
  ofSetColor(color);
  ofFill();
  ofCircle( x, y, 30 );
}

