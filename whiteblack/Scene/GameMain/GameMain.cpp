#include "GameMain.h"




GameMain::GameMain(){
    setup();
}
void GameMain::update(){

}
void GameMain::draw(){

}
void GameMain::setup(){

}

SCENE GameMain::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::STAGESELECT;
    }
    return SCENE::GAME;
}

