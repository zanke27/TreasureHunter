#include "pch.h"
#include "Background.h"
#include "Image.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

static Image* bImg;

Background::Background()
{
	// image ¾÷·Îµå
	bImg = ResMgr::GetInst()->ImgLoad(L"Background", L"Image\\BG.bmp");

	//CreateAnimator();
	//GetAnimator()->CreateAnimation(L"BackGround", bImg, Vec2(0.f, 0.f), Vec2(200.f, 171.f), Vec2(200.f, 0.f), 1, 0.9f);
	//GetAnimator()->Play(L"BackGround",true);
}
Background::~Background()
{

}
void Background::Update()
{

}
void Background::Render(HDC _dc)
{
	//Component_Render(_dc);

	Vec2 vPos = GetPos();

	int Width = (int)bImg->GetWidth();
	int Height = (int)bImg->GetHeight();

	StretchBlt(_dc
		,0
		,0
	    , Width * 5, Height * 5
	    , bImg->GetDC()
	    , 0,50
		, Width,Height
		, SRCCOPY
	    );
}