#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define MY_PORT 12345
#define REMOTE_PORT 54321

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxOscReceiver oscReciver;
ofxOscSender oscSender;
      float oscx = 0.0;
      float oscy = 0.0;
};
