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
        stageselect.update();
        break;
    case SCENE::GAME:
        GameMain.update();
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
        stageselect.draw();
        break;
    case SCENE::GAME:
        GameMain.draw();
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
        if (stageselect.shift() != SCENE::STAGESELECT)
        {
            std::cout << stageselect.Get_Stage_Number() << std::endl;
            GameMain.setup(/*stageselect.Get_Stage_Number()*/1);
        }
        scene_number = stageselect.shift();

        break;
    case SCENE::GAME:
        scene_number = GameMain.shift();

        break;
    }

}