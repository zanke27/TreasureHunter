#include "pch.h"
#include "Scene_Title.h"
#include "KeyMgr.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::Enter()
{
}

void Scene_Title::Exit()
{
}

void Scene_Title::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}