
#include "../Top/Top.h"
#include "../Block/BlockBase.h"
#include "../Block/BlockCategory/NormalBlock.h"
#include "../Block/BlockCategory/MoveBlock.h"
#include "../Block/BlockCategory/FallBlock.h"
#include "../Block/BlockCategory/DoubleBlock.h"



class Map
{
public:
    Map();
    void update();
    void draw();
	//�v���C����stage�̔ԍ��������ɂ�������
    void setup(int);

	Vec2f getPlayerStartPos() const;

	//struct�^��player��player��condition�������ł������
	//block�ɂ߂荞�񂾕��̒l��(�{)�̒l�ŕԂ��܂�
	Vec2f isHitPlayerToBlock(Object, CONDITION);

	void isHitMoveBlockToBlock();

	//�I������Ă���}�b�v�`�b�v�̍��W�������Ŋl������
	//�g�����点��
	void selected(Vec2i);

	//�I������Ă���}�b�v�`�b�v�̍��W��
	//�����Ŋl�����ċz�����܂�
	bool sucked(Vec2i);

	//�I������Ă���}�b�v�`�b�v�̍��W��
	//�����Ŋl�����ĕ��o���܂�
	bool released(Vec2i);

    //�}�b�v�̍����̈ʒu��Ԃ��֐�
    Vec2f pos();
    //�}�b�v�S�̂̑傫����Ԃ��֐�
    Vec2f size();

private:

	std::vector<std::vector<BlockBase*>> map_chip;
	Vec2f player_start_pos;

	void mapDelete();

    Vec2f collsion(Object player, Object block, bool, bool);

    
    Texture blackblock;
    Texture whiteblock;
    Texture stripeblock;
    Texture doubleblock_white;
    Texture doubleblock_black;
    Texture downblock_black;
    Texture downblock_white;
    
    Texture moveblock_up;
    Texture moveblock_down;
    Texture moveblock_left;
    Texture moveblock_right;
    Texture movedown_white;
    Texture moveleft_white;
    Texture moveright_white;
    Texture moveup_white;

};


