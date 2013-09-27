#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(50); // set background to dark gray

    // the next line makes the circles more round, but slows your computer down
    ofSetCircleResolution(150);
    
    // we'll call the setup function just for sam
    sam.setup();
    // sam.size = 200; // if you uncomment this line, sam will be bigger than the freds
    
    // here we call the setup function for all the freds
    for (int i = 0; i < NUMFREDS; i++) {
        fred[i].setup();
    }
    
    // in the for loop above, we set up all the freds.
    // But each of the freds is actually an individual object.
    // At any time, therefore, we can access any one of the freds. Here,
    // we're singling out fred #77 and we're making him huge.
    
    // comment out this line to make him the same size as the other freds
    fred[77].size = 400;
}

//--------------------------------------------------------------
void testApp::update(){
    // update() gets called each frame before draw() (below)
    // this is where we usually make changes before drawing
    
    // first we move sam
    sam.move();
    
    // then we move all the freds
    // note that i=i+1 can be written as i++, as we do in other for loops
    for (int i = 0; i < NUMFREDS; i=i+1) {
        fred[i].move();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    // we'll draw sam to the screen
    sam.display();
    
    // then all the freds
    for (int i = 0; i < NUMFREDS; i++) {
        fred[i].display();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    // every time the mouse is pressed, we'll increase sam's size by 10
    sam.size += 10;
    
    // when the mouse is pressed, we call the reset() function on all the freds
    for (int i = 0; i < NUMFREDS; i++) {
        fred[i].reset(x, y); // could also use (mouseX, mouseY) here
    }
    
    // Because the reset function sets the position and _size_ of a Walrus,
    // if we call it on all the freds, we're resetting all their sizes.
    // Therefore, if we want fred #77 to remain bigger than the others, we
    // need to then set his size _again_ after resetting all the freds.
    
    // comment this out if you want fred #77 to blend in
    fred[77].size = 400;
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
