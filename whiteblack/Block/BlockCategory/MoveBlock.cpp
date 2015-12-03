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
	block.size = Vec2f((float)BLOCKSIZE::HEIGTH,
						(float)BLOCKSIZE::WIDTH);
	
	block.vec = Vec2f::Zero();
}

void MoveBlock::update()
{

}

void MoveBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::green);
}
