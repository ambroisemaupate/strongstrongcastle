//
//  MelonTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__MelonTower__
#define __strongStrongCastle__MelonTower__

#include <stdio.h>
#include <vector>
#include "TowerInterface.h"

using namespace std;

class MelonTower : public TowerInterface {

    ofPoint origin;

    float factor;
    float delay;

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> melonPoints;
public:
    MelonTower(float delay);
    ~MelonTower();

    virtual void draw(float scale);
    virtual void buildPoints();
    virtual void update(float medium);
};

#endif /* defined(__strongStrongCastle__MelonTower__) */
