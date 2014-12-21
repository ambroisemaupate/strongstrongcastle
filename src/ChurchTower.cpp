//
//  ChurchTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "ChurchTower.h"

ChurchTower::ChurchTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

ChurchTower::~ChurchTower(){

}

void ChurchTower::buildPoints() {
    //Origin

    housePoints.push_back(ofPoint( 0.5f, 0.3f ));
    housePoints.push_back(ofPoint( 0.15f, 0.3f ));
    housePoints.push_back(ofPoint( 0.5f, 0 ));
    housePoints.push_back(ofPoint( 0.85f, 0.3f ));
    housePoints.push_back(ofPoint( 0.5f, 0.3f ));

    trapezePoints.push_back(ofPoint( 0.15f,0.5f ));
    trapezePoints.push_back(ofPoint( 0.85f,0.5f ));
    trapezePoints.push_back(ofPoint( 1,0.65f ));
    trapezePoints.push_back(ofPoint( 0,0.65f ));
    trapezePoints.push_back(ofPoint( 0.15f,0.5f ));

    // Moving points
    points.push_back(ofPoint( 0,0.65f ));
    points.push_back(ofPoint( 1,0.65f ));

    // Fixed points
    basePoints.push_back(ofPoint( 1,1 ));
    basePoints.push_back(ofPoint( 0,1 ));
}

void ChurchTower::draw(float scale, int towerLineWidth) {
    AbstractTower::draw(scale, towerLineWidth);

    ofPath path;

    for ( int i=0; i < housePoints.size(); i++ ) {
        path.lineTo( housePoints[i].x, housePoints[i].y + factor );
    }
    path.close();

    path.rectangle(0.15f, 0.3f + factor , 0.7f, 0.2f);
    path.close();

    for ( int i=0; i < trapezePoints.size(); i++ ) {
        path.lineTo( trapezePoints[i].x, trapezePoints[i].y + factor );
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
    path.draw(0, this->volume);
}