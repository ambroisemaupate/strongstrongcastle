//
//  Tower.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__Tower__
#define __strongStrongCastle__Tower__

#include <stdio.h>
#include <vector>

#include "TowerInterface.h"

using namespace std;

class Tower: public TowerInterface {

protected:
    ofPoint origin;

    float factor;
    float delay;

    vector<ofPoint> points;
    vector<ofPoint> basePoints;

public:
    Tower(float delay);
    virtual ~Tower();

    virtual void update(float medium);
    virtual void draw(float scale);
    virtual void buildPoints();
};

#endif /* defined(__strongStrongCastle__Tower__) */
