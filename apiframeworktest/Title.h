#pragma once
#include "Object.h"

class Image;
class Title :

    public Object
{
private:
    Image* m_bImage;
public:
    Title();
    ~Title();
private:

    CLONE(Title);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

