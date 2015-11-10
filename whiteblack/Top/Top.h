#pragma once
#include "星名.h"
#include "GamePad.h"

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
    WIDTH = 150,
    HEIGTH = 200
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
    NORMAL_ = 1,
    WHITE = 2,
    BLACK_ =3,
    MOVE_=4,
    FALL_=5,
    DOUBLE_W = 6,
    DOUBLE_B = 7,

};
//プレイヤーの状態
enum class CONDITION{
    BLACK,
    WHITE
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
        static AppEnv env(WIDTH, HEIGHT/*, false, true*/);

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
