#include "MoveBlock.h"

MoveBlock::MoveBlock()
{
	setup();
}

MoveBlock::~MoveBlock()
{

}

void MoveBlock::setup()
{
	block.size = Vec2f(static_cast<float>(BLOCKSIZE::WIDTH),
		static_cast<float>(BLOCKSIZE::HEIGHT));
	
	block.vec = Vec2f::Zero();

	move_flag = false;
}

void MoveBlock::update()
{
	if (move_flag == true)
	{
		block.pos += block.vec;
	}
}

void MoveBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::green);
}
