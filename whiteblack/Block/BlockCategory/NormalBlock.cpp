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

void NormalBlock::update()
{

}

void NormalBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::red);
}
