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
	block.size = Vec2f((float)BLOCKSIZE::HEIGTH,
		(float)BLOCKSIZE::WIDTH);

	block.vec = Vec2f::Zero();
}

Vec2f DoubleBlock::getBlockPos()
{
	return Vec2f();
}

Vec2f DoubleBlock::getBlockSize()
{
	return Vec2f();
}

Vec2f DoubleBlock::getBlockVectol()
{
	return Vec2f();
}

void DoubleBlock::update()
{

}

void DoubleBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::blue);
}
