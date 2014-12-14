//
//  StairTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__StairTower__
#define __strongStrongCastle__StairTower__

#include <stdio.h>
#include <vector>

#include "TowerInterface.h"

using namespace std;

class StairTower: public TowerInterface {

protected:
    ofPoint origin;

    float factor;
    float delay;

    vector<ofPoint> points;
    vector<ofPoint> narrowBasePoints;
    vector<ofPoint> basePoints;

public:
    StairTower(float delay);
    virtual ~StairTower();

    virtual void update(float medium);
    virtual void draw(float scale);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__StairTower__) */
