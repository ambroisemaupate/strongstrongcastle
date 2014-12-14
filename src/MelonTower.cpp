//
//  MelonTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "MelonTower.h"

MelonTower::MelonTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

MelonTower::~MelonTower(){

}

void MelonTower::buildPoints() {
    //Origin
    origin = ofPoint(0.15f, 0.33f);

    melonPoints.push_back(ofPoint( 0.15f,-0.15f ));
    melonPoints.push_back(ofPoint( 0.85f,-0.15f ));
    melonPoints.push_back(ofPoint( 0.85f, 0.33f ));

    // Moving points
    points.push_back(ofPoint( 0.1f,0.45f ));
    points.push_back(ofPoint( 0.9f,0.45f ));


    // Fixed points
    basePoints.push_back(ofPoint( 0.9,1 ));
    basePoints.push_back(ofPoint( 0.1,1 ));
}

void MelonTower::draw(float scale) {
    AbstractTower::draw(scale);

    ofPath path;

    // for ( int i=0; i < melonPoints.size(); i++ ) {
    //     path.lineTo( melonPoints[i].x, melonPoints[i].y + factor);
    // }
    path.moveTo(origin.x, origin.y + factor);
    path.bezierTo(
        melonPoints[0].x, melonPoints[0].y + factor,
        melonPoints[1].x, melonPoints[1].y + factor,
        melonPoints[2].x, melonPoints[2].y + factor
    );
    path.lineTo(origin.x, origin.y + factor);
    path.close();


    //ofPath middlePath;

    path.rectangle(0.0f, 0.33f + factor , 1, 0.12f);
    path.close();


    for ( int i=0; i < points.size(); i++ ) {
        path.lineTo( points[i].x, points[i].y + factor );
    }
    for ( int i=0; i < basePoints.size(); i++ ) {
        path.lineTo( basePoints[i] );
    }

    path.close();
    path.setColor( ofColor( 255, 255, 255 ) );
    path.setStrokeColor(ofColor( 0, 0, 255 ));
    path.setFilled(true);
    path.setStrokeWidth(lineWidth);
    path.scale(scale, scale);
    path.draw(0, 0);
}