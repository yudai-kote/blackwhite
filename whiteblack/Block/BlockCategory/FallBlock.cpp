#include "FallBlock.h"

FallBlock::FallBlock()
{
	setup();
}

FallBlock::~FallBlock()
{

}

void FallBlock::setup()
{
	block.size = Vec2f((float)BLOCKSIZE::HEIGTH,
		(float)BLOCKSIZE::WIDTH);

	block.vec = Vec2f::Zero();
}

void FallBlock::update()
{

}

void FallBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::yellow);
}
