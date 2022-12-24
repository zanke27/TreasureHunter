#pragma once
#include "Scene.h"
class Stage_06 :
    public Scene
{
private:
public:
    Stage_06();
    virtual ~Stage_06();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};
