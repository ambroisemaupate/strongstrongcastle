//
//  Tower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "Tower.h"
#include "ofApp.h"

Tower::Tower(float delay){

    this->delay = delay;

    this->buildPoints();
}

Tower::~Tower(){

}

void Tower::buildPoints() {
    //Origin
    origin = ofPoint(0, 0);

    // Moving points
    points.push_back(ofPoint( 0,0.143f ));
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


    // Fixed points
    basePoints.push_back(ofPoint( 1,1 ));
    basePoints.push_back(ofPoint( 0,1 ));
}

void Tower::draw(float scale, int towerLineWidth) {

    AbstractTower::draw(scale, towerLineWidth);

    ofPath path;

    for ( int i=0; i < points.size(); i++ ) {
        path.lineTo( points[i].x, points[i].y + factor);
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
