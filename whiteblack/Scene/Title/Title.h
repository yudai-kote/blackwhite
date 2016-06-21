
#pragma once

#include "../../Top/Top.h"
#include <cmath>
#include <functional>

class Title
{
    //****************************************//
    //  public:
    //****************************************//
public:
    Title();
public:
    void update();
    void draw();
    void setup();
    SCENE shift();

    //****************************************//
    //  private:
    //****************************************//
private:    //  �R���X�g���N�^�ɂ��������܂���B
    YuFont font_;
private:    //  setup()�ŉ�����Ă΂�܂��B
    Texture tex_;
	Texture title_bg;
    Color col_;
    bool is_Fade_;
    bool is_Pushed_;
    float alpha_;
    Vec2f title_Pos_;
    Vec2f start_Button_Pos_;
    int frame_;
    Color font_Col_;
private:    //  setup()�ɂ��R���X�g���N�^�ɂ�������܂���B
    YuCounter counter_;

private:
    void fade_In_();
    SCENE fade_Out_();

};
