//
//  PikeTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "PikeTower.h"

PikeTower::PikeTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

PikeTower::~PikeTower(){

}

void PikeTower::buildPoints() {
    //Origin
    housePoints.push_back(ofPoint( 0.5f, 0.7f ));
    housePoints.push_back(ofPoint( 0.1f, 0.7f ));
    housePoints.push_back(ofPoint( 0.5f, -0.1f ));
    housePoints.push_back(ofPoint( 0.9f, 0.7f ));
    housePoints.push_back(ofPoint( 0.5f, 0.7f ));

    // Moving points
    points.push_back(ofPoint( 0.2f,0.7f ));
    points.push_back(ofPoint( 0.8f,0.7f ));


    // Fixed points
    basePoints.push_back(ofPoint( 0.8f,1 ));
    basePoints.push_back(ofPoint( 0.2f,1 ));
}

void PikeTower::draw(float scale, int towerLineWidth) {
    AbstractTower::draw(scale, towerLineWidth);
    ofPath path;

    for ( int i=0; i < housePoints.size(); i++ ) {
        path.lineTo( housePoints[i].x, housePoints[i].y + factor );
    }
    path.lineTo( housePoints[0].x, housePoints[0].y + factor );
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