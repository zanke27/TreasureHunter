#pragma once
#include "Scene.h"
class Stage_03 :
    public Scene
{
private:
public:
    Stage_03();
    virtual ~Stage_03();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

