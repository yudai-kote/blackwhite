#include "../Top/Top.h"
///藤吉
//ここはいつも通りのアクションの処理を描いて
///プレイヤーの仕様をよく見てやってね
///プレイヤーの大きさはブロックの一回り小さい
//(140,190)くらいでいいと思う
//playerは選択しているマス目が合ってVec2iで
//プレイヤーの位置だったら（０，０）みたいな
//プレイヤーのみぎだったら（1,0）みたいな
//ギャーみたいな
//もちろんgetもね
//後選択範囲がプレイヤーから2マス先までだよ
//吸収放出した時にtrueを返すゲッター
//
//キーは移動はZC選択はWASDジャンプはK吸収はJ
//放出はL全変えはIでとりあえずは頼む
//プレイヤーの初期位置はマップからもらってくる予定だ
//



class Player
{
public:
    Player();
    void update();
    void draw();
    void setup(Vec2f pos);
	void move();
	//ブロックがアクティブなら選択ボタンを押せる
	//そして吸ったかどうかを返す
	bool mapAbs(bool active);
	bool releaseColor(bool active);

	//ゲッター
	Vec2f getPos();
	Vec2i getSelec();
	CONDITION getCond();
private:
    
    Object player;
	Vec2i selection;
	Vec2f speed;
	float g;
	int color_abs;
	int change_count;
	CONDITION condition;
	DIRECTION direction;
};
