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

    ofPoint origin;

public:
    virtual void update(float medium, bool wavingTowers = false);
    virtual void draw(float scale);
};

#endif /* defined(__StrongStrongCastle__AbstractTower__) */
