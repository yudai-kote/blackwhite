#pragma once
#include "../BlockBase.h"

class FallBlock : public BlockBase
{
public:

	FallBlock();
	~FallBlock();

	void update();
	void draw();
	void setup();

private:



};