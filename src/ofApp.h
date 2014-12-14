#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxShivaVGRenderer.h"
#include "TowerInterface.h"
#include <stdio.h>
#include <vector>

using namespace std;

class ofApp : public ofBaseApp{

    vector<TowerInterface*> towers;

    vector <float> left;
    vector <float> right;
    vector <float> volHistory;

    int     bufferCounter;
    int     drawCounter;
    bool    lockTowerUpdate = false;

    float smoothedVol;
    float scaledVol;
    float soundAmp;

    ofSoundStream soundStream;
    ofPtr<ofxShivaVGRenderer> _shivaVGRenderer;

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


    ofPoint documentSize;
    int marginWidth;
    int towerOffset = 0;
    float towerCount;

    ofxUICanvas *gui;

    void generateTower();

    void exit();
	void guiEvent(ofxUIEventArgs &e);

    void addTower( TowerInterface* tower )
    {
        towers.push_back( tower );
    }

    void audioIn(float * input, int bufferSize, int nChannels);
};
