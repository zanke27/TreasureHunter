#include "pch.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "Image.h"
#include "Platform.h"
ResMgr::ResMgr()
{
}

ResMgr::~ResMgr()
{
	/*map<wstring, Image*>::iterator iter;
	for (iter = m_mapImg.begin(); iter != m_mapImg.end(); ++iter)
	{
		delete iter->second;
	}*/
	Safe_Delete_Map(m_mapImg);
}

Image* ResMgr::ImgLoad(const wstring& _strKey, const wstring& _strRelativePath)
{
	Image* pImg = ImgFind(_strKey);
	if (nullptr != pImg)
	{
		return pImg;
	}
	wstring strFilePath = PathMgr::GetInst()->GetRsrcPath();
	strFilePath += _strRelativePath;
	pImg = new Image;
	pImg->Load(strFilePath);
	pImg->SetKey(_strKey);
	pImg->SetRelativePath(_strRelativePath);
	m_mapImg.insert(make_pair(_strKey , pImg));
//	m_mapImg.insert({ _strKey , pImg });
	return pImg;
}

Image* ResMgr::ImgFind(const wstring& _strKey)
{
	map<wstring, Res*>::iterator iter = m_mapImg.find(_strKey);
	if (iter == m_mapImg.end())
	{
		return nullptr;
	}
	return (Image*)iter->second;
}

Platform* ResMgr::PlatformLoad(const wstring& _strKey, const wstring& _strRelativePath)
{
	Platform* pPlat = PlatformFind(_strKey);
	if (nullptr != pPlat)
	{
		return pPlat;
	}
	wstring strFilePath = PathMgr::GetInst()->GetRsrcPath();
	strFilePath += _strRelativePath;
	pPlat = new Platform;
	pPlat->Load(strFilePath);
	pPlat->SetKey(_strKey);
	pPlat->SetRelativePath(_strRelativePath);
	m_mapPlatform.insert(make_pair(_strKey, pPlat));
	//	m_mapImg.insert({ _strKey , pImg });
	return pPlat;
}

Platform* ResMgr::PlatformFind(const wstring& _strKey)
{
	map<wstring, Res*>::iterator iter = m_mapPlatform.find(_strKey);
	if (iter == m_mapPlatform.end())
	{
		return nullptr;
	}
	return (Platform*)iter->second;
}


