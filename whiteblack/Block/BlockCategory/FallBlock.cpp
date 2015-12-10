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
	block.size = Vec2f(static_cast<float>(BLOCKSIZE::WIDTH),
		static_cast<float>(BLOCKSIZE::HEIGTH));

	block.vec = Vec2f(0.0f, -10.0f);

	fall_flag = false;
}

void FallBlock::update()
{
	if (fall_flag == true)
	{
		block.pos.y() += block.vec.y();
	}
}

void FallBlock::draw()
{
	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), Color::yellow);
}
