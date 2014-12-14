//
//  BalconyTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__BalconyTower__
#define __strongStrongCastle__BalconyTower__

#include <stdio.h>
#include <vector>
#include "AbstractTower.h"

using namespace std;

class BalconyTower : public AbstractTower {

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> housePoints;
    vector<ofPoint> trapezePoints;

public:
    BalconyTower(float delay);
    virtual ~BalconyTower();

    virtual void draw(float scale, int towerLineWidth);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__BalconyTower__) */
