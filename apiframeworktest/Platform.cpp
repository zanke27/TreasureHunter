#include "pch.h"
#include "Platform.h"
#include "json/json.h"
#include <fstream>

Platform::Platform()
    : width(0)
    , height(0)
    , data{}
{

}

Platform::~Platform()
{
}

void Platform::Load(const wstring& _strFilePath)
{
    Json::Value root;
    Json::CharReaderBuilder reader;
    JSONCPP_STRING errorMessage;
    ifstream is(_strFilePath, ifstream::binary);
    auto bret = Json::parseFromStream(reader, is, &root, &errorMessage);

    if (bret == false) {
        cout << "Error to parse JSON file !!!" << endl;
    }

    const Json::Value layer = root["layers"];
    const Json::Value datas = layer[0];
    const Json::Value data = datas["data"];
    width = root["width"].asInt();
    height = root["height"].asInt();
}
