#pragma once 

#include "PowerUp.h"
#include "Player.h"

class StrawberryPower : public PowerUp{
     public:
        StrawberryPower(Player* );
        void activate(); 
    private:
        Player *player; 
};