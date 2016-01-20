#pragma once
#include "星名.h"

//向き
//使うときは型指定をしてあげる
enum class DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NON
};
//ブロックの大きさ
enum class BLOCKSIZE
{
    WIDTH = 100,
    HEIGHT = 100
};
//画面大きさ
enum WINDOW
{
    WIDTH = 1920,
    HEIGHT = 1080,
};
///シーン
enum class SCENE
{
    TITLE,
    STAGESELECT,
    GAME,
};
//ブロックの種類
enum class BLOCK
{
    NORMAL = 1,
    
    MOVE,
    FALL,
    DOUBLE,

    PLAYER_START_POS =10

};
//プレイヤーの状態
enum class CONDITION{
    BLACK,
    WHITE,
	STRIPE,
    NONE
};


//位置
//大きさ
//移動量
struct Object
{
    Vec2f pos;
    Vec2f size;
    Vec2f vec;
};


//envのシングルトン
class App
{
public:
    static AppEnv& get()
    {
        static AppEnv env(WIDTH, HEIGHT, false, true);

        return env;
    }
};

#define env App::get()

//ランダムのシングルトン
class _Random
{
public:
    static Random& get()
    {
        static Random rand;
        return rand;
    }
};
#define random _Random::get()

//ここからゲームパッド

class Pad_Base
{
public:
	Pad_Base()
		: gamepad_num(env.numGamePad())
		, pad(env.gamePad(0))
	{

	}
	bool isPressButton(const int button)
	{
		if (gamepad_num)
		{
			if (pad.isPressButton(button))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool isPushButton(const int button)
	{
		if (gamepad_num)
		{
			if (pad.isPushButton(button))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	float axis(const int button)
	{
		if (gamepad_num)
		{
			return pad.axis(button);
		}
		else{
			return 0.0f;
		}
	}

	bool isSuckPushkey(){
		return env.isPushKey('J') || isPushButton(0);
	}
	bool isSuckPresskey(){
		return env.isPressKey('J') || isPressButton(0);
	}
	bool isOutPushkey(){
		return env.isPushKey('L') || isPushButton(3);
	}
	bool isOutPresskey(){
		return env.isPressKey('L') || isPressButton(3);
	}
	bool isJumpPushkey(){
		return env.isPushKey('K') || isPressButton(2);
	}
	bool isJumpPresskey(){
		return env.isPressKey('K') || isPressButton(2);
	}
	bool isLeftMove(){
		return env.isPressKey('Z') || axis(0) < -0.8;
	}
	bool isRightMove(){
		return env.isPressKey('C') || axis(0) > 0.8;
	}
	bool isSelectLeftPushkey(){
		return env.isPushKey('A') || isPushButton(15);
	}
	bool isSelectLeftPresskey(){
		return env.isPressKey('A') || isPressButton(15);
	}
	bool isSelectRightPushkey(){
		return env.isPushKey('D') || isPushButton(13);
	}
	bool isSelectRightPresskey(){
		return env.isPressKey('D') || isPressButton(13);
	}
	bool isSelectUpPushkey(){
		return env.isPushKey('W') || isPushButton(12);
	}
	bool isSelectUpPresskey(){
		return env.isPressKey('W') || isPressButton(12);
	}
	bool isSelectDownPushkey(){
		return env.isPushKey('S') || isPushButton(14);
	}
	bool isSelectDownPresskey(){
		return env.isPressKey('S') || isPressButton(14);
	}
	bool isketteikey(){
		return env.isPushKey(GLFW_KEY_ENTER) || isPushButton(1);
	}

private:
	GamePad& pad;
	size_t gamepad_num;
};

class Pad{
public:
	static Pad_Base& Get()
	{
		static Pad_Base pad;
		return pad;
	}

};