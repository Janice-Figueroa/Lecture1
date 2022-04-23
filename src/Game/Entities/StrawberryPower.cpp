#include "StrawberryPower.h"

StrawberryPower:: StrawberryPower(Player* p){
    this->player = p;
}
void StrawberryPower:: activate(){
    player->setTimer(0);
    player->setInvincible(true); 
}