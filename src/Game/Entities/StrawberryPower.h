#pragma once 

#include "PowerUp.h"
#include "Player.h"

class StrawberryPower : public PowerUp{
    public:
        StrawberryPower(Player* player);
        StrawberryPower(EntityManager* em); 
        void activate(); 
    private:
        

}