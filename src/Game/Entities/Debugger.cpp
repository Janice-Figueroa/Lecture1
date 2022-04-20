
#include "Debugger.h"

Debugger::Debugger(Player *player){
    this->player = player; 
}

void Debugger:: activate(){
    if (player->getSpeed() == 4 ){
        player->setSpeed(6);
    }else{player->setSpeed(4); }
}
