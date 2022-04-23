#include "ChoosePlayerState.h"

ChoosePlayer::ChoosePlayer() {
	pacman = new Button(ofGetWidth()/2-100, ofGetHeight()/2, 64, 50, "Pacman");
    mspacman = new Button(ofGetWidth()/2+100, ofGetHeight()/2, 64, 50, "Ms. Pacman");
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void ChoosePlayer::tick() {
	pacman->tick();
    anim->tick();
    mspacman->tick(); 
	if(pacman->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
    if(mspacman->wasPressed()){
		choose = true; 
        setNextState("Game");
        setFinished(true);
    }
}
void ChoosePlayer:: setChoose(bool c){
	choose = c;
}
bool ChoosePlayer:: getChoose(){
	return choose; 
}
void ChoosePlayer::render() {
	string title = "CHOOSE PLAYER";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	pacman->render();
    mspacman->render(); 
}

void ChoosePlayer::keyPressed(int key){
	
}

void ChoosePlayer::mousePressed(int x, int y, int button){
	pacman->mousePressed(x, y);
    mspacman->mousePressed(x, y);
}
Button* ChoosePlayer:: getmspacman(){
	return mspacman; 
}
void ChoosePlayer::reset(){
	setFinished(false);
	setNextState("");
	pacman->reset();
    mspacman->reset();
}

ChoosePlayer::~ChoosePlayer(){
	delete pacman;
    delete mspacman;
	delete anim;
}