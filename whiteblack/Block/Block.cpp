#include "Block.h"


Block::Block(){
    setup();
	type = static_cast<int>(BLOCK::NULLBLOCK);
}

void Block::update(){
    
    switch (static_cast<int>(status))
    {
    case static_cast<int>(BLOCK::BLACK_) :
        break;
    case static_cast<int>(BLOCK::FALL_BLACK_) :
        break;
    default:


        break;
    }

	if (env.isPushButton(Mouse::LEFT))
	{
		type = (type + 1) % 8;
	}
    
}

void Block::draw(){

	switch (type)
	{
	case static_cast<int>(BLOCK::NULLBLOCK) :
		break;

	case static_cast<int>(BLOCK::NORMAL_) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::white);
		break;

	case static_cast<int>(BLOCK::WHITE) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::black);
		break;

	case static_cast<int>(BLOCK::BLACK_) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::blue);
		break;

	case static_cast<int>(BLOCK::MOVE_) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::cyan);
		break;

	case static_cast<int>(BLOCK::FALL_) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::gray);
		break;

	case static_cast<int>(BLOCK::DOUBLE_W) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::green);
		break;

	case static_cast<int>(BLOCK::DOUBLE_B) :
		drawFillBox(start_pos.x(), start_pos.y(), draw_pos.x(), draw_pos.y(), Color::lime);
		break;
	}




}

void Block::setup(){
    block.size = Vec2f((float)BLOCKSIZE::WIDTH, 
        (float)BLOCKSIZE::HEIGTH);
    block.vec = Vec2f(0, 0);

}
///ブロックのポジションのセット
void Block::setPos(Vec2f _pos){
    block.pos = _pos;
}
//ブロックのステータスのセット
void Block::setStatus(BLOCK _status){
    status = _status;
}

//プレイヤーの情報
//上のブロックの情報
//下のブロックの情報
//動かすときの向き
//何マス動かすのか？
Vec2f Block::Collision(Object _player, 
    BLOCK _up, BLOCK _down,
    DIRECTION _direction,
    int move_vector ){



    switch (static_cast<int>(status))
    {
    case static_cast<int>(BLOCK::BLACK_):
        break;
    case static_cast<int>(BLOCK::FALL_BLACK_):
        break;
    default:
        break;
    }







    return Vec2f(0,0);
}

