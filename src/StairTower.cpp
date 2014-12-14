//
//  StairTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#include "ofApp.h"
#include "StairTower.h"

StairTower::StairTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

StairTower::~StairTower(){

}

void StairTower::buildPoints() {
    //Origin
    origin = ofPoint(0, 0);

    // Moving points
    points.push_back(ofPoint( 0.5f,0.25f ));
    points.push_back(ofPoint( 0,0.25f ));
    points.push_back(ofPoint( 0,0.0f ));
    points.push_back(ofPoint( 0.143f,0 ));
    points.push_back(ofPoint( 0.143f,0.143f ));
    points.push_back(ofPoint( 0.286f,0.143f ));
    points.push_back(ofPoint( 0.286f,0 ));
    points.push_back(ofPoint( 0.429f,0 ));
    points.push_back(ofPoint( 0.429f,0.143f ));
    points.push_back(ofPoint( 0.572f,0.143f ));
    points.push_back(ofPoint( 0.572f,0 ));
    points.push_back(ofPoint( 0.715f,0 ));
    points.push_back(ofPoint( 0.715f,0.143f ));
    points.push_back(ofPoint( 0.858f,0.143f ));
    points.push_back(ofPoint( 0.858f,0 ));
    points.push_back(ofPoint( 1.0f,0 ));
    points.push_back(ofPoint( 1.0f,0.25f ));
    points.push_back(ofPoint( 0.5f,0.25f ));

    // Fixed points
    narrowBasePoints.push_back(ofPoint( 0.9f,0.37f ));
    narrowBasePoints.push_back(ofPoint( 0.1f,0.37f ));

    // Fixed points
    basePoints.push_back(ofPoint( 0.1f,1 ));
    basePoints.push_back(ofPoint( 0.9f,1 ));
}

void StairTower::draw(float scale, int towerLineWidth) {
    AbstractTower::draw(scale, towerLineWidth);

    ofPath path;

    for ( int i=0; i < points.size(); i++ ) {
        path.lineTo( points[i].x, points[i].y + factor);
    }
    path.close();

    path.rectangle(0.05f, 0.25f + factor , 0.9f, 0.12f);
    path.close();

    for ( int i=0; i < narrowBasePoints.size(); i++ ) {
        path.lineTo( narrowBasePoints[i].x, narrowBasePoints[i].y + factor);
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