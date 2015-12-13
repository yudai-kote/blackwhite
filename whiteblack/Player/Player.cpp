#include "Player.h"


Player::Player(){

}

void Player::update(){
	move();

}

void Player::draw(){

	if (direction == DIRECTION::LEFT){

		drawTextureBox(
			0 + player.size.x() / 2,
			0,
			player.size.x(),
			player.size.y(),
			0 + cut_x,
			0,
			256,
			256,
			player_texture,
			Color::white,
			0, Vec2f(-1, 1),
			Vec2f(player.size.x() / 2, 0)
			);
	}
	if (direction == DIRECTION::RIGHT){

		drawTextureBox(
			0 + player.size.x() / 2,
			0,
			player.size.x(),
			player.size.y(),
			0 + cut_x,
			0,
			256,
			256,
			player_texture,
			Color::white,
			0, Vec2f(1, 1),
			Vec2f(player.size.x() / 2, 0)
			);
	}



}

void Player::setup(Vec2f pos){
	player_texture = Texture("res/Texture/chara.png");

	player.pos = pos;
	player.size = Vec2f(140, 190);

	speed = Vec2f(0.4, 50);
	player.vec = Vec2f(0, 0);
	g = 2;

	selection = Vec2i(0, 0);
	direction = DIRECTION::RIGHT;

	ColorMax = 3;
	color_abs = 0;
	animation_count = 0;
	jump_flag = false;
}

void Player::move(){
	cut_x = 256;
	dirUpdate(select_dir);
	//ブロック選択
	if (select_dir == SELECTDIR::Y ||
		select_dir == SELECTDIR::NON){
		if (selection.y() > -2){
			if (env.isPushKey('W')){
				selection.y()--;
			}
		}
		if (selection.y() < 2){
			if (env.isPushKey('S')){
				selection.y()++;
			}
		}
	}
	if (select_dir == SELECTDIR::X ||
		select_dir == SELECTDIR::NON){
		if (selection.x() > -2){
			if (env.isPushKey('A')){
				selection.x()--;
			}
		}
		if (selection.x() < 2){
			if (env.isPushKey('D')){
				selection.x()++;
			}
		}
	}

	//移動
	if (env.isPressKey('Z') && env.isPressKey('C')){
		;
	}
	else if (env.isPressKey('Z')){
		animation();
		player.vec.x() += speed.x();
		player.pos.x() -= player.vec.x();
		if (player.vec.x() > 4){
			player.vec.x() = 4;
		}
		direction = DIRECTION::LEFT;
	}
	else if (env.isPressKey('C')){
		animation();
		player.vec.x() += speed.x();
		player.pos.x() += player.vec.x();
		if (player.vec.x() > 4){
			player.vec.x() = 4;
		}
		direction = DIRECTION::RIGHT;
	}


	if (direction == DIRECTION::LEFT){
		player.pos.x() -= player.vec.x();
	}
	if (direction == DIRECTION::RIGHT){
		player.pos.x() += player.vec.x();
	}
	if (player.vec.x() > 0){
		player.vec.x() -= 0.2;
	}
	else{
		player.vec.x() = 0;
	}
	//ジャンプ

	if (jump_flag == true){
		if (env.isPushKey('K')){
			player.vec.y() = speed.y();
			jump_flag = false;
		}
		
	}

	player.pos.y() += player.vec.y();
	if (player.vec.y() >= -45){
		player.vec.y() -= g;
	}
}



bool Player::suckColor(){
	if (color_abs < 3){
		if (env.isPushKey('J')){
			return true;
		}
	}
	return false;
}
bool Player::outColor(){
	if (color_abs >= 0){
		if (env.isPushKey('L')){
			return true;
		}
	}
	return false;
}

void Player::dirUpdate(SELECTDIR& select_dir){
	if (selection.y() != 0){
		select_dir = SELECTDIR::Y;
	}
	if (selection.x() != 0){
		select_dir = SELECTDIR::X;
	}
	if (selection.x() == 0 &&
		selection.y() == 0){
		select_dir = SELECTDIR::NON;
	}
}

void Player::animation(){
	animation_count++;
	int index = (animation_count / 6) % 3;
	cut_x = (index)* 256.0f;
}

Object Player::getObject(){
	return player;
}

Vec2i Player::getSelect(){
	return player_pos() + selection;
}
CONDITION Player::getCondition(){
	if (color_abs < 2){
		return CONDITION::WHITE;
	}
	if (color_abs >= 2){
		if (color_abs < 4){
			return CONDITION::BLACK;
		}
	}

}

Vec2i Player::player_pos(){
	return p_pos = Vec2i((player.pos.x() + player.size.x() / 2) / static_cast<int>(BLOCKSIZE::WIDTH), (std::abs(player.pos.y()) + player.size.y() / 2) / static_cast<int>(BLOCKSIZE::HEIGHT));
}

void Player::addPos(Vec2f add){
	if (add.y() > 0){
		jump_flag = true;
		player.vec.y() = 0;
	}
	player.pos += add;
}

void Player::addColor(){
	color_abs++;
}
void Player::subColor(){
	color_abs--;
}