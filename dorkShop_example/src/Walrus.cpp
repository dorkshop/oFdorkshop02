//
//  Walrus.cpp
//  dorkShop_example
//
//  Created by Jennifer Presto on 9/26/13.
//
//

#include "Walrus.h"

// the constructor
// this is where we create the standard, generic, default Walrus

// these values can all be changed, but this is where they will start

Walrus::Walrus() {
    posX = ofGetWindowWidth() * 0.5;
    posY = ofGetWindowHeight() * 0.5;
    size = 50;
}

void Walrus::setup() {
    // Even though we used the name setup(), this is different than the setup()
    // function in testApp. We could've used any name here in the Walrus class.
    // We'll call this function in the setup() function of the testApp,
    // in order to give random values to a Walrus's variables.
    
    velX = ofRandom(-5, 5);
    velY = ofRandom(-4, 4);
        
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
}

void Walrus::move () {
    // we'll add our vel variables to our pos variables so that
    // the Walrus moves a little bit each frame
    
    posX = posX + velX;
    posY += velY; // shorter syntax, but means the same as in posX above
    
    
    // if the Walrus hits a wall, reverse direction
    
    if ( posX > ofGetWindowWidth() || posX < 0) {
        velX = velX * (-1);
    }
    
    if (posY > ofGetWindowHeight() || posY < 0) {
        velY *= (-1); // shorter syntax, but means the same as in velX above
    }
}

void Walrus::display() {
    // head
    ofSetColor(r, g, b);
    ofCircle(posX, posY, size);
    
    // eyes
    ofSetColor(0);
    ofCircle(posX + 25, posY - 5, size/3); // right eye
    ofCircle(posX - 25, posY -5, size/3); // left eye
    
    // tusks
    ofSetColor(200);
    ofRect(posX - 15, posY + 30, 10, 30); // left tusk
    ofRect(posX + 5, posY + 35, 10, 30); // right tusk
}

void Walrus::reset(float _posX, float _posY) {
    posX = _posX;
    posY = _posY;
    
    // ofMap takes a number that's in one range and maps it to another range.
    // Here, we know that _posX is going to be between 0 and the window's width
    // (that is, between 0 and 1024). So we'll take whatever number we get and
    // re-map it to be between 30 and 70.
    // Then we use that number to be the size. So the new size of the Walrus
    // after calling the reset() function will be between 30 and 70, depending
    // on what _posX is. We know that _posX will ultimately wind up being
    // the x-position of our mouse when we click it. We know this because we
    // call this method in the mousePressed() function in testApp.
    // But it doesn't _have_ to be this-- we can use any floating-point
    // number at all).
    
    size = ofMap(_posX, 0, ofGetWindowWidth(), 30, 70);
}