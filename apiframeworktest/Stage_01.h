#pragma once
#include "Scene.h"
class Stage_01 :
    public Scene
{
private:
public:
    Stage_01();
    virtual ~Stage_01();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};
