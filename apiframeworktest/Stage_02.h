#pragma once
#include "Scene.h"
class Stage_02 :
    public Scene
{
private:
public:
    Stage_02();
    virtual ~Stage_02();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

