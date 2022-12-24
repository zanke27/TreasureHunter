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
	bImg = ResMgr::GetInst()->ImgLoad(L"Background", L"Image\\BackGround.bmp");
}
Background::~Background()
{

}
void Background::Update()
{

}
void Background::Render(HDC _dc)
{
	Vec2 vPos = GetPos();

	int Width = (int)bImg->GetWidth();
	int Height = (int)bImg->GetHeight();

	StretchBlt(_dc
		,0
		,0
	    , GetSystemMetrics(SM_CXSCREEN), Height * 1.2f
	    , bImg->GetDC()
	    , 0,0
		, Width,Height
		, SRCCOPY
	    );
}