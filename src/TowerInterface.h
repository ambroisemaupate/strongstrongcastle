//
//  TowerInterface.h
//  strongStrongCastle
//
//  Created by Ambroise Maupate on 13/12/2014.
//
//

#ifndef __strongStrongCastle__TowerInterface__
#define __strongStrongCastle__TowerInterface__

#include <stdio.h>

class TowerInterface {

public:
    virtual ~TowerInterface(){
        
    };
    virtual void draw(float scale, int towerLineWidth) = 0;
    virtual void update(float medium, float volume, bool wavingTowers = false) = 0;
    virtual void buildPoints() = 0;
};

#endif /* defined(__strongStrongCastle__TowerInterface__) */
