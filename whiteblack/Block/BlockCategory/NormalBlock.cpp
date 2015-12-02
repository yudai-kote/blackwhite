#include "NormalBlock.h"

NormalBlock::NormalBlock()
{
	setup();
}

NormalBlock::~NormalBlock()
{

}

void NormalBlock::setup()
{
	block.size = Vec2f((float)BLOCKSIZE::HEIGTH,
		(float)BLOCKSIZE::WIDTH);

	block.vec = Vec2f::Zero();
}

Vec2f NormalBlock::getBlockPos()
{
	return Vec2f();
}

Vec2f NormalBlock::getBlockSize()
{
	return Vec2f();
}

Vec2f NormalBlock::getBlockVectol()
{
	return Vec2f();
}

void NormalBlock::update()
{

}

void NormalBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::red);
}
