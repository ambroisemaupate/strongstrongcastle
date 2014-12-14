//
//  ChurchTower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__ChurchTower__
#define __strongStrongCastle__ChurchTower__

#include <stdio.h>
#include <vector>
#include "AbstractTower.h"

using namespace std;

class ChurchTower : public AbstractTower {

    vector<ofPoint> points;
    vector<ofPoint> basePoints;
    vector<ofPoint> housePoints;
    vector<ofPoint> trapezePoints;

public:
    ChurchTower(float delay);
    virtual ~ChurchTower();

    virtual void draw(float scale);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__ChurchTower__) */
