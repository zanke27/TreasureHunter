#include "pch.h"
#include "Scene_Title.h"
#include "Object.h"
#include "Core.h"
#include "Image.h"
#include "SoundMgr.h"
#include "Background.h"
#include "KeyMgr.h"
#include "json/json.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	Object* bObj = new Background;

	bObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	bObj->SetScale(Vec2(200.f, 200.f));
	AddObject(bObj, GROUP_TYPE::DEFAULT);
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