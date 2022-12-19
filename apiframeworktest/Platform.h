#pragma once
#include "Res.h";
#include "json/json.h"
class Platform:
	public Res
{
private:
	int width;
	int height;
	Json::Value data;
private:
	Platform();
	virtual ~Platform();
	friend class ResMgr;
public:
	void Load(const wstring& _strFilePath);
	Json::Value GetMapData() { return data; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }
};

