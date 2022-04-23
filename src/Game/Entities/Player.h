#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "PowerUp.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        bool walking = false;
        bool invincible= false;
        int timer;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        PowerUp* Power; 
        PowerUp* cherry; 
        PowerUp* strawberry; 
        PowerUp* random; 

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        int getScore();
        int getDotCount(); 
        int getSpeed() {return speed;}
        int getTimer();
        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setSpeed(int);
        void setBounds(int,int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setTimer(int);
        void setInvincible(bool);
        void checkCollisions();
        void die();
        
};