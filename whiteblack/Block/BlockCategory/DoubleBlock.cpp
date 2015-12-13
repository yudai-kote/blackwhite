#include "DoubleBlock.h"

DoubleBlock::DoubleBlock()
{
	setup();
}

DoubleBlock::~DoubleBlock()
{

}

void DoubleBlock::setup()
{
	block.size = Vec2f(static_cast<float>(BLOCKSIZE::WIDTH),
		static_cast<float>(BLOCKSIZE::HEIGHT));

	block.vec = Vec2f::Zero();
}

void DoubleBlock::update()
{

}

void DoubleBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::blue);
}
