//
//  BalconyTower.cpp
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//
#include "ofApp.h"
#include "BalconyTower.h"

BalconyTower::BalconyTower(float delay){

    this->delay = delay;

    this->buildPoints();
}

BalconyTower::~BalconyTower(){

}

void BalconyTower::buildPoints() {
    //Origin

    housePoints.push_back(ofPoint( 0.5f, 0.24f ));
    housePoints.push_back(ofPoint( 0.24f, 0.24f ));
    housePoints.push_back(ofPoint( 0.5f, 0 ));
    housePoints.push_back(ofPoint( 0.76f, 0.24f ));
    housePoints.push_back(ofPoint( 0.5f, 0.24f ));


    trapezePoints.push_back(ofPoint( 0.5f,0.71f ));
    trapezePoints.push_back(ofPoint( 0.24f,0.71f ));
    trapezePoints.push_back(ofPoint( 0.14f,0.6f ));
    trapezePoints.push_back(ofPoint( 0.86f,0.6f ));
    trapezePoints.push_back(ofPoint( 0.76f,0.71f ));
    trapezePoints.push_back(ofPoint( 0.5f,0.71f ));

    // Moving points
    points.push_back(ofPoint( 0.24f,0.71f ));
    points.push_back(ofPoint( 0.76f,0.71f ));

    // Fixed points
    basePoints.push_back(ofPoint( 0.76f,1 ));
    basePoints.push_back(ofPoint( 0.24f,1 ));
}

void BalconyTower::draw(float scale, int towerLineWidth) {
    AbstractTower::draw(scale, towerLineWidth);

    ofPath path;

    for ( int i=0; i < housePoints.size(); i++ ) {
        path.lineTo( housePoints[i].x, housePoints[i].y + factor );
    }
    path.close();

    path.rectangle(0.24f, 0.24f + factor , 0.52f, 0.16f);
    path.close();

    path.rectangle(0.14f, 0.4f + factor , 0.72f, 0.2f);
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
