#pragma once
#include "Scene.h"
class Scene_Title :
    public Scene
{
private:
public:
    Scene_Title();
    virtual ~Scene_Title();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

