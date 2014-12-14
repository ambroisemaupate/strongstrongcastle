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
#include "AbstractTower.h"

using namespace std;

class HouseTower : public AbstractTower {

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> housePoints;
public:
    HouseTower(float delay);
    virtual ~HouseTower();

    virtual void draw(float scale);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__HouseTower__) */
