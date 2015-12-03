#pragma once
#include "../BlockBase.h"

class DoubleBlock : public BlockBase
{
public:

	DoubleBlock();
	~DoubleBlock();

	void update();
	void draw();
	void setup();

	Vec2f Collision(Object _player,
		BLOCK _up, BLOCK _down,
		DIRECTION _direction = DIRECTION::NON,
		int move_vector = 0);

private:



};