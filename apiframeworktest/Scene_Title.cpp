#include "pch.h"
#include "Scene_Title.h"
#include "Object.h"
#include "Core.h"
#include "Image.h"
#include "ResMgr.h"
#include "SoundMgr.h"
#include "Background.h"
#include "Title.h"
#include "KeyMgr.h"
#include "PlatformObj.h"
#include "Platform.h"
#include "json/json.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::Enter()
{
	SetWindowText(Core::GetInst()->GetWndHandle(), L"TreasureHunter");

	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\MainBgm.mp3");
	SoundMgr::GetInst()->Play(L"BGM");


	Object* bObj = new Background;

	bObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	bObj->SetScale(Vec2(200.f, 200.f));
	AddObject(bObj, GROUP_TYPE::DEFAULT);
	
	Object* tObj = new Title;
	tObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	tObj->SetScale(Vec2(200.f, 200.f));
	AddObject(tObj, GROUP_TYPE::DEFAULT);

	Platform* pPlatform = ResMgr::GetInst()->PlatformLoad(L"Title", L"Platform//Title.json");
	int mapWidth = pPlatform->GetWidth();
	int mapHeight = pPlatform->GetHeight();
	float tileScale = 16.f;
	Json::Value mapArr = pPlatform->GetMapData();
	PlatformObj* pPlatformObj = nullptr;

	for (int i = 1; i <= mapHeight * mapWidth; i++) {
		if (mapArr[i] != 0)
		{
			int h = i / mapWidth + 1;
			int w = i % mapWidth;

			pPlatformObj = new PlatformObj;
			pPlatformObj->SetName(L"PlatformObj");
			pPlatformObj->SetImageToNum(3);
			pPlatformObj->SetPos(Vec2(tileScale * w + 100, tileScale * h));
			pPlatformObj->SetScale(Vec2(tileScale, tileScale));
			pPlatformObj->SetCenterPos(pPlatformObj->GetPos());
			AddObject(pPlatformObj, GROUP_TYPE::TEXTPLATFORM);
		}
	}
}

void Scene_Title::Exit()
{
}

void Scene_Title::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::MAINSTAGE);
	}
}