#include "SceneManager.h"

SceneManager::SceneManager(){
    scene_number = SCENE::TITLE;
}

void SceneManager::update(){
    switch (scene_number)
    {
    default:
        break;
    case SCENE::TITLE:
        title.update();
        break;
    case SCENE::STAGESELECT:
        break;
    case SCENE::GAME:
        break;
    }
}
void SceneManager::draw(){
    switch (scene_number)
    {
    default:
        break;
    case SCENE::TITLE:
        title.draw();
        break;
    case SCENE::STAGESELECT:
        break;
    case SCENE::GAME:
        break;
    }

}
void SceneManager::Shift(){
    
    switch (scene_number)
    {
    default:
        break;
    case SCENE::TITLE:
        scene_number = title.shift();
        break;
    case SCENE::STAGESELECT:
        scene_number = stageselect.shift();

        break;
    case SCENE::GAME:
        scene_number = GameMain.shift();

        break;
    }

}