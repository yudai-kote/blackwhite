#pragma once

#include "../Title/Title.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"
#include "../../Top/Top.h"

class SceneManager
{
public:
    SceneManager();
    void update();
    void draw();
    void Shift();

private:
    Title title;
    StageSelect stageselect;
    GameMain GameMain;

    SCENE scene_number;
};
