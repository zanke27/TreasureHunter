#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
Player::Player()
{
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\Playerb.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Idle", pImg, Vec2(0.f, 0.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 2, 0.5f);
	GetAnimator()->CreateAnimation(L"Walk", pImg, Vec2(0.f, 16.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 3, 0.25f);
	GetAnimator()->CreateAnimation(L"Jump", pImg, Vec2(0.f, 32.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 3, 0.2f);
	GetAnimator()->CreateAnimation(L"Land", pImg, Vec2(0.f, 48.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 3, 0.2f);
	GetAnimator()->CreateAnimation(L"Fall", pImg, Vec2(0.f, 64.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 1, 100.f);
	GetAnimator()->Play(L"Idle", true);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	static bool isJump = false;
	static bool isMove = false;
	static bool isFall = false;
	static float m_dt = 0.0f;

	if (KEY_HOLD(KEY::LEFT) || KEY_HOLD(KEY::A))
	{
		GetAnimator()->Play(L"Walk", true);
		isMove = true;
		vPos.x -= 300.f * fDT;
	}
	else if (KEY_HOLD(KEY::RIGHT) || KEY_HOLD(KEY::D))
	{
		GetAnimator()->Play(L"Walk", true);
		isMove = true;
		vPos.x += 300.f * fDT;
	}
	else if(isMove && !isFall && !isJump)
	{
		isMove = false;
		GetAnimator()->Play(L"Idle", true);
	}

	if (KEY_TAP(KEY::SPACE) || KEY_TAP(KEY::W))
	{
		if (!isJump && !isFall)
		{
			isJump = true;
			GetAnimator()->Play(L"Jump", true);
		}
	}
	if (isJump)
	{
		m_dt += fDT;
		vPos.y -= 80.f * fDT + (0.6f-m_dt) * 0.2f;
		if (m_dt >= 0.6f)
		{
			m_dt = 0.0f;
			isJump = false;
			isFall = true;
			GetAnimator()->Play(L"Fall", true);
		}
	}
	if (isFall)
	{
		m_dt += fDT;
		vPos.y +=  m_dt * 0.4f;
	}
	SetPos(vPos);
	GetAnimator()->Update();
}

void Player::CreateBullet()
{
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;

	// 
	Bullet* pBullet = new Bullet;
	pBullet->SetName(L"Bullet_Player");
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(Vec2(25.f, 25.f));
	pBullet->SetDir(Vec2(0.f, -1.f));
	CreateObject(pBullet, GROUP_TYPE::BULLET_PLAYER);
	//Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	//pCurScene->AddObject(pBullet,GROUP_TYPE::BULLET);
}
void Player::Render(HDC _dc)
{
	Component_Render(_dc);
	/*int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();*/
	//BitBlt(_dc
	//	,(int)(vPos.x - (float)(Width / 2))
	//	,(int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//    , m_pImage->GetDC()
	//    , 0,0, SRCCOPY);

	//마젠타 색상 뺄때 transparent: 투명한
	//TransparentBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//	,Width, Height
	//    , m_pImage->GetDC()
	//    ,0,0, Width, Height
	//    , RGB(255,0,255));

}
