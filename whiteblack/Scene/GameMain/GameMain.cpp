#include "GameMain.h"


float EasingelasticOut(float t, float b, float e) {
	if (t == 0) return b;
	if (t == 1) return e;

	float p = 0.3;
	float a = e - b;
	float s = p / 4;
	return (a * std::pow(2, -10 * t) * std::sin((t - s) * (2 * M_PI) / p) + a + b);
}


GameMain::GameMain(): font_(YuFont("src/whiteblack/Top/yumayoLib/meiryo.ttc")){
	//setup();
	BGM = Media("res/sound/stage1.wav");
	gameover = Media("res/sound/gameover.wav");
	clear = Media("res/sound/clear.wav");
	bg = Texture("res/Texture/bg/orora.png");
	mw = Texture("res/Texture/mw.png");
	retry = Texture("res/Texture/retry.png");
	home = Texture("res/Texture/home.png");
	next = Texture("res/Texture/next.png");
	select_SE_ = Media("res/sound/selectSE.wav");
	font.size(100);
	
}
void GameMain::update() {

	if (count == 0) {
		if (fidcount > 0)fidcount--;
		if (!BGM.isPlaying())BGM.play();
		player.update();
		map.update();
		player.addPos(map.isHitPlayerToBlock(player.getObject(), player.getCondition()));
		//std::cout << (int)player.getCondition() << std::endl;
		//ï˙èo
		if (player.outColor()) {
			if (map.sucked(player.getSelect())) {
				player.subColor();
			}
		}
		//ãzé˚
		if (player.suckColor()) {
			if (map.released(player.getSelect())) {
				player.addColor();
			}
		}
		
	}
}
void GameMain::draw() {

	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, bg);

	//Vec2f cpos = Vec2f(-player.getObject().pos.x(), -player.getObject().pos.y());
	// cpos.x() = std::max(player.getObject().pos.x(), map.pos().x() + WIDTH / 2);
	// cpos.y() = std::max(player.getObject().pos.y(), map.pos().y() + HEIGHT / 2);
	//std::cout << "pos" << map.pos() << std::endl;

	// std::cout << "size" <<map.size() << std::endl;

	glPushMatrix();
	glTranslated(-player.getObject().pos.x(), -player.getObject().pos.y(), 0);

#ifdef DEBUG
	drawFillBox(map.pos().x(), map.pos().y(), map.size().x(), map.size().y(), Color::cyan);
#endif;
	map.draw();
	map.selected(player.getSelect());
	glPopMatrix();
	font.draw(" STAGE" + std::to_string(stage_num), Vec2f(WIDTH / -2, HEIGHT / 2 - font.drawSize("S").y()), Color::lime);
	player.draw();
	font_.textSize(32);
	font_.text("EnterÇ≈ñﬂÇÈÅ©", Vec2f(WIDTH / 2 - 250.0f, -HEIGHT / 2.0f + 100.0f - 32.0f));

	if (fidcount > 0) {
		drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color(0,0,0,static_cast<float>(fidcount)/ FEDSPEED));
	}
}

void GameMain::setup(int stage_num) {
	map.setup(stage_num);
	this->stage_num = stage_num;

	player.setup(map.getPlayerStartPos());
	//player.setPos(map.getPlayerStartPos());

	count = 0;
	select = 1;
	fidcount = FEDSPEED;
}

SCENE GameMain::shift() {

	//ÉQÅ[ÉÄÇ™ClearÇµÇΩéûÇÃèàóùÅG
	if (isGoal()) {
		BGM.stop();
		if (count++ < 60 * 3) {
			fidcount = 0;
			if (!clear.isPlaying())clear.play();
		}
		else
		{
			return Result();

		}
	}

	///ÉQÅ[ÉÄÉIÅ[ÉoÅ[ÇÃéûÇÃèàóù
	if (isFieldOut()) {
		BGM.stop();
		if (count++ < 60 * 3)
		{
			fidcount = 0;
			if (!gameover.isPlaying())gameover.play();
		}
		else
		{
			return Result();

		}

	}
	if(count == 0)
	if (env.isPushKey(GLFW_KEY_ENTER)) {
		BGM.stop();
		return SCENE::STAGESELECT;
	}

	return SCENE::GAME;
}

