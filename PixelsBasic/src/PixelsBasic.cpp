#include "PixelsBasic.h"

//--------------------------------------------------------------
void PixelsBasic::setup(){
  image.loadImage("portrait.jpg");
  modImage.allocate(image.getWidth(), image.getHeight(), OF_IMAGE_COLOR);
  modImage.getPixelsRef() = image.getPixelsRef();
  
  // get the pixels onto the graphic card
  modImage.update();
}

//--------------------------------------------------------------
void PixelsBasic::draw(){
  image.draw(50, 50);
  modImage.draw(image.getWidth() + 100, 50);
}

//--------------------------------------------------------------
void PixelsBasic::keyPressed(int key){
  cout << key << endl;
  switch (key) {
    case 115: // s
      modImage.getPixelsRef().swapRgb();
      break;
    case 114: // r
    {
      ofPixels p;
      p = modImage.getPixelsRef();
      p.rotate90(1);
      modImage.resize(modImage.getHeight(), modImage.getWidth());
      modImage.getPixelsRef() = p;
      break;
    }
    case 109: // m
      modImage.getPixelsRef().mirror(true, true);
      break;
    case 113: // p
    {
      ofColor cl(255, 255, 0);
      modImage.getPixelsRef().setColor(mouseX - 500, mouseY - 50, cl);
      break;
    }
    case 122: // z
      modImage.getPixelsRef().resize(200, 200);
      break;
    case 99:  // c
      modImage.getPixelsRef() = image.getPixelsRef();
      break;
    default:
      break;
  }
  
  modImage.update();
}

