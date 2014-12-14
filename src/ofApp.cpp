#include "ofApp.h"
#include "Tower.h"
#include "MelonTower.h"
#include "HouseTower.h"
#include "PikeTower.h"
#include "StairTower.h"
#include "ChurchTower.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofShowCursor();

    /**
     *  Setup sound
     */
    soundStream.listDevices();

    /*
     * High quality renderer
     */
    _shivaVGRenderer = ofPtr<ofxShivaVGRenderer>(new ofxShivaVGRenderer);
    ofSetCurrentRenderer(_shivaVGRenderer);
    _shivaVGRenderer->setLineCapStyle(VG_CAP_ROUND);
    _shivaVGRenderer->setLineJoinStyle(VG_JOIN_ROUND);


    int bufferSize = 256;

    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);

    bufferCounter   = 0;
    drawCounter     = 0;
    smoothedVol     = 0.0;
    scaledVol       = 0.0;

    soundAmp        = 2.0f;

    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    /*
     * Towers
     */
    towerCount = 10;
    marginWidth = 20;
    documentSize.x = ofGetWindowWidth() - marginWidth*2;
    documentSize.y = ofGetWindowHeight() - marginWidth*2;

    generateTower();


    /*
     * GUI
     */
    gui = new ofxUICanvas();
    gui->addSpacer();
    gui->addLabel("TOWER CONTROL");
    gui->addSlider("Tower count",3,50,towerCount);
    gui->addSlider("Tower offset",-1000.0f,1000.0f,towerOffset);
    gui->addSpacer();
    gui->addButton("Shuffle towers", false);
    gui->addToggle("Waving towers", wavingTowers);
    gui->addSpacer();
    gui->addLabel("SOUND CONTROL");
    gui->addToggle("Listen sound", listenSound);
    gui->addSlider("Sound amp",1.0f,10.0f,soundAmp);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");

}

//--------------------------------------------------------------
void ofApp::update(){

    if (!lockTowerUpdate) {
        int ratio = left.size() / (float) towers.size();

        for (unsigned int i = 0, j = 0; i < towers.size() && j < left.size(); i++, j+=ratio)
        {
            float medium = 0.0f;
            for (unsigned int mi = j; mi < j+ratio; ++mi)
            {
                medium += left[mi];
            }
            medium /= (int)ratio;
            //medium = ofMap(medium, 0.0, 0.17, 0.0, 1.0, true);

            towers[i]->update(medium * soundAmp, wavingTowers);
        }
    }

    /*
     * Sound
     */
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

    //lets record the volume into an array
    volHistory.push_back( scaledVol );

    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
}


//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    ofTranslate(marginWidth + (towerOffset/2), marginWidth);

    for (unsigned int i = 0; i < (int)towers.size()/2; i++)
    {
        ofPushMatrix();
        ofTranslate((documentSize.x - towerOffset) * (i / (float) towerCount), ofGetWindowHeight()*0.666);
        towers[i]->draw(documentSize.x/towers.size());
        ofPopMatrix();
    }
    for (unsigned int j = towers.size() - 1; j >= towers.size()/2; j--)
    {
        ofPushMatrix();
        ofTranslate((documentSize.x - towerOffset) * (j / (float) towerCount), ofGetWindowHeight()*0.666);
        towers[j]->draw(documentSize.x/towers.size());
        ofPopMatrix();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    documentSize.x = ofGetWindowWidth() - this->marginWidth*2;
    documentSize.y = ofGetWindowHeight() - this->marginWidth*2;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
void ofApp::exit()
{
    gui->saveSettings("settings.xml");
    delete gui;
}

void ofApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.getName() == "Tower count")
    {
        ofxUISlider *slider = e.getSlider();
        towerCount = (int) slider->getScaledValue();
        generateTower();
    }

    if(e.getName() == "Sound amp")
    {
        ofxUISlider *slider = e.getSlider();
        soundAmp = (float) slider->getScaledValue();
    }

    if(e.getName() == "Tower offset")
    {
        ofxUISlider *slider = e.getSlider();
        towerOffset = (int) slider->getScaledValue();
    }

    if(e.getName() == "Shuffle towers")
    {
        generateTower();
    }

    if (e.getName() == "Listen sound")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;

        if (true == toggle->getValue())
        {
            soundStream.start();
        } else {
            soundStream.stop();
        }
    }

    if (e.getName() == "Waving towers")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;

        wavingTowers = (bool) toggle->getValue();
    }


}

void ofApp::generateTower() {

    lockTowerUpdate = true;

    for (unsigned int i = 0; i < towers.size(); ++i) {
        delete towers[i];
    }

    towers.clear();

    for (unsigned int i = 0; i < towerCount; ++i)
    {
        switch  ((int) ofRandom(0,6)) {
            case 0:
                addTower( new MelonTower(i*500.0f) );
                break;
            case 1:
                addTower( new Tower(i*500.0f) );
                break;
            case 2:
                addTower( new StairTower(i*500.0f) );
                break;
            case 3:
                addTower( new HouseTower(i*500.0f) );
                break;
            case 4:
                addTower( new PikeTower(i*500.0f) );
                break;
            case 5:
                addTower( new ChurchTower(i*500.0f) );
                break;

        }
    }

    lockTowerUpdate = false;
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){

    float curVol = 0.0;

    // samples are "interleaved"
    int numCounted = 0;

    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]     = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;

        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }

    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;

    // this is how we get the root of rms :)
    curVol = sqrt( curVol );

    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;

    bufferCounter++;
}

