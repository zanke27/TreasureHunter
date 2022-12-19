#pragma once
class Image;
class Platform;
class Res;
class ResMgr
{
private:
//	map<wstring, Image*> m_mapImg;
	map<wstring, Res*> m_mapImg;
	map<wstring, Res*> m_mapPlatform;

public:
	SINGLE(ResMgr);
private:
	ResMgr();
	~ResMgr();
public:
	Image* ImgLoad(const wstring& _strKey, const wstring& _strRelativePath);
	Image* ImgFind(const wstring& _strKey);

	Platform* PlatformLoad(const wstring& _strKey, const wstring& _strRelativePath);
	Platform* PlatformFind(const wstring& _strKey);
};

