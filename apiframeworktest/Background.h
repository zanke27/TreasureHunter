#pragma once
#include "Object.h"

class Image;
class Background :

    public Object
{
private:
    Image* m_bImage;
public:
    Background();
    ~Background();
private:

    CLONE(Background);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

