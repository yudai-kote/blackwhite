#include "Player.h"


Player::Player(){
    
}

void Player::update(){
	move();
}

void Player::draw(){
	drawFillBox(player.pos.x(), player.pos.y(), player.size.x(), player.size.y(),
		Color::white, 0, Vec2f(0, 0), Vec2f(player.size.x() / 2, 0));
}

void Player::setup(Vec2f pos){
	player.pos = pos;
	player.size = Vec2f(140, 190);
	speed = Vec2f(0.5, 10);
	player.vec = Vec2f(0, 0);
	selection = Vec2i(0,0);
	color_abs = 0;
	g = 2;
}

void Player::move(){
	//ブロック選択
	if (selection.y() < 2){
		if (env.isPushKey('W')){
			selection.y()++;
		}
	}
	if (selection.y() > -2){
		if (env.isPushKey('S')){
			selection.y()--;
		}
	}
	if (selection.x() < 2){
		if (env.isPushKey('A')){
			selection.x()++;
		}
	}
	if (selection.x() > -2){
		if (env.isPushKey('D')){
			selection.x()--;
		}
	}
	//移動
	if (env.isPushKey('Z')){
		player.vec.x() += speed.x();
		player.pos.x() -= player.vec.x();
		if (player.vec.x() > 5){
			player.vec.x() = 5;
		}
	}
	else {
		player.vec.x() = 0;
	}
	if (env.isPushKey('C')){
		player.vec.x() += speed.x();
		player.pos.x() += player.vec.x();
		if (player.vec.x() > 5){
			player.vec.x() = 5;
		}
	}
	else {
		player.vec.x() = 0;
	}
	//ジャンプ
	if (env.isPushKey('K')){
		player.vec.y() = speed.y();
		player.pos.y() += player.vec.y();
		player.vec.y() -= g;
	}
	
	
}

bool Player::mapAbs(bool active){

	if (active == true){
		if (env.isPushKey('J')){
			color_abs++;
			return true;
		}
	}
	return false;
}
bool Player::releaseColor(bool active){
	if (active == true){
		if (color_abs >= 0){
			if (env.isPushKey('L')){
				color_abs--;
				return true;
			}
		}
	}
	if (env.isPushKey('I')){
		color_abs = 0;
	}
	return false;
}

Vec2f Player::getPos(){
	return player.pos;
}

Vec2i Player::getSelec(){
	return selection;
}
CONDITION Player::getCond(){
	if (color_abs < 3){
		return CONDITION::WHITE;
	}
	if (color_abs >= 3){
		if (color_abs < 6){
			return CONDITION::BLACK;
		}
	}
	
}