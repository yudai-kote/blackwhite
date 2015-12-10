#include "GameMain.h"




GameMain::GameMain(){
    setup();
}
void GameMain::update(){
    player.update();
    map.update();


}
void GameMain::draw(){

    glPushMatrix();
    glTranslated(player.getPos().x(), player.getPos().y(),0);
    std::cout << player.getPos() << std::endl;
    player.draw();
    map.draw();
    glPopMatrix();

}
void GameMain::setup(){
    map.setup(1);
    std::cout << map.getPlayerStartPos() << std::endl;

    player.setup(map.getPlayerStartPos());
    //player.setPos(map.getPlayerStartPos());


}

SCENE GameMain::shift(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        return SCENE::STAGESELECT;
    }
    return SCENE::GAME;
}

