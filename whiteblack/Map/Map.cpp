#include "Map.h"


Map::Map(){
    setup(1, Vec2i(10, 10));
}

void Map::update(){

}

void Map::draw(){

	for (int y = 0; y < static_cast<int>(map_chip.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(map_chip[y].size()); x++)
		{
			switch (map_chip[y][x].getBlockStatus())
			{
			case BLOCK::NORMAL_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::gray);
				return;

			case BLOCK::WHITE_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::white);
				break;

			case BLOCK::BLACK_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::black);
				break;

			case BLOCK::MOVE_WHITE_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::cyan);
				break;

			case BLOCK::MOVE_BLACK_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::blue);
				break;

			case BLOCK::FALL_WHITE_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::green);
				break;

			case BLOCK::FALL_BLACK_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::lime);
				break;

			case BLOCK::DOUBLE_WHITE_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::magenta);
				break;

			case BLOCK::DOUBLE_BLACK_:
				drawFillBox(x * static_cast<float>(BLOCKSIZE::WIDTH),
					-y * static_cast<float>(BLOCKSIZE::HEIGTH),
					static_cast<float>(BLOCKSIZE::WIDTH),
					static_cast<float>(BLOCKSIZE::HEIGTH),
					Color::maroon);
				break;
			}
		}
	}
}

void Map::setup(int stage, Vec2i map_size){

	map_chip = std::vector<std::vector<Block>>(map_size.y(), std::vector<Block>(map_size.x()));

	std::string file_name = "res/stage(" + std::to_string(stage) + ").txt";
	std::ifstream* map_file = new std::ifstream(file_name);

	int status;

	for (int y = 0; y < map_size.y(); y++)
	{
		for (int x = 0; x < map_size.y(); y++)
		{
			*map_file >> status;

			map_chip[y][x].setStatus(static_cast<BLOCK>(status));
		}
	}

	delete map_file;
}

Vec2f Map::isHitPlayerToBlock(Object player, CONDITION condition){

	Vec2f sinking;

	for (int y = 0; y < static_cast<int>(map_chip.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(map_chip[y].size()); x++)
		{
			sinking = map_chip[y][x].Collision(player,
				map_chip[y - 1][x].getBlockStatus(),
				map_chip[y + 1][x].getBlockStatus());

			if (sinking != Vec2f(0.0f, 0.0f))
				continue;

			return sinking;
		}
	}
}

void Map::selected(Vec2i selected_pos){

	drawBox(selected_pos.x() * static_cast<float>(BLOCKSIZE::WIDTH),
		-selected_pos.y() * static_cast<float>(BLOCKSIZE::HEIGTH),
		static_cast<float>(BLOCKSIZE::WIDTH),
		static_cast<float>(BLOCKSIZE::HEIGTH),
		10,
		Color::yellow);
}


bool Map::sucked(Vec2i selected_pos){

	switch (map_chip[selected_pos.y()][selected_pos.x()].getBlockStatus())
	{
	case BLOCK::NORMAL_:
		return;

	case BLOCK::WHITE_:
		return false;

	case BLOCK::BLACK_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::WHITE_);
		return true;

	case BLOCK::MOVE_WHITE_:
		return false;

	case BLOCK::MOVE_BLACK_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::MOVE_WHITE_);
		return true;

	case BLOCK::FALL_WHITE_:
		return false;

	case BLOCK::FALL_BLACK_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::FALL_WHITE_);
		break;

	case BLOCK::DOUBLE_WHITE_:
		return false;

	case BLOCK::DOUBLE_BLACK_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::WHITE_);
		return true;
	}
}

bool Map::release(Vec2i selected_pos)
{
	switch (map_chip[selected_pos.y()][selected_pos.x()].getBlockStatus())
	{
	case BLOCK::NORMAL_:
		return;

	case BLOCK::WHITE_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::BLACK_);
		return true;

	case BLOCK::BLACK_:
		return false;

	case BLOCK::MOVE_WHITE_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::MOVE_BLACK_);
		return true;

	case BLOCK::MOVE_BLACK_:
		return false;

	case BLOCK::FALL_WHITE_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::FALL_BLACK_);
		return true;

	case BLOCK::FALL_BLACK_:
		return false;

	case BLOCK::DOUBLE_WHITE_:
		map_chip[selected_pos.y()][selected_pos.x()].setStatus(BLOCK::BLACK_);
		return true;

	case BLOCK::DOUBLE_BLACK_:
		return false;
	}
}

void Map::mapDelete()
{
	map_chip.clear();
}