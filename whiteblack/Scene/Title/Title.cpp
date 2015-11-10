#include "Title.h"


Title::Title(){
    setup();
}
void Title::update(){
    //タイトルのアニメーションとかやるときに処理が増えるかもしれない

}
void Title::draw(){
    //タイトルの描画
}
void Title::setup(){

}

SCENE Title::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::STAGESELECT;
    }
    return SCENE::TITLE;
}

