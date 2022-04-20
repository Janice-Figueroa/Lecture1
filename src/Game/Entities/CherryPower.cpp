#include "CherryPower.h"

CherryPower:: CherryPower(Player *p, EntityManager *em){
    this->player = p; 
    this->entitymanager = em; 
}

void CherryPower::activate(){
    int coords = ofRandom(0,entitymanager->entities.size());
    player->getBounds(entitymanager->entities[coords]->getX(),entitymanager->entities[coords]->getY());
}