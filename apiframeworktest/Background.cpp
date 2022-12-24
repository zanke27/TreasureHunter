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
	    , GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)
	    , bImg->GetDC()
	    , 0,0
		, Width,Height
		, SRCCOPY
	    );
}