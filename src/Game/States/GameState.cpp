#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage,getChosenPlayer());
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if(map->getPlayer()->getDotCount() == 0){
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
	}
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	if(key == 'p'){
		setNextState("pause");
		setFinished(true);
	}else if(key == 'y'){
		setNextState("win");
		setFinished(true);
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

void GameState::setChosenPlayer(string chosenP){
	chosenPlayer = chosenP;
}

string GameState::getChosenPlayer(){
	return chosenPlayer;
}

GameState::~GameState(){
	delete map;
}