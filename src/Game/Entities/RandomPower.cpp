#include "RandomPower.h"

RandomPower::RandomPower(Player* p){
    this->player = p;
}

void RandomPower::activate(){
    random = ofRandom(0,100); 

     if(random <=20){
        player->setScore(player->getScore() + 50);
    } else if(random >20 || random <40){
        player->setScore(player->getScore() + 100);
    } else if(random >= 40 || random < 60){
        player->setScore(player->getScore() + 250);
    } else if(random >= 60 || random <80){
        player->setScore(player->getScore() + 500);
    } else if(random <=100){
        player->setScore(player->getScore() + 1000);
    }
}