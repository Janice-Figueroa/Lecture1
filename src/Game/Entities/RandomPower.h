#pragma once

#include "PowerUp.h"
#include "Player.h"

class RandomPower : public PowerUp{
    public: 
        RandomPower(Player*);
        void activate();
    private: 
        Player* player;
        int random; 
};