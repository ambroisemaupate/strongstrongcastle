//
//  HouseTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "HouseTower.h"

HouseTower::HouseTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

HouseTower::~HouseTower(){

}

void HouseTower::update(float medium) {
    factor = (abs(medium)*5) * -1;
}

void HouseTower::buildPoints() {
    //Origin

    housePoints.push_back(ofPoint( 0.1f, 0.25f ));
    housePoints.push_back(ofPoint( 0.5f, 0 ));
    housePoints.push_back(ofPoint( 0.9f, 0.25f ));

    // Moving points
    points.push_back(ofPoint( 0.1f,0.25f ));
    points.push_back(ofPoint( 0.9f,0.25f ));


    // Fixed points
    basePoints.push_back(ofPoint( 0.9,1 ));
    basePoints.push_back(ofPoint( 0.1,1 ));
}

void HouseTower::draw(float scale) {

    int lineWidth = 6 * scale/100.0f;
    lineWidth = lineWidth > 1 ? lineWidth : 1;

    ofPath path;

    for ( int i=0; i < housePoints.size(); i++ ) {
        path.lineTo( housePoints[i].x, housePoints[i].y + factor );
    }
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