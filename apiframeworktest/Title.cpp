#include "pch.h"
#include "Title.h"
#include "Image.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

static Image* tImg;

Title::Title()
{

	tImg = ResMgr::GetInst()->ImgLoad(L"Title", L"Image\\Title.bmp");

}
Title::~Title()
{

}
void Title::Update()
{

}
void Title::Render(HDC _dc)
{

	Vec2 vPos = GetPos();

	int Width = (int)tImg->GetWidth();
	int Height = (int)tImg->GetHeight();

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, 75
		,Width, Height
	    , tImg->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,255,255));
}