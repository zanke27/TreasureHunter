#pragma once
#include "Scene.h"
class Stage_04 :
    public Scene
{
private:
public:
    Stage_04();
    virtual ~Stage_04();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

