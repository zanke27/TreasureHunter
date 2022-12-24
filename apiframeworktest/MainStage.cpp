#include "pch.h"
#include "KeyMgr.h"
#include "MainStage.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Platform.h"
#include "ResMgr.h"
#include "PlatformObj.h"
#include "json/json.h"
#include <string>

static Object* pObj;
static PlatformObj* sPlatObj;
static int num = 1;

MainStage::MainStage()
{
}

MainStage::~MainStage()
{
}
void MainStage::Enter()
{
	//SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	//SoundMgr::GetInst()->Play(L"BGM");

	Generate(num);
}

void MainStage::Exit()
{
	DeleteAll();
	//SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	CollisionMgr::GetInst()->CheckReset();
}

void MainStage::Update()
{
	Scene::Update();
	if (pObj->GetPos().y > Core::GetInst()->GetResolution().y)
	{
		pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 20 + 200, Core::GetInst()->GetResolution().y / 3 + 250));
	}
	if (pObj->GetPos().x + 16 >= sPlatObj->GetPos().x &&
		pObj->GetPos().x - 16 <= sPlatObj->GetPos().x &&
		pObj->GetPos().y + 16 >= sPlatObj->GetPos().y &&
		pObj->GetPos().y - 16 <= sPlatObj->GetPos().y)
	{
		Remove();
		
		num += 1;
		if (num == 8)
			ChangeScene(SCENE_TYPE::ENDING);
		else 
			Generate(num);
	}
}

void MainStage::Generate(int num)
{
	Object* bObj = new Background;

	bObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	bObj->SetScale(Vec2(200.f, 200.f));
	AddObject(bObj, GROUP_TYPE::DEFAULT);

	pObj = new Player;

	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 20 + 209, Core::GetInst()->GetResolution().y / 3 + 250));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	wstring stage = L"Stage";
	stage += to_wstring(num);

	wstring path = L"Platform\\Stage";
	path += to_wstring(num);
	path += L".json";

	Platform* pPlatform = ResMgr::GetInst()->PlatformLoad(stage, path);
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
			pPlatformObj->SetImageToNum(mapArr[i].asInt());
			pPlatformObj->SetPos(Vec2(tileScale * w, tileScale * h));
			pPlatformObj->SetScale(Vec2(tileScale, tileScale));
			pPlatformObj->SetCenterPos(pPlatformObj->GetPos());
			if (mapArr[i] == 1)
				AddObject(pPlatformObj, GROUP_TYPE::PLATFORM);
			else if (mapArr[i] == 2)
			{
				sPlatObj = pPlatformObj;
				AddObject(pPlatformObj, GROUP_TYPE::PORTAL);
			}
			else if (mapArr[i] == 3)
				AddObject(pPlatformObj, GROUP_TYPE::TEXTPLATFORM);
		}
	}

	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::PLATFORM);
}

void MainStage::Remove()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}
