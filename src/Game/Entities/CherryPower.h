#pragma once

#include "PowerUp.h"
#include "Player.h"
#include "EntityManager.h"

class CherryPower : public PowerUp{
    public:
        CherryPower(Player* , EntityManager* );
        void activate(); 
    private:
        Player* player; 
        EntityManager* entitymanager; 
};