//
//  PikeTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__PikeTower__
#define __strongStrongCastle__PikeTower__

#include <stdio.h>
#include <vector>
#include "TowerInterface.h"

using namespace std;

class PikeTower : public TowerInterface {

    ofPoint origin;

    float factor;
    float delay;

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> housePoints;
public:
    PikeTower(float delay);
    virtual ~PikeTower();

    virtual void draw(float scale);
    virtual void buildPoints();
    virtual void update(float medium);
};

#endif /* defined(__strongStrongCastle__PikeTower__) */
