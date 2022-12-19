#include "pch.h"
#include "PlatformObj.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Image.h"
#include "ResMgr.h"

PlatformObj::PlatformObj()
	: m_vCenterPos(Vec2(0.f, 0.f))
{
	// 이거 현재는 이미지 없으니까 만들어야함
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"Brick", L"Image\\Brick.bmp"); // 사막 유적같이 생긴 벽돌 하나 그려서 땜빵하자
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

PlatformObj::~PlatformObj()
{

}

void PlatformObj::Update()
{

}

void PlatformObj::EnterCollision(Collider* _pOther)
{

}