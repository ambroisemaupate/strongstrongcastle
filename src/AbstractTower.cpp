//
//  AbstractTower.cpp
//  StrongStrongCastle
//
//  Created by Ambroise Maupate on 14/12/2014.
//
//

#include "AbstractTower.h"

void AbstractTower::update(float medium, float volume, bool wavingTowers) {
    
    this->volume = volume*50.0f;
    
    if (ofGetFrameNum()%3 == 0) {
        this->motion.x = 0;
        this->motion.y = (medium) * -2;
    }
    this->motion.y += 0.03f;
    this->motion.y *= 0.98f;
    
    if (wavingTowers)
    {
        this->factor = ((sin((ofGetElapsedTimeMillis() + this->delay)/500.f)*0.5f) + 0.5f) * -2.0f;
        //this->factor += this->motion.y;
    } else {
        this->factor += this->motion.y;
    }
    
    if (this->factor > 0) {
        this->factor = 0;
    }
    if (this->factor < -6) {
        this->factor = -6;
    }
    
}

void AbstractTower::draw(float scale, int towerLineWidth) {
    lineWidth = towerLineWidth * scale/100.0f;
    lineWidth = lineWidth > 1 ? lineWidth : 1;
}