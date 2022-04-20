#pragma once 

#include "PowerUp.h"
#include "Player.h"

class Debugger : public PowerUp {
    private:
        Player *player; 

    public:
        Debugger(Player* player);
        void activate(); 
};