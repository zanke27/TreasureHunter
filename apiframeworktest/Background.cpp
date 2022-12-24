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
	int Width = (int)bImg->GetWidth();
	int Height = (int)bImg->GetHeight();

	BitBlt(_dc
		,(int)((float)(Width / 2))
		,(int)((float)(Height / 2))
	    , Width, Height
	    , bImg->GetDC()
	    , 0,0, SRCCOPY);
}