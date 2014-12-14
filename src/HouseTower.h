//
//  HouseTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__HouseTower__
#define __strongStrongCastle__HouseTower__

#include <stdio.h>
#include <vector>
#include "TowerInterface.h"

using namespace std;

class HouseTower : public TowerInterface {

    ofPoint origin;

    float factor;
    float delay;

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> housePoints;
public:
    HouseTower(float delay);
    ~HouseTower();

    virtual void draw(float scale);
    virtual void buildPoints();
    virtual void update(float medium);
};

#endif /* defined(__strongStrongCastle__HouseTower__) */
