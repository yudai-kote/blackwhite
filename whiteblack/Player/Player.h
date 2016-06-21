#include "../Top/Top.h"
///���g
//�����͂����ʂ�̃A�N�V�����̏�����`����
///�v���C���[�̎d�l���悭���Ă���Ă�
///�v���C���[�̑傫���̓u���b�N�̈��菬����
//(140,190)���炢�ł����Ǝv��
//player�͑I�����Ă���}�X�ڂ�������Vec2i��
//�v���C���[�̈ʒu��������i�O�C�O�j�݂�����
//�v���C���[�݂̂���������i1,0�j�݂�����
//�M���[�݂�����
//�������get����
//��I��͈͂��v���C���[����2�}�X��܂ł���
//�z�����o��������true��Ԃ��Q�b�^�[
//
//�L�[�͈ړ���ZC�I����WASD�W�����v��K�z����J
//���o��L�S�ς���I�łƂ肠�����͗���
//�v���C���[�̏����ʒu�̓}�b�v���������Ă���\�肾
//

enum class SELECTDIR{
	Y,
	X,
	NON_Y0,
	NON_Y1,
	NON
	

};


class Player
{
public:
    Player();
    void update();
    void draw();
    void setup(Vec2f pos);
	void move();
	void conditionUpdate();
	void dirUpdate(SELECTDIR&);
	void animation();

	//�A�b�v�f�[�g������h��Ȃ��������
	void deadAnimation();

	void clearAnimation();

	SELECTDIR select_dir;
	//�u���b�N���z�����ԂȂ�I���{�^����������
	//�����ċz�������ǂ�����Ԃ�
	bool suckColor();
	bool outColor();
	Vec2i player_pos();

	//�Q�b�^�[
	Object getObject();
	Vec2i getSelect();
	CONDITION getCondition();

	//�Z�b�^�[
	//�|�X�̃Z�b�g�͒n�ʔ���ł���Ă����Ă�
	void addPos(Vec2f pos);
	void addColor();
	void subColor();
private:
	Texture player_texture;
	Media jump, sub, add;
	int ColorMax;
	int animation_count;
	int dead_animation_count;
	int clear_animation_count;
	float cut_x;
	float cut_y;
	float dead_x;
    int fream;
    Object player;
	Vec2i selection;
	Vec2i p_pos;
	Vec2f speed;
	float g;
	int color_abs;
	int change_count;
	bool jump_flag;
	CONDITION condition;
	DIRECTION direction;

	
};
