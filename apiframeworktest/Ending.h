#pragma once
#include "Scene.h"
class Ending :
    public Scene
{
private:
public:
    Ending();
    virtual ~Ending();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

