//
//  AbstractTower.h
//  StrongStrongCastle
//
//  Created by Ambroise Maupate on 14/12/2014.
//
//

#ifndef __StrongStrongCastle__AbstractTower__
#define __StrongStrongCastle__AbstractTower__

#include "ofApp.h"
#include <stdio.h>
#include "TowerInterface.h"

class AbstractTower: public TowerInterface {

protected:
    float factor;
    float delay;
    float lineWidth;
    float volume;

    ofPoint origin;
    ofPoint motion;

public:
    virtual void update(float medium, float volume, bool wavingTowers = false);
    virtual void draw(float scale, int towerLineWidth);
};

#endif /* defined(__StrongStrongCastle__AbstractTower__) */
