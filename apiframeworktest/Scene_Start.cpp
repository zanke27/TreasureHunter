#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
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

static Object* pObj;

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object 추가

	pObj = new Player;
	
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/20, Core::GetInst()->GetResolution().y/3));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

	// Monster Object 추가
	//Monster* pMonsterObj = new Monster;
	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

	// 몬스터 배치
	//Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	//int iMonster = 16;
	//float fMoveDist = 25.f;
	//float fObjScale = 50.f;
	//float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
	//Monster* pMonsterObj = nullptr;
	//for (int i = 0; i < iMonster; i++)
	//{
	//	pMonsterObj = new Monster;
	//	pMonsterObj->SetName(L"Monster");
	//	pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
	//	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	//	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//	pMonsterObj->SetMoveDistance(fMoveDist);
	//	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	//}

	Platform* pPlatform = ResMgr::GetInst()->PlatformLoad(L"MainMap", L"Platform\\MainMap.json");
	int mapWidth = pPlatform->GetWidth();
	int mapHeight = pPlatform->GetHeight();
	float tileScale = 16.f;
	Json::Value mapArr = pPlatform->GetMapData();
	PlatformObj* pPlatformObj = nullptr;

	for (int i = 1; i <= mapHeight * mapWidth; i++) {
		if (mapArr[i] == 1)
		{
			int h = i / mapWidth + 1;
			int w = i % mapWidth;

			pPlatformObj = new PlatformObj;
			pPlatformObj->SetName(L"PlatformObj");
			pPlatformObj->SetPos(Vec2(tileScale * w, tileScale * h));
			pPlatformObj->SetScale(Vec2(tileScale, tileScale));
			pPlatformObj->SetCenterPos(pPlatformObj->GetPos());
			AddObject(pPlatformObj, GROUP_TYPE::PLATFORM);
		}
	}

	//for (int i = 1; i <= mapHeight; i++) {
	//	for (int j = 1; j <= mapWidth; j++) {
	//		if (mapArr[i] == 58)
	//		{
	//			pPlatformObj = new PlatformObj;
	//			pPlatformObj->SetName(L"PlatformObj");
	//			pPlatformObj->SetPos(Vec2(5 * j, 5 * i));
	//			pPlatformObj->SetScale(Vec2(tileScale, tileScale));
	//			pPlatformObj->SetCenterPos(pPlatformObj->GetPos());
	//			AddObject(pPlatformObj, GROUP_TYPE::PLATFORM);
	//		}
	//	}
	//}

	//for (int i = 0; i < data.size(); i++) {
	//    cout << data[i] << "  ";
	//    // switch (data[i])
	//    // case 58: 이미지 출력 break;
	//    // 출력위치 옮기기
	//    if ((i + 1) % width == 0) {
	//        cout << endl;
	//        // 출력 위치 y값 옮기기 + x값 옮기기
	//    }
	//}
	
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::PLATFORM);

}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{  
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
	if (pObj->GetPos().y > Core::GetInst()->GetResolution().y)
	{
		pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 20, Core::GetInst()->GetResolution().y / 3));
	}
}
