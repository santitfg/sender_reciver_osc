#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    oscReciver.setup(MY_PORT);
    oscSender.setup("localhost",REMOTE_PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    while (oscReciver.hasWaitingMessages()) {
       ofxOscMessage m;
       oscReciver.getNextMessage(&m);

       if (m.getAddress() == "/position") {
         oscx = m.getArgAsFloat(0);
         oscy = m.getArgAsFloat(1);
       }
     }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(oscx * ofGetWidth(), oscy*ofGetHeight(), 64);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress("/position");
    m.addFloatArg(float(mouseX)/float(ofGetWidth()));
    m.addFloatArg(float(mouseY)/float(ofGetHeight()));
    oscSender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
