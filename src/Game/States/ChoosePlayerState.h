#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class ChoosePlayer : public State {
private:
	ofImage img1;
	Button *pacman;
    Button *mspacman; 
	Animation* anim;

public:
	ChoosePlayer();
	~ChoosePlayer();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
