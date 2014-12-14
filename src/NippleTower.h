//
//  NippleTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__NippleTower__
#define __strongStrongCastle__NippleTower__

#include <stdio.h>
#include <vector>
#include "AbstractTower.h"

using namespace std;

class NippleTower : public AbstractTower {

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> nipplePoints;
    vector<ofPoint> nippleBasePoints;

public:
    NippleTower(float delay);
    virtual ~NippleTower();

    virtual void draw(float scale, int towerLineWidth);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__NippleTower__) */
