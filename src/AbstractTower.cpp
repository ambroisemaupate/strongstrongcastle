//
//  AbstractTower.cpp
//  StrongStrongCastle
//
//  Created by Ambroise Maupate on 14/12/2014.
//
//

#include "AbstractTower.h"

void AbstractTower::update(float medium, bool wavingTowers) {
    this->factor = (abs(medium)*5) * -1;

    if (wavingTowers)
    {
        this->factor += -0.5f + (sin((ofGetElapsedTimeMillis() + this->delay)/500.f)*0.5f);
    }
}

void AbstractTower::draw(float scale) {
    lineWidth = 8 * scale/100.0f;
    lineWidth = lineWidth > 1 ? lineWidth : 1;
}