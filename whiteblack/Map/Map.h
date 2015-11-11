
#include "../Top/Top.h"
#include "../Block/Block.h"
/////ウッティーーー
///マップにはプレイヤーのposとsizeとvecの
///情報でblockにどれだけめり込んだかを返す関数を作る
//実際にblockにその情報を経由するんだけど
//その情報プラス上と下に何のブロックがあるのか
//も渡してあげる
//blockがどんなブロックなのかを初期化する
//初期化はとりあえずtxtでやろうと思う
//マップの描画はゲームメインさんでトランスレートする
//マップのサイズとブロックの種類は定数で用意してあるので使って
//後でマップのマスの数は変えれるように汎用性を持たせてブロックをインスタンス化する
//playerのポジションから選択の選択されているマス目を視覚化しないといけない
//プレイヤーからどのマスを選択しているかの情報をVec2iであげるでプレイヤーの中心から
//ブロックサイズを掛けてそのマス目にdrawBoxでもいいからしておいてね
//情報が多すぎるからObjectの構造体で受け取ってね



class Map
{
public:
    Map();
    void update();
    void draw();
    void setup();

	Vec2f isHitPlayerToBlock(Object, CONDITION);
	void selected(Vec2i);
	void sucked(Vec2i);

private:

	std::vector<std::vector<Block>> map_chip;
    
};


