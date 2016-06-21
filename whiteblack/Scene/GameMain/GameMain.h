#include "../../Top/Top.h"

#include "../../Map/Map.h"
#include "../../Player/Player.h"

class GameMain
{
public:
    void update();
    void draw();
    void setup(int);
    SCENE shift();
    GameMain();
private:
    Map map;
    Player player;
	YuFont font_;
    Media BGM;
    Media gameover;
    Media clear;
	Media select_SE_;
	Media sub_SE;
	Media add_SE;
    Texture bg;
	Texture mw;
	Texture retry;
	Texture home;
	Texture next;
    int count;
	int stage_num;
	int select;
    bool isGoal();
	
	int fidcount;
	
	bool isFieldOut();
	SCENE Result();
	Font font = Font("res/Arimo-Italic.ttf");

	
	enum 
	{
		FEDSPEED = 60
	};
};

