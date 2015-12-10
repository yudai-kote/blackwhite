#include "GameMain.h"




GameMain::GameMain(){
    setup();
}
void GameMain::update(){
    
}
void GameMain::draw(){
    glPushMatrix();
    glTranslated(player.getPos().x(), player.getPos.y(),0);


    player.draw();
    map.draw();
    glPopMatrix();

}
void GameMain::setup(){
    

}

SCENE GameMain::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::STAGESELECT;
    }
    return SCENE::GAME;
}

