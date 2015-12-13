#pragma once
#include "../BlockBase.h"

class NormalBlock : public BlockBase
{
public:

	NormalBlock();
	~NormalBlock();

	void setImage(Texture image){ this->image = image; }
	void setPos(Vec2f _pos){ block.pos = _pos; }
	void setVec(Vec2f _vec){ block.vec = _vec; }
	void setStatus(BLOCK _block){ status = _block; }
	void setCondition(CONDITION _type){ color_type = _type; }

	void setFallFlag(bool fall_flag){ this->fall_flag = fall_flag; }
	void setMoveFlag(bool move_flag){ this->move_flag = move_flag; }

	Vec2f getPos() { return block.pos; }
	Vec2f getSize() { return block.size; }
	Vec2f getVectol() { return block.vec; }

	BLOCK getStatus(){ return status; }
	CONDITION getCondition(){ return color_type; }

	bool getFallFlag(){ return fall_flag; }
	bool getMoveFlag(){ return move_flag; }

	void update();
	void draw();
	void setup();

private:



};