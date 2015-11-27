#pragma once
#include "../Top/Top.h"

class BlockBase
{
public:

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void setup() = 0;


	virtual Vec2f Collision(Object _player,
		BLOCK _up, BLOCK _down,
		DIRECTION _direction = DIRECTION::NON,
		int move_vector = 0) = 0;

	void setPos(Vec2f _pos){ block.pos = _pos; }
	void setStatus(BLOCK _block){ status = _block; }
	void setCondition(CONDITION _type){ color_type = _type; }

	BLOCK getBlockStatus(){ return status; }
	CONDITION getCondition(){ return color_type; }

private:

	CONDITION color_type;
	BLOCK status;
	Object block;

};