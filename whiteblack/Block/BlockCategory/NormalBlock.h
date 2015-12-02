#pragma once
#include "../BlockBase.h"

class NormalBlock : public BlockBase
{
public:

	NormalBlock();
	~NormalBlock();

	void update();
	void draw();
	void setup();

	Vec2f getBlockPos();
	Vec2f getBlockSize();
	Vec2f getBlockVectol();

	Vec2f Collision(Object _player,
		BLOCK _up, BLOCK _down,
		DIRECTION _direction = DIRECTION::NON,
		int move_vector = 0);

private:



};