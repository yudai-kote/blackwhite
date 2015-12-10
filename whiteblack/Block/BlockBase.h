#pragma once
#include "../Top/Top.h"

class BlockBase
{
public:

	BlockBase(){};
	virtual ~BlockBase(){};

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void setup() = 0;

	void setPos(Vec2f _pos){ block.pos = _pos; }
	void setVec(Vec2f _vec){ block.vec = _vec; }
	void setStatus(BLOCK _block){ status = _block; }
	void setCondition(CONDITION _type){ color_type = _type; }

	virtual void setFallFlag(bool){}

	Vec2f getPos() { return block.pos; }
	Vec2f getSize() { return block.size; }
	Vec2f getVectol() { return block.vec; }

	BLOCK getStatus(){ return status; }
	CONDITION getCondition(){ return color_type; }

protected:

	CONDITION color_type;
	BLOCK status;
	Object block;

};