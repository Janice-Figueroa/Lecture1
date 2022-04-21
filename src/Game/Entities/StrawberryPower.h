#pragma once 

#include "PowerUp.h"
#include "Player.h"
#include "EntityManager.h"

class StrawberryPower : public PowerUp{
     public:
        StrawberryPower(Player* player, EntityManager* entitymanager);
        void activate(); 
    private:
        Player *player; 
        EntityManager *entitymanager; 
};