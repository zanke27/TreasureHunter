#pragma once
#include "Scene.h"
class Stage_05 :
    public Scene
{
private:
public:
    Stage_05();
    virtual ~Stage_05();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};
