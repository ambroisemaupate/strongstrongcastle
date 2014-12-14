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
#include "AbstractTower.h"

using namespace std;

class MelonTower : public AbstractTower {

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> melonPoints;
public:
    MelonTower(float delay);
    virtual ~MelonTower();

    virtual void draw(float scale);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__MelonTower__) */
