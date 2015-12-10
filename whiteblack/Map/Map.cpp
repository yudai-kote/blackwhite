#include "Map.h"


Map::Map(){
	setup(1);
}

void Map::update(){

}

void Map::draw(){

	for (int y = 0; y < static_cast<int>(map_chip.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(map_chip[y].size()); x++)
		{
			map_chip[y][x]->draw();
		}
	}
}

void Map::setup(int stage){

	std::string file_name = "res/map/stage" + std::to_string(stage) + ".txt";
	std::ifstream* map_file = new std::ifstream(file_name);

	if (map_file->fail())
	{
		std::cerr << "“Ç‚Ýž‚ÝŽ¸”s" << std::endl;

		exit(0);
	}

	Vec2i map_size;

	*map_file >> map_size.x();
	*map_file >> map_size.y();

	std::vector<BlockBase*> map_chip_;
	int type;

	for (int y = 0; y < map_size.y(); y++)
	{
		for (int x = 0; x < map_size.y(); x++)
		{
			*map_file >> type;

			switch (type)
			{
			case 1:
				map_chip_.push_back(new NormalBlock);
				break;

			case 2:
				map_chip_.push_back(new MoveBlock);
				break;

			case 3:
				map_chip_.push_back(new FallBlock);
				map_chip_[y][x].setFallFlag(false);
				break;

			case 4:
				map_chip_.push_back(new DoubleBlock);
				break;

			case 5:
				player_start_pos = Vec2f(
					static_cast<float>(BLOCKSIZE::WIDTH)*x,
					-(static_cast<float>(BLOCKSIZE::HEIGTH)*y));
			}
		}

		map_chip.push_back(map_chip_);

		map_chip_.clear();
	}

	delete map_file;

}

Vec2f Map::getPlayerStartPos() const{
	return player_start_pos;
}

Vec2f Map::isHitPlayerToBlock(Object player, CONDITION player_condition){

	Vec2f sinking;

	for (int y = 0; y < static_cast<int>(map_chip.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(map_chip[y].size()); x++)
		{
			if (player_condition == map_chip[y][x]->getCondition())
				return Vec2f(0.0f, 0.0f);

			//top
			if (map_chip[y][x]->getCondition() != map_chip[y - 1][x]->getCondition())
			{
				if (player.pos.x() + player.size.x() > map_chip[y][x]->getPos().x() &&
					player.pos.x() < map_chip[y][x]->getPos().x() + map_chip[y][x]->getSize().x())
				{
					if (player.pos.y() > map_chip[y][x]->getPos().y() + map_chip[y][x]->getSize().y() - 50.0f &&
						player.pos.y() < map_chip[y][x]->getPos().y() + map_chip[y][x]->getSize().y())
					{
						if (player.vec.y() < 0.0f)
						{
							sinking.x() = 0.0f;
							sinking.y() = map_chip[y][x]->getPos().y() - player.pos.y();

							return sinking;
						}
					}
				}
			}

			//left
			if (map_chip[y][x]->getCondition() != map_chip[y][x - 1]->getCondition())
			{
				if (player.pos.x() + player.size.x() > map_chip[y][x]->getPos().x() &&
					player.pos.x() + player.size.x() < map_chip[y][x]->getPos().x() + map_chip[y][x]->getSize().x() / 2)
				{
					if (player.pos.y() + player.size.y() > map_chip[y][x]->getPos().y() &&
						player.pos.y() < map_chip[y][x]->getPos().y() + map_chip[y][x]->getSize().y())
					{
						sinking.x() = player.pos.x() - map_chip[y][x]->getPos().x();
						sinking.y() = 0.0f;

						return sinking;
					}
				}
			}

			//right
			if (map_chip[y][x]->getCondition() != map_chip[y][x + 1]->getCondition())
			{
				if (player.pos.x() > map_chip[y][x]->getPos().x() + map_chip[y][x]->getSize().x() / 2 &&
					player.pos.x() < map_chip[y][x]->getPos().x() + map_chip[y][x]->getSize().x())
				{
					if (player.pos.y() + player.size.y() > map_chip[y][x]->getPos().y() &&
						player.pos.y() < map_chip[y][x]->getPos().y() + map_chip[y][x]->getSize().y())
					{
						sinking.x() = map_chip[y][x]->getPos().x() - player.pos.x();
						sinking.y() = 0.0f;

						return sinking;
					}
				}
			}

			//down
			if (map_chip[y][x]->getCondition() != map_chip[y + 1][x]->getCondition())
			{
				if (player.pos.x() + player.size.x() > map_chip[y][x]->getPos().x() &&
					player.pos.x() < map_chip[y][x]->getPos().x() + map_chip[y][x]->getSize().x())
				{
					if (player.pos.y() + player.pos.y() > map_chip[y][x]->getPos().y() &&
						player.pos.y() + player.pos.y() < map_chip[y][x]->getPos().y() + 50.0f)
					{
						if (player.vec.y() > 0.0f)
						{
							sinking.x() = 0.0f;
							sinking.y() = player.pos.y() - map_chip[y][x]->getPos().y();

							return sinking;
						}
					}
				}
			}
		}
	}

	return Vec2f(0.0f, 0.0f);
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

	switch (map_chip[selected_pos.y()][selected_pos.x()]->getStatus())
	{
	case BLOCK::NORMAL:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::BLACK)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::WHITE);
		return true;

	case BLOCK::MOVE:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::BLACK)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::WHITE);
		return true;

	case BLOCK::FALL:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::BLACK)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::WHITE);
		map_chip[selected_pos.y()][selected_pos.x()]->setFallFlag(true);
		return true;

	case BLOCK::DOUBLE:
		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::WHITE);
		return true;
	}

	return false;
}

bool Map::released(Vec2i selected_pos)
{
	switch (map_chip[selected_pos.y()][selected_pos.x()]->getStatus())
	{
	case BLOCK::NORMAL:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::WHITE)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::BLACK);
		return true;

	case BLOCK::MOVE:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::WHITE)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::BLACK);
		return true;

	case BLOCK::FALL:
		if (map_chip[selected_pos.y()][selected_pos.x()]->getCondition() != CONDITION::WHITE)
			return false;

		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::BLACK);
		map_chip[selected_pos.y()][selected_pos.x()]->setFallFlag(true);
		return true;

	case BLOCK::DOUBLE:
		map_chip[selected_pos.y()][selected_pos.x()]->setCondition(CONDITION::BLACK);
		return true;
	}

	return false;
}

void Map::mapDelete()
{
	map_chip.clear();
}