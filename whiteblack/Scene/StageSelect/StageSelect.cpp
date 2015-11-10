#include "StageSelect.h"




StageSelect::StageSelect(){
    setup();
}
void StageSelect::update(){

}
void StageSelect::draw(){

}
void StageSelect::setup(){

}

SCENE StageSelect::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::GAME;
    }
    return SCENE::STAGESELECT;
}
