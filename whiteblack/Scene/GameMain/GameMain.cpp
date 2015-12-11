#include "GameMain.h"




GameMain::GameMain(){
    //setup();
}
void GameMain::update(){
    player.update();
    map.update();
    //player.setPos(player.getPos() + map.isHitPlayerToBlock(player.ge));

}
void GameMain::draw(){
    env.bgColor(Color::blue);
    glPushMatrix();
    glTranslated(-player.getPos().x(), -player.getPos().y(),0);
    
    map.draw();
    glPopMatrix();
    player.draw();
}

void GameMain::setup(){
    map.setup(1);


    player.setup(map.getPlayerStartPos());
    //player.setPos(map.getPlayerStartPos());


}

SCENE GameMain::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::STAGESELECT;
    }
    return SCENE::GAME;
}

