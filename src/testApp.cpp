#include "testApp.h"
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);

    serial.enumerateDevices();
    serial.setup(0,9600);

    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    // Initialize some variables
    circlePos.x = 10;
    circlePos.y = 10;
    radius = 10.0;

}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(240, 230, 180); // set background to beige
    
    int x1, y1, z1;
    
    if(serial.available() > 0){
        unsigned char buffer[4];
        unsigned char buffer2[4];
        
        memset(buffer, 0, 4);
        memset(buffer2, 0, 4);
        
        serial.readBytes(buffer, 4);
        serial.readBytes(buffer2, 4);
        
        if(buffer[3] =='z'){
            x1 = (int)buffer2[0];
            y1 = (int)buffer2[1];
            z1 = (int)buffer2[2];
        }
        serial.flush();
        serial.writeByte('A');
        
        x1 = ofClamp(x1, 0, 255);
        y1 = ofClamp(y1, 0, 255);
        z1 = ofClamp(z1, 0, 255);
    }

//    if(x1 > 0 && x1 <= 127){
//        quad1 = ofMap(x1, 0, 127, 0, ofGetWindowWidth()/2);
//        circlePos.x = quad1;
//    } else if(x1 > 127 && x1 < 255){
//        quad2 = ofMap(x1, 128, 255, ofGetWindowWidth()/2, ofGetWindowWidth());
//        circlePos.x = quad2;
//    }
//    if(y1 > 0 && y1 <= 127){
//        quad3 = ofMap(y1, 0, 127, 0, ofGetWindowWidth()/2);
//        circlePos.y = quad3;
//    } else if(x1 > 128 && x1 < 255){}{
//        quad4 = ofMap(y1, 128, 255, ofGetWindowWidth()/2, ofGetWindowWidth());
//        circlePos.y = quad4;
//    }
    
//        float max = ofDist(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        xpos = ofMap(x1, 0, 255, 0, ofGetWindowWidth());
        ypos = ofMap(y1, 0, 255, 0, ofGetWindowHeight());
        //zpos = ofMap(z1, 0, 255, 0, max);

        circlePos.x = xpos;
        circlePos.y = ypos;
        radius = z1;
    
//    radius = 30 + cos(ofGetFrameNum()/10.0) * 50;    // modulate the radius 10 to 50
//    circlePos.x += 50.0 * ofGetLastFrameTime();       // Move to the right 20px/sec

//    circlePos.x += xpos * ofGetLastFrameTime();       // Move to the right ACCELEROMETE-Pixels/sec

    // If the circle moves beyond the right side of the screen, pacman
    if(circlePos.x > ofGetWidth()+radius) {
        circlePos.x = -radius;
    }
    cout << "x " << x1  <<  ": "  <<  "xMapped "  << quad2 << "\t"  << "y " << y1  <<  ": "  <<  "yMapped "  << quad4 << "\t"<< "z " << z1 << endl;;

    /*
    
     Use xMap for the x-location of the ellipse.
     yMap for the y-location.
     zMap for the size.
     
     */

}
//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255, 0, 255);    // Set the drawing color
    ofCircle(circlePos.x, circlePos.y, radius);
    
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
