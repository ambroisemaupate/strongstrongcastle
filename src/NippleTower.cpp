//
//  NippleTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "NippleTower.h"

NippleTower::NippleTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

NippleTower::~NippleTower(){

}

void NippleTower::buildPoints() {
    //Origin

    nippleBasePoints.push_back(ofPoint( 0.9f, 0.57f ));
    nippleBasePoints.push_back(ofPoint( 0.1f, 0.57f ));

    nipplePoints.push_back(ofPoint( 0.1, 0.57f )); // cp1
    nipplePoints.push_back(ofPoint( 0.06f, 0.35f )); // cp2
    nipplePoints.push_back(ofPoint( 0.3f, 0.24f )); // pt1

    nipplePoints.push_back(ofPoint( 0.3f, 0.24f )); // cp1
    nipplePoints.push_back(ofPoint( 0.5f, 0.21f )); // cp2
    nipplePoints.push_back(ofPoint( 0.5f, 0 )); // pt2

    nipplePoints.push_back(ofPoint( 0.5f, 0.21f ));
    nipplePoints.push_back(ofPoint( 0.7f,0.24f ));
    nipplePoints.push_back(ofPoint( 0.7f,0.24f )); // pt3

    nipplePoints.push_back(ofPoint( 0.94f,0.35f ));
    nipplePoints.push_back(ofPoint( 0.9f,0.57f ));
    nipplePoints.push_back(ofPoint( 0.9f,0.57f )); // pt4

    nipplePoints.push_back(ofPoint( 0.9f,0.57f ));
    nipplePoints.push_back(ofPoint( 0.5f,0.57f ));
    nipplePoints.push_back(ofPoint( 0.5f,0.57f )); // pt5

    // Moving points
    points.push_back(ofPoint( 0.2f,0.57f ));
    points.push_back(ofPoint( 0.8f,0.57f ));

    // Fixed points
    basePoints.push_back(ofPoint( 0.8,1 ));
    basePoints.push_back(ofPoint( 0.2,1 ));
}

void NippleTower::draw(float scale, int towerLineWidth) {
    AbstractTower::draw(scale, towerLineWidth);

    ofPath path;

    for ( int i=0; i < nippleBasePoints.size(); i++ ) {
        path.lineTo( nippleBasePoints[i].x, nippleBasePoints[i].y + factor );
    }

    for ( int i=0; i < nipplePoints.size(); i+=3 ) {
        path.bezierTo(
            nipplePoints[i].x, nipplePoints[i].y + factor,
            nipplePoints[i + 1].x, nipplePoints[i + 1].y + factor,
            nipplePoints[i + 2].x, nipplePoints[i + 2].y + factor
        );
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