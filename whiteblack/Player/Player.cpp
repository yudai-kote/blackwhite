#include "Player.h"


Player::Player(){

}

void Player::update(){
    conditionUpdate();
	move();
    //std::cout << color_abs << std::endl;
}

void Player::draw(){

	if (direction == DIRECTION::LEFT){

		drawTextureBox(
			0 + player.size.x() / 2,
			0,
			player.size.x(),
			player.size.y(),
			0 + cut_x,
			0 + cut_y,
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
			0 + cut_y,
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
    cut_y = 768;
    fream = 12;
	player.pos = pos;
	player.size = Vec2f(95, 190);

	speed = Vec2f(0.8, 21);
	player.vec = Vec2f(0, 0);
	g = 1;

	selection = Vec2i(0, 0);
	direction = DIRECTION::RIGHT;

	ColorMax = 3;
	color_abs = 0;
	animation_count = 0;
	jump_flag = false;
}

void Player::conditionUpdate(){
	cut_x = 256;
	switch (color_abs)
	{
	case 0:
        cut_y = 768;
		fream = 9;
		break;
	case 1:
        cut_y = 512;
		fream = 6;
		break;
	case 2:
        cut_y = 256;
		fream = 3;
		break;
	case 3:
        cut_y = 0;
		fream = 0;
		break;
	}
}

void Player::move(){
	dirUpdate(select_dir);
	//�u���b�N�I��
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

	//�ړ�
	if (env.isPressKey('Z') && env.isPressKey('C')){
		;
	}
	else if (env.isPressKey('Z')){
		animation();
		player.vec.x() -= speed.x();
		

		if (player.vec.x() < -8){
			player.vec.x() = -8;
		}
		direction = DIRECTION::LEFT;
	}
	else if (env.isPressKey('C')){
		animation();
		player.vec.x() += speed.x();
		if (player.vec.x() > 8){
			player.vec.x() = 8;
		}
		direction = DIRECTION::RIGHT;
	}




	player.pos.x() += player.vec.x();
	
	if (player.vec.x()*player.vec.x() > 0.01){
		player.vec.x() *= 0.9;
	}
	else{
		player.vec.x() = 0;
	}
	
	//�W�����v
	if (player.vec.y() > -3){
		if (jump_flag == true){
			if (env.isPushKey('K')){
				player.vec.y() = speed.y();
				jump_flag = false;
			}
		}
	}

	player.pos.y() += player.vec.y();
	if (player.vec.y() >= -25){
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
	if (color_abs > 0){
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
	int index = (animation_count / 6) % 3+fream;
	cut_x = (index%3) * 256.0f;
	cut_y = (index/3) * 256.0f;
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
	return CONDITION::BLACK;
}

Vec2i Player::player_pos(){
	return p_pos = Vec2i((player.pos.x() + player.size.x() / 2) / static_cast<int>(BLOCKSIZE::WIDTH), (std::abs(player.pos.y()) + player.size.y() / 2) / static_cast<int>(BLOCKSIZE::HEIGHT));
}

void Player::addPos(Vec2f add){
	if (add.y() > 0){
		jump_flag = true;
		player.vec.y() = 0;
	}
    if (add.y() < 0){
        player.vec.y() = -0.1;
    }
	player.pos += add;
}

void Player::addColor(){
	color_abs++;
}
void Player::subColor(){
	color_abs--;
}