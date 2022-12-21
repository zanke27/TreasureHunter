#include "pch.h"
#include "Background.h"
#include "ResMgr.h"

Background::Background()
{
	// image ¾÷·Îµå
	Image* bImg = ResMgr::GetInst()->ImgLoad(L"Background", L"Image\\Background.bmp");
}
Background::~Background()
{

}
void Background::Update()
{

}
void Background::Render(HDC _dc)
{
	Component_Render(_dc);
}