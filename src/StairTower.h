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

#include "AbstractTower.h"

using namespace std;

class StairTower: public AbstractTower {

protected:
    vector<ofPoint> points;
    vector<ofPoint> narrowBasePoints;
    vector<ofPoint> basePoints;

public:
    StairTower(float delay);
    virtual ~StairTower();

    virtual void draw(float scale, int towerLineWidth);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__StairTower__) */
