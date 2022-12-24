#pragma once
#include "Scene.h"
class MainStage :
    public Scene
{
private:
public:
    MainStage();
    virtual ~MainStage();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    void Generate(int num);
    void Remove();
};

