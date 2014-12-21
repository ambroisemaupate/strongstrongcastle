#include "ofApp.h"
#include "Tower.h"
#include "MelonTower.h"
#include "HouseTower.h"
#include "PikeTower.h"
#include "StairTower.h"
#include "ChurchTower.h"
#include "NippleTower.h"
#include "BalconyTower.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofShowCursor();
    /*
     * High quality renderer
     */
    _shivaVGRenderer = ofPtr<ofxShivaVGRenderer>(new ofxShivaVGRenderer);
    ofSetCurrentRenderer(_shivaVGRenderer);
    _shivaVGRenderer->setLineCapStyle(VG_CAP_ROUND);
    _shivaVGRenderer->setLineJoinStyle(VG_JOIN_ROUND);

    /**
     *  Setup sound
     */
    soundStream.listDevices();



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
    documentSize.x = ofGetWindowWidth() - marginWidth * 2;
    documentSize.y = ofGetWindowHeight() - marginWidth * 2;

    generateTower();

    /*
     * GUI
     */
    gui = new ofxUISuperCanvas("", OFX_UI_FONT_MEDIUM);
    gui->addSpacer();
    gui->addLabel("TOWER CONTROL");
    gui->addSlider("Tower count", 3, 50, towerCount);
    gui->addSlider("Tower offset", -1000.0f, 1000.0f, towerOffset);
    gui->addSlider("Line width", 1, 10, towerLineWidth);
    gui->addSpacer();
    gui->addButton("Shuffle towers", false);
    gui->addToggle("Waving towers", wavingTowers);
    gui->addSpacer();
    gui->addLabel("SOUND CONTROL");
    gui->addToggle("Listen sound", listenSound);
    gui->addSlider("Sound amp",1.0f,10.0f,soundAmp);
    gui->addSpacer();
    gui->addButton("Save PDF", false);
    gui->addSlider("Zoom", 0.5f, 10.0f, &viewportScale);
    gui->addButton("Reset view", false);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");


    viewportOrigin = ofPoint(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5);
    viewportUserOrigin = viewportOrigin;
}

//--------------------------------------------------------------
void ofApp::update(){
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
            
            float cosAbsiss = ofMap(i, 0.0f, towers.size()-1, -10.0f, 10.0f);
            float volAbsiss = ((cos(cosAbsiss/PI)*0.5f) + 0.5f) * scaledVol;
            
            towers[i]->update(medium * soundAmp, volAbsiss, wavingTowers);
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){

    if( oneShot ){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }
    ofPushMatrix();
    // User pan
    ofTranslate(viewportUserOrigin);

    ofPushMatrix();
    // Zoom
    ofScale(viewportScale, viewportScale);

    ofPushMatrix();
    // Center viewport to center zoom
    ofTranslate(ofGetWindowWidth()*-0.5, ofGetWindowHeight()*-0.5);

    for (unsigned int i = 0; i < (int)towers.size()/2; i++)
    {
        ofPushMatrix();
        ofTranslate((documentSize.x - towerOffset) * (i / (float) towerCount), ofGetWindowHeight()*0.666);
        towers[i]->draw(documentSize.x/towers.size(), towerLineWidth);
        ofPopMatrix();
    }
    for (unsigned int j = towers.size() - 1; j >= towers.size()/2; j--)
    {
        ofPushMatrix();
        ofTranslate((documentSize.x - towerOffset) * (j / (float) towerCount), ofGetWindowHeight()*0.666);
        towers[j]->draw(documentSize.x/towers.size(), towerLineWidth);
        ofPopMatrix();
    }
    ofPopMatrix();
    ofPopMatrix();
    ofPopMatrix();

    if( oneShot ){
        ofEndSaveScreenAsPDF();
        oneShot = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
        case ' ':
            gui->toggleVisible();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    if (userPanInit)
    {
        ofPoint currentDeltaPoint = ofPoint(x - mouseOrigin.x, y - mouseOrigin.y);
        viewportUserOrigin = viewportOrigin + currentDeltaPoint;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if (!(gui->isHit(x, y)))
    {
        userPanInit = true;
        mouseOrigin = ofPoint(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    viewportOrigin = viewportUserOrigin;
    userPanInit = false;
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

        if (true == toggle->getValue()) {
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

    if (e.getName() == "Line width")
    {
        ofxUISlider *slider = e.getSlider();
        towerLineWidth = (int) slider->getScaledValue();
    }

    if (e.getName() == "Zoom")
    {
        ofxUISlider *slider = e.getSlider();
        viewportScale = (float) slider->getScaledValue();
    }

    if (e.getName() == "Save PDF")
    {
        oneShot = true;
    }
    if (e.getName() == "Reset view")
    {
        viewportOrigin = ofPoint(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5);
        viewportUserOrigin = viewportOrigin;
        viewportScale = 1.0f;
    }

}

void ofApp::generateTower() {

    lockTowerUpdate = true;

//    for (unsigned int i = 0; i < towers.size(); ++i) {
//        if(NULL != towers[i]) {
//            delete towers[i];
//        }
//    }

    towers.clear();

    for (unsigned int i = 0; i < towerCount; ++i)
    {
        switch  ((int) ofRandom(0,8)) {
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
            case 6:
                addTower( new NippleTower(i*500.0f) );
                break;
            case 7:
                addTower( new BalconyTower(i*500.0f) );
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

