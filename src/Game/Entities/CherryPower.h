#pragma once

#include "PowerUp.h"
#include "Player.h"
#include "EntityManager.h"

class CherryPower : public PowerUp{
    public:
        CherryPower(Player* player, EntityManager* entitymanager);
        void activate(); 
    private:
        Player *player; 
        EntityManager *entitymanager; 
};