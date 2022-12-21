#pragma once
#include "Object.h"

class Image;
class Player :

    public Object
{
private:
    Image* m_pImage;
public:
    Player();
    ~Player();
private:
    virtual void	EnterCollision(Collider* _pOther);
    virtual void    ExitCollision(Collider* _pOther);
    virtual void    StayCollision(Collider* _pOther);

    CLONE(Player);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

