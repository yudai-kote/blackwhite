#include "GameMain.h"




GameMain::GameMain(){
    //setup();
    //BGM = Media("res/sound/stage1.wav");
    //gameover = Media("res/sound/gameover.wav");
    //clear = Media("res/sound/clear.wav");
    //bg = Texture("res/Texture/”wŒiƒCƒ}ƒWƒ“/”wŒiƒCƒ}ƒWƒ“/orora.png");
}
void GameMain::update(){
    //if (!BGM.isPlaying())BGM.play();
    player.update();
    map.update();
    player.addPos(map.isHitPlayerToBlock(player.getObject(),player.getCondition()));
    //std::cout << (int)player.getCondition() << std::endl;
    //•úo
    if (player.outColor()){
        if (map.sucked(player.getSelect())){
            player.subColor();
        }
    }
    //‹zû
    if (player.suckColor()){
        if (map.released(player.getSelect())){
            player.addColor();
        }
    }

}
void GameMain::draw(){
    env.bgColor(Color::blue);
    //drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, bg);

    //Vec2f cpos = Vec2f(-player.getObject().pos.x(), -player.getObject().pos.y());
   // cpos.x() = std::max(player.getObject().pos.x(), map.pos().x() + WIDTH / 2);
   // cpos.y() = std::max(player.getObject().pos.y(), map.pos().y() + HEIGHT / 2);
   //// std::cout << map.pos() << std::endl;

    glPushMatrix();
    glTranslated(-player.getObject().pos.x(), -player.getObject().pos.y(), 0);
    map.draw();
    map.selected(player.getSelect());
    glPopMatrix();

    player.draw();
}

void GameMain::setup(int stage_num){
    map.setup(stage_num);


    player.setup(map.getPlayerStartPos());
    //player.setPos(map.getPlayerStartPos());
    

}

SCENE GameMain::shift(){

    
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::TITLE;
    }
    return SCENE::GAME;
}

