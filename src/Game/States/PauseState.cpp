#include "PauseState.h"

PauseState :: PauseState(){
    quitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Quit");
    resumeButton = new Button(ofGetWidth()/2-32, ofGetHeight()/4, 64, 50, "Resume");
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);
}
void PauseState::tick() {
	resumeButton->tick();
	anim->tick();
	if(resumeButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
    quitButton->tick();
    anim->tick();
    if (quitButton->wasPressed()){
        setNextState("over");
        setFinished(true);
    }
}
void PauseState::render()
    {
	string title = "Pause Menu";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	quitButton->render();
    resumeButton->render(); 
    }
void PauseState::keyPressed(int key){
}

void PauseState::mousePressed(int x, int y, int button){
	quitButton->mousePressed(x, y);
    resumeButton->mousePressed(x,y);
}

void PauseState::reset(){
	setFinished(true);
	setNextState("");
	resumeButton->reset();
}

PauseState::~PauseState(){
	delete quitButton;
    delete resumeButton; 
	delete anim;
}