bool GameMain::isGoal()
{
	if (player.getObject().pos.x() + player.getObject().size.x() >= map.getGoalPos().x() &&
		player.getObject().pos.x() <= map.getGoalPos().x() + map.getGoalSize().x())
	{
		if (player.getObject().pos.y() + player.getObject().size.y() >= map.getGoalPos().y() &&
			player.getObject().pos.y() <= map.getGoalPos().y() + map.getGoalSize().y())
		{
			return true;
		}
	}
	return false;
}

bool is_hitg(Vec2f pos, Vec2f floor_pos, Vec2f floor_size) {
	return (
		pos.x() >= floor_pos.x() &&
		pos.x() <= floor_pos.x() + floor_size.x() &&
		pos.y() >= floor_pos.y() &&
		pos.y() <= floor_pos.y() + floor_size.y());

}
bool GameMain::isFieldOut() {
	return !is_hitg
		(player.getObject().
			pos, map.pos() - player.getObject().size,
			map.size() + player.getObject().size);
}


SCENE GameMain::Result() {

	Vec2f size = Vec2f(700, 800);

	float a = EasingelasticOut((static_cast<float>((count - 60.f*3.f) / (60.f*2.f))),
		HEIGHT / 2 + size.y() / 2, 0);

	//std::cout << select << std::endl;

	if (fidcount == 0) {
		if (env.isPushKey('A'))
		{
			if (select > 0) {
				select--; select_SE_.play();
			}
		}
		if (env.isPushKey('D'))
		{
			if (select < 2) {
				select++;
				select_SE_.play();
			}
		}
	}

	Vec2f sizeh = Vec2f(100, 100);
	Vec2f sizer = Vec2f(100, 100);
	Vec2f sizen = Vec2f(100, 100);
	if (env.isPushKey(GLFW_KEY_ENTER)) {
		if (fidcount == 0);
		fidcount++;
	}
	if (fidcount > 0)
	{
		fidcount++;
	}
	if (fidcount > FEDSPEED) {
		clear.stop();
		gameover.stop();
		switch (select)
		{
		default:
			break;
		case 0:
			return SCENE::STAGESELECT;
			break;
		case 1:
			setup(stage_num);
			break;
		case 2:
			setup(stage_num + 1);
			break;
		}
	}


	float b = sin(static_cast<float>(count) / 10.f) * 20;
	switch (select)
	{
	default:
		break;
	case 0:
		sizeh += Vec2f(b, b);
		break;
	case 1:
		sizer += Vec2f(b, b);
		break;
	case 2:
		sizen += Vec2f(b, b);
		break;
	}

	drawTextureBox(
		0, a,
		size.x(), size.y(),
		0, 0,
		480, 160,
		mw,
		Color::white,
		0,
		Vec2f(1, 1),
		size / 2);
	drawTextureBox(-size.x() / 2 + size.x() / 4, a, sizeh.x(), sizeh.y(), 0, 0, 256, 256, home, Color::white, 0, Vec2f(1, 1), sizeh / 2);
	drawTextureBox(-size.x() / 2 + size.x() / 4 * 2, a, sizer.x(), sizer.y(), 0, 0, 256, 256, retry, Color::white, 0, Vec2f(1, 1), sizer / 2);
	drawTextureBox(-size.x() / 2 + size.x() / 4 * 3, a, sizen.x(), sizen.y(), 0, 0, 256, 256, next, Color::white, 0, Vec2f(1, 1), sizen / 2);
	if (fidcount > 0) {
		drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color(0, 0, 0, static_cast<float>(fidcount) / FEDSPEED));
	}
	return SCENE::GAME;
}